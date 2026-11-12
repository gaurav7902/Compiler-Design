/* Emit three-address code and Graphviz DOT control-flow graphs for Week 10
 * fragments. */
#include <stdio.h>
int main(void) {
  FILE *f = fopen("fragment_a.dot", "w");
  if (!f) {
    perror("fragment_a.dot");
    return 1;
  }
  fputs(
      "digraph CFG {\n  node [shape=box];\n  B1 [label=\"B1: t1=c*d; a=b+t1; "
      "t2=a+b; t3=c*d; e=t2+t3\"];\n  B2 [label=\"B2: if e>20\"];\n  B3 "
      "[label=\"B3: x=e*2\"];\n  B4 [label=\"B4: x=e-5\"];\n  B5 [label=\"B5: "
      "if x>0\"];\n  B6 [label=\"B6: x=x-1\"];\n  B7 [label=\"B7: exit\"];\n  "
      "B1->B2; B2->B3 [label=true]; B2->B4 [label=false]; B3->B5; B4->B5; "
      "B5->B6 [label=true]; B5->B7 [label=false]; B6->B5;\n}\n",
      f);
  fclose(f);
  f = fopen("fragment_b.dot", "w");
  if (!f) {
    perror("fragment_b.dot");
    return 1;
  }
  fputs("digraph CFG {\n  node [shape=box];\n  B1 [label=\"B1: i=1; "
        "sum=0\"];\n  B2 [label=\"B2: if i<=n\"];\n  B3 [label=\"B3: t1=a[i]; "
        "if t1>0\"];\n  B4 [label=\"B4: sum=sum+t1\"];\n  B5 [label=\"B5: "
        "i=i+1\"];\n  B6 [label=\"B6: result=sum; exit\"];\n  B1->B2; B2->B3 "
        "[label=true]; B2->B6 [label=false]; B3->B4 [label=true]; B3->B5 "
        "[label=false]; B4->B5; B5->B2;\n}\n",
        f);
  fclose(f);
  puts("Wrote fragment_a.dot and fragment_b.dot. Render with: dot -Tpng "
       "fragment_a.dot -o fragment_a.png");
  puts("Fragment (a) TAC: t1=c*d; a=b+t1; t2=a+b; t3=c*d; e=t2+t3; if e>20 "
       "...; while x>0 ...");
  puts("Fragment (b) TAC: i=1; sum=0; loop if i<=n; test a[i]>0; accumulate; "
       "increment i; result=sum.");
  return 0;
}
