#include <stdio.h>

/*  * https://blog.naver.com/PostView.nhn?isHttpsRedirect=true&blogId=sharonichoya&logNo=220495444611*/

struct S1 {
  char a;
  int b;
} s1 = {'a', 1};

struct S2 {
  char a;
  char b;
  int c;
} s2 = {'a', 'b', 10};

struct S3 {
  char a;
  int c;
  char b;
} s3 = {'a', 10, 'b'};

int main() {

  printf("%lu %lu \t 메모리 크기 = %lu\n", sizeof s1.a, sizeof s1.b,
         sizeof(s1)); // 8
  printf("%lu %lu %lu \t 메모리 크기 = %lu\n", sizeof s2.a, sizeof s2.b,
         sizeof s2.c, sizeof s2); // 8
  printf("%lu %lu %lu \t 메모리 크기 = %lu\n", sizeof s3.a, sizeof s3.b,
         sizeof s3.c, sizeof s3); // 12
}
