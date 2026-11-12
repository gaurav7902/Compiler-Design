#include <stdio.h>
int main(void) {
  puts("Fragment (a):");
  puts("t1 = c * d\nt2 = b + t1\na = t2\nt3 = a + b\nt4 = c * d\nt5 = t3 + "
       "t4\ne = t5\nif e > 20 goto L1\ngoto L2\nL1: t6 = e * 2\nx = t6\ngoto "
       "L3\nL2: t7 = e - 5\nx = t7\nL3: if x > 0 goto L4\ngoto L5\nL4: x = x - "
       "1\ngoto L3\nL5:");
  puts("\nFragment (b):");
  puts("i = 1\nsum = 0\nL1: if i <= n goto L2\ngoto L5\nL2: t1 = a[i]\nif t1 > "
       "0 goto L3\ngoto L4\nL3: t2 = sum + t1\nsum = t2\nL4: i = i + 1\ngoto "
       "L1\nL5: result = sum");
  return 0;
}
