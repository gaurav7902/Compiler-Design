/* FIRST/FOLLOW calculator. Grammar: number-of-productions followed by A->rhs
 * lines; # denotes epsilon. */
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#define M 32
#define R 64
#define W 128
char lhs[R], rhs[R][W], nts[M], first[M][256], follow[M][256];
int np, nn;
int ni(char c) {
  for (int i = 0; i < nn; i++)
    if (nts[i] == c)
      return i;
  return -1;
}
int terminal(char c) { return !isupper((unsigned char)c) && c != '#'; }
int add(char *s, char c) {
  if (!strchr(s, c)) {
    int n = strlen(s);
    s[n] = c;
    s[n + 1] = 0;
    return 1;
  }
  return 0;
}
int main(void) {
  if (scanf("%d", &np) != 1 || np >= R)
    return 1;
  for (int i = 0; i < np; i++) {
    char line[W];
    scanf("%127s", line);
    char *a = strstr(line, "->");
    if (!a)
      return 1;
    lhs[i] = line[0];
    strcpy(rhs[i], a + 2);
    if (ni(lhs[i]) < 0)
      nts[nn++] = lhs[i];
  }
  int change = 1;
  while (change) {
    change = 0;
    for (int p = 0; p < np; p++) {
      int A = ni(lhs[p]);
      char *s = rhs[p];
      if (!strcmp(s, "#")) {
        change |= add(first[A], '#');
        continue;
      }
      int nullable = 1;
      for (int k = 0; s[k] && nullable; k++) {
        int B = ni(s[k]);
        if (B < 0) {
          change |= add(first[A], s[k]);
          nullable = 0;
        } else {
          for (int x = 0; first[B][x]; x++)
            if (first[B][x] != '#')
              change |= add(first[A], first[B][x]);
          if (!strchr(first[B], '#'))
            nullable = 0;
        }
      }
      if (nullable)
        change |= add(first[A], '#');
    }
  }
  add(follow[0], '$');
  change = 1;
  while (change) {
    change = 0;
    for (int p = 0; p < np; p++)
      for (int k = 0; rhs[p][k]; k++) {
        int B = ni(rhs[p][k]);
        if (B < 0)
          continue;
        int nullable = 1;
        for (int j = k + 1; rhs[p][j] && nullable; j++) {
          int C = ni(rhs[p][j]);
          if (C < 0) {
            change |= add(follow[B], rhs[p][j]);
            nullable = 0;
          } else {
            for (int x = 0; first[C][x]; x++)
              if (first[C][x] != '#')
                change |= add(follow[B], first[C][x]);
            if (!strchr(first[C], '#'))
              nullable = 0;
          }
        }
        if (nullable) {
          int A = ni(lhs[p]);
          for (int x = 0; follow[A][x]; x++)
            change |= add(follow[B], follow[A][x]);
        }
      }
  }
  for (int i = 0; i < nn; i++)
    printf("FIRST(%c)={%s} FOLLOW(%c)={%s}\n", nts[i], first[i], nts[i],
           follow[i]);
  return 0;
}
