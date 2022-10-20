#include <stdio.h>

#define MAX_DEGREE 101              // 다항식의 최대 차수 + 1
#define MAX(a, b) ((a > b) ? a : b) // 함수도 define 할 수 있네?

/* 첫번째 방법 : 모든 항을 차수 순서대로 array 저장. 
 * 1. 다항식 struct 선언. member : 차수(int), 계수(float array) */
struct Poly1 {
  int degree;             // 차수
  float coef[MAX_DEGREE]; // 계수
};

// typedef <type> <name>
typedef struct Poly1 polynomial;

/* addpoly1 : struct type인 polynomial_1을 2개 인자로 받음
 * 두 다항식을 더한 (polynomial_1 타입의) 값을 return */
polynomial add_poly(polynomial A, polynomial B) {
  polynomial C; // 더한 결과를 담을 다항식 struct 선언
  int Apos = 0, Bpos = 0, Cpos = 0; // 배열 index 선언
  int degree_a = A.degree,          // degree 복사
      degree_b = B.degree;
  // MAX : 결과 다항식의 차수
  C.degree = MAX(A.degree, B.degree);

  printf("Apos=%i\t Bpos=%i\t Cpos=%i\n", Apos, Bpos, Cpos);
          printf("A.coef[%i]=%f\t B.coef[%i]=%f\n",Apos, A.coef[Apos], Bpos, B.coef[Bpos]);
  printf("degree_a=%i\t degree_b=%i\n", degree_a, degree_b);

  int count = 0;
  /* loop : 배열 index가 두 다항식의 차수보다 작은동안 반복*/
  while (Apos <= A.degree && Bpos <= B.degree) {

    if (degree_a > degree_b) { // a쪽 항의 차수가 더 높을 때
      printf("\n<%i>-----------degree_a > degree_b--------\n", ++count);
      C.coef[Cpos++] = A.coef[Apos++];
      degree_a--;
    } else if (degree_a == degree_b) { // 차수가 같을 때
      printf("\n<%i>-----------degree_a == degree_b--------\n", ++count);
      C.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++];
      degree_a--;
      degree_b--;
    } else { // b쪽 항의 차수가 더 높을 때
      printf("\n<%i>-----------degree_a < degree_b---------\n", ++count);
      C.coef[Cpos++] = B.coef[Bpos++];
      degree_b--;
    }
        printf("--> C.coef[%i] = %f\n",count-1 , C.coef[Cpos - 1]);
    printf("Apos=%i\t Bpos=%i\t Cpos=%i\n", Apos, Bpos, Cpos);
    printf("A.coef[%i]=%f\t B.coef[%i]=%f\n",Apos, A.coef[Apos], Bpos, B.coef[Bpos]);
    printf("degree_a=%i\t degree_b=%i\n", degree_a, degree_b);
  }
  return C;
}

struct {
    float coef;
    int expon;
}terms[MAX_DEGREE] = { {10,5}, {6,1}, {3,0} };

int main() {
  polynomial a = {7, {1,2,3, 6, 0, 0, 0, 10}};
  polynomial b = {4, {7, 0, 5, 0, 1}};

  polynomial c;
  c = add_poly(a, b);

  printf("%lu %lu %lu\n", sizeof c.coef, sizeof c.coef[0],
         sizeof c.coef / sizeof c.coef[0]);
  for (int i = 0; i < 6; i++)
    printf("%f\n", c.coef[i]);
}
