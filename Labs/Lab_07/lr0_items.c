/* Canonical LR(0) item-set construction for S'->S, S->CC, C->cC|d. */
#include <stdio.h>
#include <string.h>
#define MAX 32
#define P 4
const char *left[] = {"S'", "S", "C", "C"}, *right[] = {"S", "CC", "cC", "d"};
typedef struct {
  int p, dot;
} Item;
typedef struct {
  Item a[MAX];
  int n;
} Set;
int has(Set *s, int p, int d) {
  for (int i = 0; i < s->n; i++)
    if (s->a[i].p == p && s->a[i].dot == d)
      return 1;
  return 0;
}
void add(Set *s, int p, int d) {
  if (!has(s, p, d) && s->n < MAX)
    s->a[s->n++] = (Item){p, d};
}
void closure(Set *s) {
  int change = 1;
  while (change) {
    change = 0;
    for (int i = 0; i < s->n; i++) {
      Item x = s->a[i];
      char c = right[x.p][x.dot];
      if (c)
        for (int p = 0; p < P; p++)
          if (left[p][0] == c && !has(s, p, 0)) {
            add(s, p, 0);
            change = 1;
          }
    }
  }
}
int eq(Set *a, Set *b) {
  if (a->n != b->n)
    return 0;
  for (int i = 0; i < a->n; i++)
    if (!has(b, a->a[i].p, a->a[i].dot))
      return 0;
  return 1;
}
int main(void) {
  Set states[32] = {0};
  add(&states[0], 0, 0);
  closure(&states[0]);
  int n = 1;
  for (int i = 0; i < n; i++) {
    for (char sym = '('; sym <= 'd'; sym++) {
      Set t = {0};
      for (int j = 0; j < states[i].n; j++) {
        Item x = states[i].a[j];
        if (right[x.p][x.dot] == sym)
          add(&t, x.p, x.dot + 1);
      }
      if (!t.n)
        continue;
      closure(&t);
      int k;
      for (k = 0; k < n && !eq(&states[k], &t); k++)
        ;
      if (k == n)
        states[n++] = t;
    }
  }
  for (int i = 0; i < n; i++) {
    printf("I%d:\n", i);
    for (int j = 0; j < states[i].n; j++) {
      Item x = states[i].a[j];
      printf("  %s -> ", left[x.p]);
      for (int k = 0; k <= (int)strlen(right[x.p]); k++) {
        if (k == x.dot)
          putchar('.');
        if (right[x.p][k])
          putchar(right[x.p][k]);
      }
      puts("");
    }
  }
  puts("LR(0) ACTION/GOTO table can be derived from these item sets and "
       "transitions.");
  return 0;
}
