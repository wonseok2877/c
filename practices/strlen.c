#include <stdio.h>
#include <string.h>

int str_len(char s[]) {
  printf("%s\n", s);
  int i = 0;
  while (s[i] != '\0')
    ++i;
  return i;
}

// formal parameter은 s[]보단 *s가 ANSI에서 더 권장됨.
int str_len2(char *s) {
  int n;

  for (n = 0; *s != '\0'; s++, n++)
    /* printf("s: %p \t *s : %c\n",s, *s); */
    ;
  return n;
}

int main() {
  char mychar[] = "abcdefg";
  char *p = mychar;
  printf("%i \n", str_len(mychar));
  // strlen : from strin:whileg.h
  printf("%lu \n", strlen(mychar));

  printf("result of array name: %i \n", str_len2(mychar));
  printf("result of constant string: %i \n", str_len2("abcdefg"));
  printf("result of pointer: %i \n", str_len2(p));

  return 0;
}
