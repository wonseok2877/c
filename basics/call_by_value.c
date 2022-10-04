#include <stdio.h>

int power(int base, int n) {
  int p;
  for (p = 1; n > 0; --n) {
    printf("base : %i n : %i\t p : %i \n", base, n, p);
    p = p * base;
  }
    printf("%i \n", n);
  return p;
}

int main() {
    int base = 10;
    int n = 3;
  int result = power(base, n);

  printf("%i \n", n);
  printf("%i \n", result);
}
