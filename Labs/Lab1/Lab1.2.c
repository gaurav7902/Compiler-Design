#include <stdio.h>
#include <ctype.h>

int main(int count, char *files[]) {
    if (count < 2) {
        printf("Error accessing file\n");
        return 1;
    }

    long totalChars = 0;
    long totalWords = 0;
    long totalLines = 0;
    int processedFiles = 0;

    for (int index = 1; index < count; index++) {
        FILE *fp = fopen(files[index], "r");

        if (fp == NULL) {
            printf("Error opening file");
            continue;
        }

        long charCount = 0;
        long wordCount = 0;
        long lineCount = 0;

        int current;
        int insideWord = 0;
        int previous = '\n';

        while ((current = fgetc(fp)) != EOF) {
            charCount++;

            if (current == '\n')
                lineCount++;

            if (isspace((unsigned char)current)) {
                insideWord = 0;
            } else {
                if (!insideWord) {
                    wordCount++;
                    insideWord = 1;
                }
            }

            previous = current;
        }

        if (charCount > 0 && previous != '\n')
            lineCount++;

        fclose(fp);

        printf("File: %s\n", files[index]);
        printf("characters: %ld\n", charCount);
        printf("Words: %ld\n", wordCount);
        printf("Lines: %ld\n\n", lineCount);

        totalChars += charCount;
        totalWords += wordCount;
        totalLines += lineCount;
        processedFiles++;
    }

    printf("--------------------------------------------------------\n");
    printf("Total Files Processed: %d\n", processedFiles);
    printf("Total Characters: %ld\n", totalChars);
    printf("Total Words: %ld\n", totalWords);
    printf("Total Lines: %ld\n", totalLines);

    return 0;
}