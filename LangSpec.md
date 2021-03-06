# TimeMachine Shell

## Background
Sometimes, I feel it is very laboring to set up an item in my to-do list on the computer, especially when I need to set up the time point just several minutes later. In order to set the correct time in that situation, one needs to know the current time, do a calculation in mind, and input the entire hours/minutes for the target time point. I want to change that experience to just type in:
```
 >>15m # turn off the oven => alarm 
```
Then, I found it is actually an event-driven pattern, with a signal defined by the time point. With this definition, the new DSL can do more than a to-do list.

I expect it to be:
1. an trigger system
1. a to-do list
1. a task scheduler that do something routinely like checking for updates.
1. a shell

simultaneously.

## Composition of the final product
1. A background service that gives out the timer signals, performs the actions and execute the DSL input from the client application (by socket, maybe).
2. A CLI client application that receive the DSL input in both interactive form and batch-file form. (works like python.exe)

## DSL Description
The name of the new DSL is "TimeMachine Shell". It will contain four aspects of functions:
1. Built-in support for time operations.
1. Signal-to-action triggers.
1. Basic variable support, struct support, and arithmatic operations. 
1. a set of runtime actions, e.g. alarm, open a file, run a program, shutdown.
1. a set of runtime management commands, like manually triggering a signal or changing the internal time of the service (that is why I call it time machine).

### Time types
We will have three built-in types to decribe the concepts about time:
1. TimePoint: a time point in UTC.
1. Duration: the length of a time span.
1. Periodic: `struct{start, end: TimePoint; period: Duration}`, represents an set of time points starting at `start`, ending at `end` and sampled everytime a `period` passed.

### Time Literal
TimePoint and duration has a literal form that can directly used in the DSL, without any quote:
1. TimePoint Form1:`[[2001:]2:3T]4:5[:6]` for 02/03/2001 04:05:06 in local time, and the local time zone is obtained from the OS.
    
    If the part of second (`:6`) is missing, a `0` is filled in automatically.

    If any other optional part is missing, the time point will be the next time that the time matches the literal, and the current time is obtained from the OS.

    For example, suppose the OS time is now `2021:12:31T23:59:59`, a literal of `12:00` will represent a time point at `2022:01:01T12:00:00`

    The starting `0` will be omitted for the fields of Month, Date, Hour, minute and second, so `2:28T1:1:1` is legal.

    All literal should be in 24-hour format.
    
1. TimePoint Form2: `4:5[:6][D(Sun|Mon|...|Sat)]`. The time point will be the next time that the time matches the literal. For example, if current time is `12:30:00DMon`, `12:30:01DMon` will represent the time one second later, and `12:30DMon` will represent the time on next Monday.

1. Duration Form: `[1w][1d][1h][1m][1s]` and should not be empty. Each field are added up to get the length of the Duration, e.g. `1w21d` is 28 days.

### Time operators
Normal Operators:
All operators supported in std::chrono are supported in TMShell, except the '/' (division). Following is some examples.
```C++
//TimePoint forward/backward
TimePoint operator+(TimePoint, Duration)
TimePoint operator-(TimePoint, Duration)

//Duration add/minus
Duration operator+(Duration, Duration)
Duration operator-(Duration, Duration)

//Comparison
bool operator<=>(TimePoint, TimePoint)
bool operator<=>(Duration, Duration)
```

Special Operators:
1. Construct a Periodic{start = a, end = c (forever if empty), period = b}
    ```c++
    '[' a:TimePoint @ b:Duration [@ c:TimePoint]  ']'
    ```
1. Get a timepoint after a Duration d of the current time.
    ```
    >>d
    ```
1. Get current time point
    ```
    <.>
    ```

### Trigger Definition
a trigger is defined in the form 
```
triggerDef = signal ('#' trigger_name)? ('=>'|']]') action
```

a signal can be one of 
- TimePoint
- Periodic
- String

where String signal are triggered manually with a built-in action/command.

### Variable scope
All signals and triggers are defined `globally`.
The variables can be defined `globally`, `session-level`, or `locally`.

Here, `globally` means a durable cache that can be accessed for all code run in the background service.
`session-level` means the variable is effective in a client session.
`locally` is a variable defined and used within a single `action`.

### Special Rules for Variable scope
Because the action is saved for further use even the client has closed. So a `session-level` variable cannot be used in that. We have an access table:

|             | global | session-level | local | 
|-------------|--------|---------------|-------|
| signal      | OK     | OK            | -     | 
| action      | OK     | -             | OK    | 
| mgmt/varDef | OK     | OK            | -     | 

### Built-in command
These are `mgmt_command`.
```c++
//Time maneuver
jump <TimePoint>
speed <Integer> // 1000 for 1x, 1500 for 1.5x, etc.
reset time

//info retrival
ls event
ls global //global variable

//removal
remove signal <string signal>
remove event <event index>

//execute a file of TimeMachine Code
run <file path>

//Trigger a string signal manually
signal <String signal>

```

### Built-in method
These methods are provided for the `action`.
```java
signal(<string signal>) //trigger a string signal
shell_open(<filePath>) //double fork and run a program
alert(<any thing>) // pop up a msgbox for output some info.
log(<any thing>) // write something to log. Default behaviour: write to console.
run(<filePath>) // run another TimeMachine script.
disconnect() //remove this action from this signal.
return() // exit current action.
```

### How to make a custom function in TimeMachine
Set a special string signal and write the actions as the function body.
When you need to call a function, trigger that signal.
The data exchange can be done by global variable.

## Implementation 
All the features except the custom struct are implemented correctly.
Full multi-thread support.
Full UTF-8 support. (internally converted to UTF16 when perform system calls, so any character beyond UTF16 may be problematic. And consoles cannot show/input UTF-8 properly. So the input and output must be with files if using UTF-8, and a UTF-8 string inputted by file work perfectly with the system api.)

## Formal Specification
BNF:
```py
program : (execute_line|NEWLINE) +;

execute_line : (mgmt_command | varDef | triggerDef) NEWLINE;

mgmt_command : COLON command_name=cmd_arg args+=cmd_arg*;
cmd_arg : StringLiteral             #QuotedArg
        | TEXTARG                   #PlainArg
        ;

varDef : LET ID '=' expr        #SessionVarDef
      | LET GLOBAL ID '=' expr  # GlobalVarDef
      ;

triggerDef : signal=expr (POUND trigger_name=cmd_arg)? RIGHTARROW action=expr;

expr: '-' expr                                              #NegExpr
    | '!' expr                                              #NotExpr
    | expr op=('*' | '/') expr                              # MulExpr
    | expr op=('+'|'-') expr                                # AddExpr
    | expr op=('<' | '>' |'<=' | '>=') expr                 # RelExpr
    | expr op=('==' | '!=') expr                            # EqlExpr
    | expr op=('||' | '&&') expr                            # LogicExpr
    | LET ID '=' expr                                       # LocalVarDefExpr
    | id+=ID ('.' id+=ID ('.' id+=ID)?)? '=' expr           # AssignExpr
    | '[' expr'@' expr ('@' end=expr)? ']'                  # PeriodicExpr
    | expr '.' ID                                           # FieldExpr
    | ID '(' (args+=expr (',' args+=expr) *)? ')'           # CallExpr
    | LEFTBRACE  (inner+=expr (';' inner+=expr)*)? ';'? RIGHTBRACE # GroupExpr
    | ID                                                    # IDExpr
    | '>>' expr                                             #LaterExpr
    | '<.>'                                                 #CurrentExpr
    | '(' expr ')'                                          #ParanExpr
    | IF '('cond=expr')' then=expr (ELSE epart=expr)?       # IfExpr
    | TimePointLiteral                                      # TimePointLExpr
    | DurationLiteral                                       # DurationLExpr
    | StringLiteral                                         # StringLExpr
    | IntegerLiteral                                        #IntLExpr
    | BoolLiteral                                           #BoolExpr
    ;

```

## Log
1. Any type can be implicitly cast to String in function calls, or in an ???+??? operation with another string. All other type casting are forbidden.
1. Duration/int (division) is forbidden.
1. equal is defined by `to_string(lhs) == to_string(rhs) && type(lhs) == type(rhs)`. It is sound and complete as long as no custom struct support.
1. short cut for `||` and `&&` is implemented.
1. [*Fixed*]bug when COLON command lines used in file modes.
