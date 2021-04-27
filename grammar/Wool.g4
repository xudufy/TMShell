/* 
 * Grammar for the Wool-W compiler, CS4533 and CS544, Worcester Polytechnic Institute
 * Author: Gary F. Pollice
 */
grammar Wool;

// Parser rules
program                 :   classes+=classDef+ EOF ;

classDef                :   'class' className=TYPE (INHERITS inherits=TYPE)? classBody ;

classBody               :   '{' ((variables+=variableDecl | methods+=method))* '}' ;
    
method                  :   ID '(' (formals+=formal (',' formals+=formal)*)? ')' ':' type=typeName '{'  vars+=variableDecl* expr '}' ;

variableDecl            :   ID ':' type=typeName ('<-' initializer=expr)? ';' ;
                              
formal                  :   name=ID ':' type=typeName ; 

typeName                :   classType=TYPE | intType=INT | boolType=BOOL ;

expr                    :   object=expr '.' methodName=ID '(' (args+=expr (',' args+=expr)*)? ')'     # FullMethodCall
                            | methodName=ID '(' (args+=expr (',' args+=expr)*)? ')'         # LocalMethodCall
                            | IF condition=expr THEN thenExp=expr ELSE elseExp=expr FI      # IfExpr
                            | WHILE condition=expr LOOP action=expr POOL                    # WhileExpr
                            | '{' (exprs+=expr ';')+ '}'                                    # ExprList
                            | SELECT selectAlt+ END                                         # Select
                            | NEW type=TYPE                                                 # NewExpr
                            | <assoc=right> MINUS expr                                      # UMinusExpr
                            | ISNULL expr                                                   # IsNullExpr
                            | left=expr (STAR | SLASH) right=expr                           # MultExpr
                            | left=expr (PLUS | MINUS) right=expr                           # AddExpr
                            | left=expr (LESS | LEQ | GTR | GEQ) right=expr                 # RelExpr
                            | <assoc=right> left=expr (EQUAL | NEQ) right=expr              # EqExpr
                            | <assoc=right> TILDE expr                                      # NotExpr
                            | '(' expr ')'                                                  # ParenExpr
                            | ID '<-' expr                                                  # AssignExpr
                            | ID                                                            # IDExpr
                            | INTEGER                                                       # IntExpr
                            | STRING                                                        # StrExpr
                            | TRUE                                                          # TrueExpr
                            | FALSE                                                         # FalseExpr
                            | NULLL                                                          # NullExpr
                            ;
                            
selectAlt                   :   expr ':' expr ';' ;

// Lexer rules:
// We assume that reserved words are recognized by the scanner rather than just
// recognizing an identifier and letting the parser determine the token class.

// Key words
BOOL                    :   'boolean' ;
CLASS                   :   'class' ;
ELSE                    :   'else' ;
END                     :   'end' ;
FALSE                   :   'false' ;
FI                      :   'fi' ;
IF                      :   'if' ;
IN                      :   'in' ;
INT                     :   'int' ;
INHERITS                :   'inherits' ;
ISNULL                  :   'isnull' ;
LOOP                    :   'loop' ;
NEW                     :   'new' ;
NULLL                    :   'null' ;
POOL                    :   'pool' ;
SELECT                  :   'select' ;
THEN                    :   'then' ;
TRUE                    :   'true' ;
WHILE                   :   'while' ;

// Punctuation, operators, and symbols. Again, we choose to recognize multi-character
// operators in the lexer rather than in the parser.
COLON                   :   ':' ;
COMMA                   :   ',' ;
DOT                     :   '.' ;
EQUAL                   :   '=' ;
GEQ                     :   '>=' ;
GTR                     :   '>' ;
LBRACE                  :   '{' ;
LEQ                     :   '<=' ;
LESSDASH                :   '<-' ;
LESS                    :   '<' ;
LPAR                    :   '(' ;
MINUS                   :   '-' ;
NEQ                     :   '~=' ;
PLUS                    :   '+' ;
RBRACE                  :   '}' ;
RPAR                    :   ')' ;
SEMICOLON               :   ';' ;
SLASH                   :   '/' ;
STAR                    :   '*' ;
TILDE                   :   '~' ;

// Integers, Identifiers
WS                      :   [ \t\r\n\f]+ -> skip ;
INTEGER                 :   DIGIT+ ;
TYPE                    :   UPPER (LETTER|UNDERSCORE|DIGIT)* ;
ID                      :   LOWER (LETTER|UNDERSCORE|DIGIT)* ;
STRING                  :   '"' ('\\'. | ~[\n])*? '"' ;

// Comments
COMMENT                  :  (INLINE_COMMENT|STD_COMMENT) -> skip ;
fragment INLINE_COMMENT  :  '#' .*? ('\n'|EOF);
fragment STD_COMMENT     :  '(*' (STD_COMMENT | .)*? '*)' ;
fragment UNDERSCORE      :   '_' ;

// Fragments
fragment DIGIT          :   [0-9] ;
fragment UPPER          :   [A-Z] ;
fragment LOWER          :   [a-z] ;
fragment LETTER         :   UPPER | LOWER ;