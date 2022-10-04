#include <stdio.h>

// Operator precedence determines the grouping of terms in an expression and
// decides how an expression is evaluated.

void unary() {
  int a = 20;
  int b = 10;
  int c = 15;
  int d = 5;
  int e;

  e = (a + b) * c / d; // ( 30 * 15 ) / 5
  printf("Value of (a + b) * c / d is : %d\n", e);

  e = ((a + b) * c) / d; // (30 * 15 ) / 5
  printf("Value of ((a + b) * c) / d is  : %d\n", e);

  e = (a + b) * (c / d); // (30) * (15/5)
  printf("Value of (a + b) * (c / d) is  : %d\n", e);

  e = a + (b * c) / d; //  20 + (150/5)
  printf("Value of a + (b * c) / d is  : %d\n", e);
}

void hojin() {
  struct PhoneList {
    char *name;
    int phone;
  } phone_list[] = {{"Son", 1111}, {"Pig", 2222}, {"Gom", 3333}, {"Kim", 4444}};

  struct PhoneList *pp = phone_list;
  int x, y, z, w;
  char v, u, t, s, r;

  x = pp++->phone;
  y = ++pp->phone;
  z = (++pp)->phone;

  w = *pp->name;
  v = *pp->name++;
  u = *pp->name;
  t = *--pp->name;
  s = *pp++->name;
  r = *pp->name;

  printf("x=%d, y=%d, z=%d\n", x, y, z);
  printf("v=%c, u=%c, t=%c, s=%c, r=%c \n", v, u, t, s, r);
}
int main() {
  unary();

  hojin();
  return 0;
}
