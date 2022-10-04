#include <stdio.h>

int main(){
int x = 10, y = 7;

  printf("x= %i\n", x);

  // arithmetic Operator
  printf("arithmetic Operators. \n");
  x += y;
  printf("x= %i\n", x);
  x -= y;
  printf("x= %i\n", x);

  x *= y;
  printf("x= %i\n", x);
  x /= y;
  printf("x= %i\n", x);

  x %= y;
  printf("x= %i\n", x);

  // bitwise Operator
  printf("bitwise Operators. \n");
  x <<= y;
  printf("x= %i\n", x);
  x >>= y;
  printf("x= %i\n", x);

  x &= y;
  printf("x= %i\n", x);
  x ^= y;
  printf("x= %in", x);
  x |= y;
  printf("x= %in", x);

return 0;
}
