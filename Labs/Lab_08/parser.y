%{
#include <stdio.h>
int yylex(void);
void yyerror(const char *s);
%}

%define parse.error verbose
%token NUMBER INVALID
%left '+' '-'
%left '*' '/'
%precedence UMINUS

%%

input : expr { printf("Result = %ld\n", $1); } ;

expr : NUMBER             { $$ = $1; }
     | expr '+' expr      { $$ = $1 + $3; }
     | expr '-' expr      { $$ = $1 - $3; }
     | expr '*' expr      { $$ = $1 * $3; }
     | expr '/' expr      {
           if (!$3) { yyerror("division by zero"); YYERROR; }
           $$ = $1 / $3;
       }
     | '-' expr %prec UMINUS { $$ = -$2; }
     | '(' expr ')'       { $$ = $2; }
     ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Invalid expression: %s\n", s);
}

int main(void) { return yyparse(); }
