#include <stdio.h>

/* decompose : float의 각 int, frac part를 추출 
 * call by reference */ 
void decompose(float x, int *int_part, float *frac_part) {
// float을 int로 형변환. 이 과정에서 정수 파트만 남는다
  *int_part = (int)x;
  // float x - int x (정수파트) = 소수점 파트
  *frac_part = x - *int_part;
}

int main() {
  int i;
  float f;

  decompose(3.14159265359, i, f);

  printf("i=%i\t f=%f\n", i, f);
}
