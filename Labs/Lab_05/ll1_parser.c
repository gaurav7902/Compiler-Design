/* Table-driven LL(1) parser for the standard expression grammar. Tokens:
 * id,+,*,(,),$. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const char *nts = "ERTYF", *ts[] = {"id", "+", "*", "(", ")", "$"};
int ti(char *s) {
  for (int i = 0; i < 6; i++)
    if (!strcmp(s, ts[i]))
      return i;
  return -1;
}
int main(void) {
  const char *table[5][6] = {{NULL, NULL, NULL, "TR", NULL, NULL},
                             {"+TR", NULL, NULL, NULL, "#", "#"},
                             {NULL, NULL, NULL, "FY", NULL, NULL},
                             {"#", "+FY", "#", NULL, "#", "#"},
                             {"id", NULL, NULL, "(E)", NULL, NULL}};
  char input[256], stack[256] = "$E";
  printf("Tokens separated by spaces (e.g. id + id * id): ");
  fgets(input, sizeof input, stdin);
  char *v[128];
  int n = 0;
  for (char *p = strtok(input, " \t\r\n"); p && n < 126;
       p = strtok(NULL, " \t\r\n"))
    v[n++] = p;
  int pos = 0;
  puts("Stack (top right) | Input | Action");
  while (*stack) {
    int z = strlen(stack);
    char top = stack[z - 1];
    stack[z - 1] = 0;
    int t = ti(pos < n ? v[pos] : "$");
    printf("%s%c |", stack, top);
    for (int j = pos; j < n; j++)
      printf(" %s", v[j]);
    puts(" $");
    if (top == '$') {
      if (t == 5) {
        puts("Accepted");
        return 0;
      }
      break;
    }
    if (!strchr(nts, top)) {
      if ((top == 'i' && pos < n && !strcmp(v[pos], "id")) ||
          (top != 'i' && pos < n && strlen(v[pos]) == 1 && v[pos][0] == top)) {
        pos++;
        continue;
      }
      break;
    }
    int row = (int)(strchr(nts, top) - nts);
    const char *r = t < 0 ? NULL : table[row][t];
    if (!r)
      break;
    printf("  %c -> %s\n", top, r);
    if (strcmp(r, "#"))
      for (int j = (int)strlen(r) - 1; j >= 0; j--) {
        if (r[j] == 'd' && j > 0 && r[j - 1] == 'i') {
          stack[strlen(stack) - 1] = 'i';
          continue;
        }
        stack[strlen(stack)] = r[j];
        stack[strlen(stack) + 1] = 0;
      }
  }
  puts("Rejected");
  return 1;
}
