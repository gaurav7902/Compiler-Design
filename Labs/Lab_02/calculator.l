%{
#include <stdio.h>
%}

%%

[0-9]+      { return 256; }
[+*/%-]     { return yytext[0]; }
[ \t\r\n]+  ;
.           { return yytext[0]; }

%%

int yywrap(void) { return 1; }

int main(void) {
    int a, b;
    char op;
    while (scanf("%d %c %d", &a, &op, &b) == 3) {
        if (op == '+') printf("Result = %d\n", a + b);
        else if (op == '-') printf("Result = %d\n", a - b);
        else if (op == '*') printf("Result = %d\n", a * b);
        else if (op == '/' && b != 0) printf("Result = %d\n", a / b);
        else if (op == '%' && b != 0) printf("Result = %d\n", a % b);
        else printf("Error: invalid operator or division by zero.\n");
    }
    return 0;
}
