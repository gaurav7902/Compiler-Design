#include <ctype.h>
#include <stdio.h>

static void count_file(const char *name, long *tc, long *tw, long *tl) {
  FILE *fp = fopen(name, "r");
  if (!fp) {
    perror(name);
    return;
  }
  long ccount = 0, wcount = 0, lcount = 0;
  int c, in_word = 0, last = '\n';
  while ((c = fgetc(fp)) != EOF) {
    ccount++;
    last = c;
    if (c == '\n')
      lcount++;
    if (isspace((unsigned char)c))
      in_word = 0;
    else if (!in_word) {
      wcount++;
      in_word = 1;
    }
  }
  if (ccount && last != '\n')
    lcount++;
  fclose(fp);
  printf("File: %s\nCharacters: %ld\nWords: %ld\nLines: %ld\n\n", name, ccount,
         wcount, lcount);
  *tc += ccount;
  *tw += wcount;
  *tl += lcount;
}
int main(int argc, char **argv) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s file...\n", argv[0]);
    return 1;
  }
  long c = 0, w = 0, l = 0;
  for (int i = 1; i < argc; i++)
    count_file(argv[i], &c, &w, &l);
  printf("Total Characters: %ld\nTotal Words: %ld\nTotal Lines: %ld\n", c, w,
         l);
  return 0;
}
