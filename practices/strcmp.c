#include <stdio.h>

/* return <0 if s<t, 0 if s==t, >0 if s>t */
int strcmp1(char *s, char *t) {
  int i;
  for (i = 0; s[i] == t[i]; i++) {
    if (s[i] == '\0') {
      return 0;
    }
  }
  printf("s[i] : %c\t t[i] : %c\n", s[i], t[i]);

  return s[i] - t[i];
}

/* pointer version */
int strcmp2(char *s, char *t) {
  for (; *s == *t; s++, t++) {
    if (*s == '\0')
      return 0;
  }
  printf("*s : %c\t *t : %c\n", *s, *t);

  return *s - *t;
}

int main() {
  char a[] = "apple", b[] = "appL";
  char c[] = "coconut", d[] = "coconutt";

  printf("%i \n", strcmp1(a, b));
  printf("%i \n", strcmp2(c, d));

  printf("c : %s\t d : %s\n", c, d);

  // stack?
  int arr[] = {1, 2, 3, 4, 5};
  int *p = arr;
  int val = 100;

  *p++ = val;
  for (int i = 0; i < 5; i++)
    printf("%i\n", arr[i]);
  val = *--p;
  for (int i = 0; i < 5; i++)
    printf("%i\n", arr[i]);
}
