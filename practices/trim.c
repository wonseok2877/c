#include <stdio.h>
#include <string.h>

// trim : remove trailing blanks, tabs, new lines
int trim(char s[]) {
  int n;
  printf("length : %lu\n", strlen(s));
  for (n = strlen(s) - 1; n >= 0; n--) {
    printf("s[n] : %c \n", s[n]);
    if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n'){
        printf("s[n] : %c \n", s[n]);
break;}
  }

  s[n + 1] = '\0';
  printf("s : %s \n", s);
  return n;
}

int main() {
  char my_char[] = "a  p p l e   \n \t ";

  int result = trim(my_char);

  printf("%i \n", result);

  return 0;
}
