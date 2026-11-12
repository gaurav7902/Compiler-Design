#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *fp;
    int c;
    int insideWord = 0;
    int previous = '\n';

    long characters = 0;
    long words = 0;
    long lines = 0;

    fp = fopen("Sample.txt", "r");

    if (fp == NULL) {
        printf("Error opening file");
        return 0;
    }

    while ((c = fgetc(fp)) != EOF) {
        characters++;
        previous = c;

        if (c == '\n')
            lines++;

        if (isspace((unsigned char)c)) {
            insideWord = 0;
        } else {
            if (insideWord == 0) {
                words++;
                insideWord = 1;
            }
        }
    }

    if (characters > 0 && previous != '\n')
        lines++;

    fclose(fp);

    printf("Number of Characters: %ld\n", characters);
    printf("Number of Words: %ld\n", words);
    printf("Number of Lines: %ld\n", lines);

    return 0;
}