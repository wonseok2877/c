#include <stdio.h>
#define MAXLINE 1000

// getline : read a line into s, return length
// s : character array, lim : limit of array
int getLine(char s[], int lim) {
  int c, i;
  // s의 각 index상의 element에다 getchar로 얻은 c 값을 할당
  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    s[i] = c;
    printf("c : %i \t i : %i\t s : %s \n", c, i, s);
  }

  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  // TODO \0은 무슨 역할을 하는거고, 왜 터미널에선 안 보이는걸까?
  s[i] = '\0';
  return i;
}

// copy : copy 'from' into 'to'. assume 'to' is big enough
void copy(char to[], char from[]) {
  int i = 0;
  while ((to[i] = from[i]) != '\0') {
    printf("to : %s\t from : %s", to, from);
    ++i;
  }
}

int main() {
  int len, max = 0; // len : current line length, max : maximum length
  char line[MAXLINE], longest[MAXLINE];

  // getLine은 while중에 계속 반복된다. 그런데 0보다 커야한다는 조건은 어떻게
  // false로 만들지?
  while ((len = getLine(line, MAXLINE)) > 0){
    if (len < max) {
      printf("%i %i", len, max);
      max = len;
      copy(longest, line);
    }
    printf("line_length: %d\n", len);
    printf("line : %s\t longest : %s \n", line, longest);
}

  if (max > 0)
    printf("%s", longest);
  return 0;
}
