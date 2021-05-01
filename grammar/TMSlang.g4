grammar TMSlang;

@lexer::members {
  int textArgModeOneLine = 0;
  int textArgModeOneWord = 0;
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
triggerDef : signal=expr (POUND trigger_name=cmd_arg)? RIGHTARROW? action+=expr (';' action+=expr)* ;
expr: '-' expr #NegExpr
    | '!' expr #NotExpr
    | expr ('*' | '/') expr # MulExpr
    | expr ('+'|'-') expr # AddExpr
    | expr ('<' | '>' |'<=' | '>=') expr # RelExpr
    | expr ('==' | '!=') expr # EqlExpr
    | expr ('||' | '&&') expr # LogicExpr
    | IF '('expr')' expr (ELSE expr)? # IfExpr
    | VAR ID '=' expr # LocalVarDefExpr
    | ID '=' expr # AssignExpr
    | expr'@' expr ('@' expr)? # PeriodicExpr
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
    | BoolLiteral #BoolExpr
    ;

COLON: ':' {textArgModeOneLine=1;};
TEXTARG: ~[ \n\r\t"]+ {textArgModeOneLine==1 || textArgModeOneWord==1}? {textArgModeOneWord = 0;};
IF:'if';
ELSE:'else'; 
POUND: '#' {textArgModeOneWord=1;};
LEFTBRACE: '{' {skipNewline=1;};
RIGHTBRACE: '}' {skipNewline=0;};
RIGHTARROW: '=>' {textArgModeOneWord=0;};
VAR: 'var';
SESSION: 'session';
GLOBAL: 'global';
BoolLiteral: 'true' | 'false';

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

WS : [ \t]+ -> skip;
ESCAPEDNEWLINE : ('\\\n'|'\\\r\n') -> skip;
NEWLINE_SKIP: ('\n' | '\r\n')+ {skipNewline==1}? -> skip;
NEWLINE: '\n' | '\r\n'{textArgModeOneLine=0;textArgModeOneWord = 0;};
ERRORCHAR:.;