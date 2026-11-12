%{
#include <stdio.h>
#include <string.h>
int keywords = 0, identifiers = 0, integers = 0, floats = 0;
int operators = 0, delimiters = 0;
%}

DIGIT [0-9]
ID [a-zA-Z_][a-zA-Z0-9_]*

%%

"int"|"float"|"char"|"if"|"else"|"while"|"for"|"return"|"void" {
    printf("Keyword: %s\n", yytext); keywords++;
}
{DIGIT}+\.{DIGIT}+ {
    printf("Float: %s\n", yytext); floats++;
}
{DIGIT}+ {
    printf("Integer: %s\n", yytext); integers++;
}
{ID} {
    printf("Identifier: %s\n", yytext); identifiers++;
}
"=="|"!="|"<="|">="|"++"|"--"|"&&"|"||"|[+*/%=<>!-] {
    printf("Operator: %s\n", yytext); operators++;
}
[(){}\[\],;.] {
    printf("Delimiter: %s\n", yytext); delimiters++;
}
[ \t\r\n]+|\/\/[^\n]*|\/\*([^*]|\*+[^*/])*\*+\/ ;
. { printf("Unknown: %s\n", yytext); }

%%

int yywrap(void) { return 1; }

int main(int argc, char **argv) {
    if (argc == 2) {
        yyin = fopen(argv[1], "r");
        if (!yyin) { perror(argv[1]); return 1; }
    }
    yylex();
    printf("Keywords: %d\nIdentifiers: %d\nIntegers: %d\nFloats: %d\n"
           "Operators: %d\nDelimiters: %d\n",
           keywords, identifiers, integers, floats, operators, delimiters);
    return 0;
}
