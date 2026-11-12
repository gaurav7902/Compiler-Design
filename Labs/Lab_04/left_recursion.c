/* Eliminates immediate left recursion for one production. Input: E -> E+T|E-T|T
 */
#include <stdio.h>
#include <string.h>
#define MAX 512
int main(void) {
  char line[MAX], lhs[64], rhs[MAX], *alts[64];
  int n = 0;
  puts("Enter production (example: E -> E+T|T):");
  if (!fgets(line, sizeof line, stdin))
    return 1;
  char *arrow = strstr(line, "->");
  if (!arrow) {
    fprintf(stderr, "Expected ->\n");
    return 1;
  }
  int k = (int)(arrow - line);
  while (k > 0 && line[k - 1] == ' ')
    k--;
  memcpy(lhs, line, k);
  lhs[k] = '\0';
  strncpy(rhs, arrow + 2, sizeof(rhs) - 1);
  rhs[strcspn(rhs, "\r\n")] = 0;
  for (char *p = strtok(rhs, "|"); p && n < 64; p = strtok(NULL, "|"))
    alts[n++] = p;
  char *rec[64], *base[64];
  int nr = 0, nb = 0, L = strlen(lhs);
  for (int i = 0; i < n; i++) {
    if (!strncmp(alts[i], lhs, L))
      rec[nr++] = alts[i] + L;
    else
      base[nb++] = alts[i];
  }
  if (!nr) {
    puts("No immediate left recursion.");
    return 0;
  }
  if (!nb) {
    puts("Cannot eliminate: no non-recursive alternative.");
    return 1;
  }
  printf("%s -> ", lhs);
  for (int i = 0; i < nb; i++)
    printf("%s%s%s", base[i], lhs, (i + 1 < nb) ? " | " : "\n");
  printf("%s' -> ", lhs);
  for (int i = 0; i < nr; i++)
    printf("%s%s'%s", rec[i], lhs, (i + 1 < nr) ? " | " : " | epsilon\n");
  return 0;
}
