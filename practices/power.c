#include <stdio.h>

// parameter names can be omitted
int power(int , int);

void main() {
  for (int i = 0; i < 10; ++i)
    printf("%d %d %d\n", power(2, i), power(-3, i),power(10, i));
}

// power : raise base to n-th power n>=0
int power(int base, int n) {
  int p = 1;
  for (int i = 1; i <= n; ++i)
    p = p * base;

  printf("n:%d\t base:%d\t p:%d\n", n, base, p);
  return p;
}
