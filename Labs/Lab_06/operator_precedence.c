/* Demonstrates operator-precedence parsing trace for id + id * id. */
#include <stdio.h>
#include <string.h>
int main(void) {
  const char *stack[] = {"$",     "$id",     "$E",     "$E+",  "$E+id", "$E+E",
                         "$E+E*", "$E+E*id", "$E+E*E", "$E+E", "$E"};
  const char *input[] = {"id+id*id$", "+id*id$", "+id*id$", "id*id$",
                         "*id$",      "*id$",    "id$",     "$",
                         "$",         "$",       "$"};
  const char *action[] = {"shift id",
                          "reduce id to E",
                          "shift +",
                          "shift id",
                          "reduce id to E",
                          "shift *",
                          "shift id",
                          "reduce id to E",
                          "reduce E*E to E (handle: E*E)",
                          "reduce E+E to E (handle: E+E)",
                          "accept"};
  puts("Stack\tInput\tAction");
  for (int i = 0; i < 11; i++)
    printf("%s\t%s\t%s\n", stack[i], input[i], action[i]);
  puts("Precedence: * > +; operands shift/reduce as E; parentheses bind "
       "highest.");
  return 0;
}
