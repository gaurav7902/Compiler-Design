%option noyywrap

%{
#include "parser.tab.h"
#include <stdlib.h>
%}

%%

[0-9]+       { yylval = atol(yytext); return NUMBER; }
[+*/()-]     { return yytext[0]; }
[ \t\r\n]+   ;
.            { return INVALID; }

%%
