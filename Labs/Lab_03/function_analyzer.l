%{
#include <stdio.h>
#include <string.h>
int depth = 0;
%}

ID [a-zA-Z_][a-zA-Z0-9_]*

%%

"{" { depth++; }
"}" { if (depth > 0) depth--; }
{ID}[ \t]*\( {
    if (depth == 0) {
        char name[128];
        sscanf(yytext, "%127[^ (]", name);
        if (strcmp(name, "if") && strcmp(name, "for") &&
            strcmp(name, "while") && strcmp(name, "switch")) {
            printf("Function: %s\n", name);
        }
    }
}
. | \n ;

%%

int yywrap(void) { return 1; }

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s file.c\n", argv[0]);
        return 1;
    }
    yyin = fopen(argv[1], "r");
    if (!yyin) { perror(argv[1]); return 1; }
    yylex();
    fclose(yyin);
    return 0;
}
