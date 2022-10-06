#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

// getline : read a line into s, return length
// s : character array, lim : limit of array
int getLine(char s[], int lim) {
  int c, i;
  // s의 각 index상의 element에다 getchar로 얻은 c 값을 할당
  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    s[i] = c;
    /* printf("c : %i \t i : %i\t s : %s \n", c, i, s); */
  }

  s[i] = '\0';
  return i;
}

// reverse
// https://flaviocopes.com/c-return-string/
// TODO pointer은 stack이 아닌 heap에 할당된다? 무슨 의미
const char* reverse(char s[]) {
  int c, i, j;

  for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
   c = s[i], s[i] = s[j], s[j] = c;

    printf("s[%i] -> %c s[%i] -> %c \n", i, s[i],  j, s[j]);
  }

  return s;
}

int main() {
  int len, max = 0; // len : current line length, max : maximum length
  char input[MAXLINE];

  // getLine은 while중에 계속 반복된다. 그런데 0보다 커야한다는 조건은 어떻게
  // false로 만들지?
  while ((len = getLine(input, MAXLINE)) > 0){

    printf("input : %s\n", input);

    const char * result = reverse(input);
    printf("result : %s\n", result);
}


   return 0;
}

