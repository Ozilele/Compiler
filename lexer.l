%option noyywrap

%{
#include <iostream>
#include "parser.hpp"

extern int yylex();
%}

WS [ \t]

%x COMM

%%

\#            { BEGIN(COMM); }
<COMM>.       ;
<COMM>\n      { BEGIN(INITIAL); }
{WS}          ;
\n            ;

\;            { return T_SEMICOLON; }
\,            { return T_COMMA; }

\+            { return T_ADD; }
\-            { return T_SUB; }
\/            { return T_DIV; }
\%            { return T_MOD; }
\*            { return T_MUL; }

\:\=          { return T_ASSIGN; }

\=            { return T_EQ; }
\!\=          { return T_NEQ; }  
\<            { return T_LT; }
\>            { return T_GT; }
\<\=          { return T_LTEQ; }
\>\=          { return T_GTEQ; }

PROGRAM       { return T_PROGRAM; }
IS            { return T_IS; }
IN            { return T_IN; }
END           { return T_END; }

PROCEDURE     { return T_PROCEDURE; }

READ          { return T_READ; }
WRITE         { return T_WRITE; }

REPEAT        { return T_REPEAT; }
UNTIL         { return T_UNTIL; }

WHILE         { return T_WHILE; }
DO            { return T_DO; }
ENDWHILE      { return T_ENDWHILE; }

IF            {  return T_IF; }
THEN          {  return T_THEN; }
ELSE          {  return T_ELSE; }
ENDIF         { return T_ENDIF; }

\[            { return T_LEFT_BRACKET; }
\]            { return T_RIGHT_BRACKET; }

\(            { return T_LEFTPARENTHESIS; } 
\)            { return T_RIGHTPARENTHESIS; }

T             { return T; }

[_a-z]+       { yylval.str = strdup(yytext); return T_IDENTIFIER; }
[0-9]+        { yylval.num = std::stoll(yytext); return T_NUM; }

.             { return T_ERROR; }

%%

