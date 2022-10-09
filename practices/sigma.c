#include <stdio.h>

int sigma(int n) {
  int r;
  for (r = 0; n > 0; n--)
    r += n;
  return r;
}
int main() {

  int a;
  printf("Input Number : ");
  scanf("%d", &a);
  printf("Sigma 1 to %d = %d\n", a, sigma(a));
}
