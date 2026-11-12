%{
#include<stdio.h>
int words =0;
%}

%%

[a - zA - Z ]+  words++;
.|\ n ;

%%

int yywrap()
{
    return 1;
}

int main(){
    yylex();
    printf("Words =%d", words );
}