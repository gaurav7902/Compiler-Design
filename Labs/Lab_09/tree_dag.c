#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node {
  char v;
  struct Node *l, *r;
  int id;
} Node;
Node *nodes[64];
int nn;
Node *make(char v, Node *l, Node *r, int share) {
  if (share)
    for (int i = 0; i < nn; i++)
      if (nodes[i]->v == v && nodes[i]->l == l && nodes[i]->r == r)
        return nodes[i];
  Node *n = calloc(1, sizeof *n);
  n->v = v;
  n->l = l;
  n->r = r;
  n->id = ++nn;
  nodes[nn - 1] = n;
  return n;
}
void pre(Node *n) {
  if (!n)
    return;
  printf("%c ", n->v);
  pre(n->l);
  pre(n->r);
}
void in(Node *n) {
  if (!n)
    return;
  if (n->l) {
    putchar('(');
    in(n->l);
  }
  putchar(n->v);
  if (n->r) {
    in(n->r);
    putchar(')');
  }
}
void post(Node *n) {
  if (!n)
    return;
  post(n->l);
  post(n->r);
  printf("%c ", n->v);
}
int main(void) {
  Node *a = make('a', 0, 0, 0), *b = make('b', 0, 0, 0),
       *c = make('c', 0, 0, 0), *d = make('d', 0, 0, 0);
  Node *ab = make('+', a, b, 0), *cd = make('-', c, d, 0);
  Node *left = make('*', ab, cd, 0),
       *right = make('*', make('+', a, b, 0), make('-', c, d, 0), 0);
  Node *root = make('+', left, right, 0);
  printf("Syntax tree preorder: ");
  pre(root);
  printf("\ninorder: ");
  in(root);
  printf("\npostorder: ");
  post(root);
  printf("\nSyntax-tree nodes: %d\n", nn);
  nn = 0;
  ab = make('+', a, b, 1);
  cd = make('-', c, d, 1);
  left = make('*', ab, cd, 1);
  right = make('*', ab, cd, 1);
  root = make('+', left, right, 1);
  puts("DAG nodes (id: value, children):");
  for (int i = 0; i < nn; i++)
    printf("%d: %c, %d, %d\n", nodes[i]->id, nodes[i]->v,
           nodes[i]->l ? nodes[i]->l->id : 0,
           nodes[i]->r ? nodes[i]->r->id : 0);
  printf("DAG nodes: %d (shared repeated subexpressions)\n", nn);
  return 0;
}
