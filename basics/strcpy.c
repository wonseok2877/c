#include <stdio.h>

/* array subscript version
 * argument로 pointer를 보냈을 때 에러 발생 : segmentation fault (core dumped).
 * caused by accessing memory that “does not belong to you.”
 * */
void strcpy1(char *s, char *t) {
  int i = 0;

  while (t[i] != '\0') {
    printf("s[i]:%c \t t[i]:%c\n", s[i], t[i]);
    s[i] = t[i];
    i++;
  }
}

/* pointer version*/
void strcpy2(char *s, char *t) {
  while (*t != '\0') {
    printf("*s:%c\t *t:%c\n", *s, *t);
    *s = *t;
    s++, t++;
  }
}

/* pointer version 2 */
void strcpy3(char *s, char *t) {
  printf("*s:%c \t *t:%c \n", *s, *t);

  while ((*s++ = *t++) != '\0')
    ;
}

void strcpy4(char *s, char *t) {
  printf("*s:%c \t *t:%c \n", *s, *t);
  while ((*s++ = *t++))
    ;
}

int main() {
  // array
  char a[] = "apples", b[] = "banana";
  char c[] = "coconut", d[] = "dragon";
  char e[] = "egg", f[] = "from where?";
  char g[] = "game", h[] = "hello world";

  *(e + 3) = 's';
  printf("%p %p \n", e + 3, a);

  printf("e: %s\n", e);
  strcpy1(a, b);

  printf("a:%s\t b:%s\n", a, b);

  strcpy2(c, d);
  printf("c:%s\t d:%s\n", c, d);

  strcpy3(e, f);
  printf("e:%s\t f:%s\n", e, f);

  strcpy4(g, h);
  printf("g:%s\t h:%s\n", g, h);

  return 0;
}
