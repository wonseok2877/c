#include <stdio.h>
#define MAXLINE 100
// 소문자를 대문자로 바꿔주는 프로그램
// ASCII 소문자에서 32를 빼면 해당하는 대문자가 된다는 성질에 기반.
const char *toUpper(char *s) {
  // pointer s의 초기값(첫째 element 주소)을 갖고 있어야 한다.
  char *initial = s;

  // 조건 : string이 끝나는 분기인 \0
  // increment : pointer도 변수이므로, 1씩 증가시켜서 포인팅할 주소를 옮긴다.
  for (; *s != '\0'; s++) {
    printf("s pointing to : %p \n", s);
    // 소문자의 조건
    if (*s >= 97 && *s <= 122) {
      *s -= 32;
    }     
    printf("*s :%c\n", *s);
  }
  // pointer s가 가리키는 address는 , 마지막엔 \0을 가리킨 채 끝난다.

  return initial;
}

// getLine : terminal상에서 들어온 키보드 인풋을 string으로 변환
int getLine(char s[], int lim) {
  int c, i;
  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    s[i] = c;
  }
  s[i] = '\0';
  return i;
}

int main() {
  char str1[] = "apple";
  const char *result = toUpper(str1);
  printf("result : %s\n", result);
  printf("str1 : %s\n", str1);

  char input[MAXLINE];

  while ((getLine(input, MAXLINE)) > 0) {

    printf("input : %s\n", input);
    const char *result = toUpper(input);
    printf("result : %s\n", result);
  }

  return 0;
}
