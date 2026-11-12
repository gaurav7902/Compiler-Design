/* Ordered substitution + immediate-left-recursion removal for single-character
   nonterminals. Input format: count, then lines such as S->Aa|b ; epsilon is
   written as #. */
#include <stdio.h>
#include <string.h>
#define N 16
#define P 32
#define L 128
char nt[N], prod[N][P][L];
int cnt[N];
int indexof(char c, int n) {
  for (int i = 0; i < n; i++)
    if (nt[i] == c)
      return i;
  return -1;
}
int main(void) {
  int n;
  if (scanf("%d", &n) != 1 || n < 1 || n >= N)
    return 1;
  for (int i = 0; i < n; i++) {
    char line[1024];
    scanf("%127s", line);
    char *a = strstr(line, "->");
    if (!a)
      return 1;
    nt[i] = line[0];
    char rhs[900];
    strcpy(rhs, a + 2);
    for (char *t = strtok(rhs, "|"); t && cnt[i] < P; t = strtok(NULL, "|"))
      strcpy(prod[i][cnt[i]++], t);
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < i; j++) {
      char next[P][L];
      int nn = 0;
      for (int p = 0; p < cnt[i]; p++) {
        char *r = prod[i][p];
        if (r[0] == nt[j]) {
          for (int q = 0; q < cnt[j] && nn < P; q++) {
            snprintf(next[nn++], L, "%s%s",
                     strcmp(prod[j][q], "#") ? prod[j][q] : "", r + 1);
          }
        } else if (nn < P)
          strcpy(next[nn++], r);
      }
      memcpy(prod[i], next, sizeof next);
      cnt[i] = nn;
    }
  for (int i = 0; i < n; i++) {
    char rec[P][L], base[P][L];
    int nr = 0, nb = 0;
    for (int p = 0; p < cnt[i]; p++) {
      if (prod[i][p][0] == nt[i])
        strcpy(rec[nr++], prod[i][p] + 1);
      else
        strcpy(base[nb++], prod[i][p]);
    }
    if (!nr)
      continue;
    if (!nb) {
      fprintf(stderr,
              "Cannot eliminate left recursion for %c: no beta alternative\n",
              nt[i]);
      continue;
    }
    char prime = (nt[i] == 'Z' ? 'a' : nt[i] + 1);
    printf("%c -> ", nt[i]);
    for (int b = 0; b < nb; b++)
      printf("%s%c%c%s", !strcmp(base[b], "#") ? "" : base[b], prime,
             (b + 1 < nb) ? '|' : '\n', "");
    printf("%c -> ", prime);
    for (int r = 0; r < nr; r++)
      printf("%s%c%c", rec[r], prime, (r + 1 < nr) ? '|' : '|');
    puts("epsilon");
  }
  for (int i = 0; i < n; i++) {
    int rec = 0;
    for (int p = 0; p < cnt[i]; p++)
      if (prod[i][p][0] == nt[i])
        rec = 1;
    if (!rec) {
      printf("%c -> ", nt[i]);
      for (int p = 0; p < cnt[i]; p++)
        printf("%s%s", prod[i][p], p + 1 < cnt[i] ? "|" : "\n");
    }
  }
  return 0;
}
