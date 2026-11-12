%{
	#include<stdio.h>
	#include<stdlib.h>
	
	int lines,words,chars;
	int total_lines =0;	
	int total_words =0;	
	int total_chars =0;	

	extern FILE *yyin;
%}

%%

\n		{lines++;chars++;}
[\t]+		{chars+=yyleng;}
[^\t\n]+ 	{words++;chars+=yyleng;}

%%

int yywrap(){
	return 1;
}

int main(int argc, char* argv[])
{
	if(argc < 2 )
	{
	        printf("Usage: %s file1 file2 ...\n", argv[0]);
		return 1;
	}

	for(int i=1; i<argc; i++){
		yyin = fopen(argv[i], "r");

		if(yyin == NULL){
			printf("Cannot Open file %s\n", argv[i]);
			continue;
		}
		lines =0;
		words =0;
		chars =0;
		yyrestart(yyin);
		yylex();
		
		printf("\nFile: %s\n", argv[i]);
		printf("Lines      : %d\n", lines);
		printf("Words      : %d\n", words);
		printf("Characters : %d\n", chars);

		total_lines += lines;
		total_words += words;
		total_chars += chars;

		fclose(yyin);
	}
	printf("\nTotal\n");
	printf("Total Lines      : %d\n", total_lines);
	printf("Total Words      : %d\n", total_words);
	printf("Total Characters : %d\n", total_chars);
	
	return 0;
}
