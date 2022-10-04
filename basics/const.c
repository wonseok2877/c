#include <stdio.h>
#define loooong 123456789L

int main() {
  const int a = 1;
  printf("%d", a);
  printf("%li\n", loooong);

  const double e = 2.7182818;
  char msg_1[] = "Warning : ";

  msg_1[8] = '=';
  const char msg_2[] = "Warning : ";
  /* msg_2[8] = '='; */ // error : const array는 element를 바꿀 수 없다.

  printf("%s\n", msg_1);
}

// 여기서 s[]의 각 element는 바뀔 수 없음.
int str_len(const char s[]) {
  printf("%s\n", s);
  int i = 0;
  /* s[i] = 'a'; */
  while (s[i] != '\0')
    ++i;
  return i;
}
