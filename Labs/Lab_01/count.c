#include <ctype.h>
#include <stdio.h>

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s file\n", argv[0]);
    return 1;
  }
  FILE *fp = fopen(argv[1], "r");
  if (!fp) {
    perror(argv[1]);
    return 1;
  }
  long chars = 0, words = 0, lines = 0;
  int c, in_word = 0, last = '\n';
  while ((c = fgetc(fp)) != EOF) {
    chars++;
    last = c;
    if (c == '\n')
      lines++;
    if (isspace((unsigned char)c))
      in_word = 0;
    else if (!in_word) {
      words++;
      in_word = 1;
    }
  }
  if (chars && last != '\n')
    lines++;
  fclose(fp);
  printf(
      "Number of Characters: %ld\nNumber of Words: %ld\nNumber of Lines: %ld\n",
      chars, words, lines);
  return 0;
}
