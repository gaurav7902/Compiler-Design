%{
#include <stdio.h>
extern FILE *yyin;
long lines, words, chars;
long total_lines, total_words, total_chars;
%}

%%

\n              { lines++; chars++; }
[ \t\r]+        { chars += yyleng; }
[^ \t\r\n]+    { words++; chars += yyleng; }

%%

int yywrap(void) { return 1; }

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s file...\n", argv[0]);
        return 1;
    }
    for (int i = 1; i < argc; i++) {
        yyin = fopen(argv[i], "r");
        if (!yyin) { perror(argv[i]); continue; }
        lines = words = chars = 0;
        yylex();
        printf("File: %s\nLines: %ld\nWords: %ld\nCharacters: %ld\n\n",
               argv[i], lines, words, chars);
        total_lines += lines;
        total_words += words;
        total_chars += chars;
        fclose(yyin);
    }
    printf("Total\nLines: %ld\nWords: %ld\nCharacters: %ld\n",
           total_lines, total_words, total_chars);
    return 0;
}
