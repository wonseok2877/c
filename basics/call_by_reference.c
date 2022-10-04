#include <stdio.h>
#include <ctype.h>

void swap_1(int x, int y) {
  int temp;

  temp = x;
  x = y;
  y = temp;
}
void swap_2(int *px, int *py) {
  int temp;

  temp = *px;
  *px = *py;
  *py = temp;
}

int main() {
  int a = 3, b = 9;

  // call by value
  swap_1(a, b);
  printf("a:%i\tb:%i\n", a, b);
  // call by reference
  swap_2(&a, &b);

  printf("a:%i\tb:%i\n", a, b);
}
