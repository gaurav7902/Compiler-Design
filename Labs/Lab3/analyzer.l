%{
#include <stdio.h>
#include <string.h>

int braceDepth = 0;
%}

ID      [a-zA-Z_][a-zA-Z0-9_]*

%%
"{"	{ braceDepth++; }

"}"	{
		if(braceDepth > 0)
		braceDepth--;
	}
     
{ID}[ \t]*"("		{
                            if(braceDepth == 0)
                            {
                                char name[100];
                                int i = 0;

                                while(yytext[i] != '(' &&
                                      yytext[i] != ' ' &&
                                      yytext[i] != '\t')
                                {
                                    name[i] = yytext[i];
                                    i++;
                                }

                                name[i] = '\0';

			if(strcmp(name, "if") != 0 && strcmp(name, "for") != 0 &&
			   strcmp(name, "while") != 0 && strcmp(name, "switch") != 0)
			{
				printf("Function: %s\n", name);
			}
		}
	}

.|\n	;
%%

int yywrap()
{
    return 1;
}

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Usage: %s input.c\n", argv[0]);
        return 1;
    }

    yyin = fopen(argv[1], "r");

    if(yyin == NULL)
    {
        printf("Cannot open file\n");
        return 1;
    }

    yylex();

    fclose(yyin);

    return 0;
}
