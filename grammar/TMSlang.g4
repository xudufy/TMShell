grammar TMSlang;

@lexer::members {
  int textArgModeUntilNewLine = 0;
  int textArgModeUntilSpace = 0;
  int skipNewline = 0;
}

program : (execute_line|NEWLINE) +;

execute_line : (mgmt_command | varDef | triggerDef) NEWLINE;

mgmt_command : COLON command_name=cmd_arg args+=cmd_arg*;
cmd_arg : StringLiteral #QuotedArg
        | TEXTARG #PlainArg
        ;

varDef : VAR ID '=' expr #SessionVarDef
      | VAR GLOBAL ID '=' expr # GlobalVarDef
      ;
triggerDef : signal=expr (POUND trigger_name=cmd_arg)? RIGHTARROW action=expr;
expr: expr ('*' | '/') expr # MulExpr
    |expr ('+'|'-') expr # AddExpr
    | expr ('<' | '>' |'<=' | '>=') expr # RelExpr
    | expr ('==' | '!=') expr # EqlExpr
    | 'if' '('expr')' expr ('else' expr)? # IfExpr
    | 'var' ID '=' expr # LocalVarDefExpr
    | ID '=' expr # AssignExpr
    | expr'<<<' expr ('>>>' expr)? # PeriodicExpr
    | expr '.' ID # FieldExpr
    | ID '(' (expr (',' expr) *)? ')' # CallExpr
    | LEFTBRACE  (expr ';')* RIGHTBRACE # GroupExpr
    | ID # IDExpr
    | '>>' expr #LaterExpr
    | '<.>' #CurrentExpr
    | TimePointLiteral # TimePointLExpr
    | DurationLiteral # DurationLExpr
    | StringLiteral # StringLExpr
    | IntegerLiteral #IntLExpr
    ;

COLON: ':' {textArgModeUntilNewLine=1;};
TEXTARG: ~[ \n\r\t"]+ {textArgModeUntilNewLine==1 || textArgModeUntilSpace==1}?;
POUND: '#' {textArgModeUntilSpace=1;};
LEFTBRACE: '{' {skipNewline=1;};
RIGHTBRACE: '}' {skipNewline=0;};
RIGHTARROW: '=>' {textArgModeUntilSpace=0;};
VAR: 'var';
SESSION: 'session';
GLOBAL: 'global';
ID: [a-zA-Z_][0-9a-zA-Z_]*;

TimePointLiteral: ((Integer ':')? (Integer ':' Integer 'T' ))? Integer ':' Integer (':' Integer)?
                | Integer ':' Integer (':' Integer)? 'D' DAYLITERAL  
                ;
DurationLiteral: ([0-9]+[wdhms]) +;

fragment DAYLITERAL: ('Sun'|'sun'|'Mon'|'mon'|'Tue'|'tue'|'Wed'|'wed'|'Thu'|'thu'|'Fri'|'fri'|'Sat'|'sat'|'Sun'|'sun');
DurationFragment: [0-9]+[wdhms];
IntegerLiteral: Integer;
fragment Integer: [0-9]+;
StringLiteral: '"' (~[\\"\n\r] | EscapedSL)* '"';
fragment EscapedSL: '\\\\'
                  | '\\n'
                  | '\\"'
                  | '\\t'
                  ;

WS : [ \t]+ {textArgModeUntilSpace = 0;}-> skip;
ESCAPEDNEWLINE : ('\\\n'|'\\\r\n') -> skip;
NEWLINE_SKIP: ('\n' | '\r\n')+ {skipNewline==1}? -> skip;
NEWLINE: '\n' | '\r\n'{textArgModeUntilNewLine=0;textArgModeUntilSpace = 0;};
ERRORCHAR:.;