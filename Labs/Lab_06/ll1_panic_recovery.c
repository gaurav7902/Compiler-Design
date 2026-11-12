/* Predictive parser with panic-mode recovery for E->TR, R->+TR|epsilon, T->FY,
   Y->*FY|epsilon, F->(E)|id. Input tokens separated by spaces; id + * id
   illustrates recovery. */
#include <stdio.h>
#include <string.h>
int main(void) {
  char line[256], *in[100], stack[256] = "$E";
  int n = 0, p = 0;
  fputs("Enter tokens: ", stdout);
  fgets(line, sizeof line, stdin);
  for (char *t = strtok(line, " \t\r\n"); t && n < 98;
       t = strtok(NULL, " \t\r\n"))
    in[n++] = t;
  puts("This parser uses panic recovery: when no table entry exists, discard "
       "input until a synchronizing token.");
  while (*stack) {
    int z = strlen(stack);
    char X = stack[--z];
    stack[z] = 0;
    char *a = p < n ? in[p] : "$";
    if (X == '$') {
      if (!strcmp(a, "$")) {
        puts("Accepted");
        return 0;
      }
      break;
    }
    if (X == 'i') {
      if (!strcmp(a, "id")) {
        p++;
        continue;
      }
      printf("Missing id before %s; inserting id\n", a);
      continue;
    }
    if (X == '+' || X == '*' || X == '(' || X == ')') {
      char q[2] = {X, 0};
      if (!strcmp(a, q)) {
        p++;
        continue;
      }
      printf("Expected %c, got %s; inserting %c\n", X, a, X);
      continue;
    }
    if ((X == 'R' && (!strcmp(a, ")") || !strcmp(a, "$"))) ||
        (X == 'Y' && (!strcmp(a, "+") || !strcmp(a, ")") || !strcmp(a, "$"))))
      continue;
    if (X == 'R' && !strcmp(a, "+")) {
      strcat(stack, "T+");
      continue;
    }
    if (X == 'Y' && !strcmp(a, "*")) {
      strcat(stack, "F*Y");
      continue;
    }
    if (X == 'E' && !strcmp(a, "id")) {
      strcat(stack, "RT");
      continue;
    }
    if (X == 'E' && !strcmp(a, "(")) {
      strcat(stack, "RT");
      continue;
    }
    if (X == 'T' && (!strcmp(a, "id") || !strcmp(a, "("))) {
      strcat(stack, "YF");
      continue;
    }
    if (X == 'F' && !strcmp(a, "id")) {
      stack[strlen(stack)] = 'i';
      stack[strlen(stack) + 1] = 0;
      continue;
    }
    if (X == 'F' && !strcmp(a, "(")) {
      strcat(stack, ")E(");
      continue;
    }
    printf("Synchronize: pop %c at lookahead %s\n", X, a);
    if (!strcmp(a, "$"))
      break;
    p++;
  }
  puts("Input rejected (recovered errors were encountered)");
  return 1;
}
