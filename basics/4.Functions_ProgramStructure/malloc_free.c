#include <stdio.h>
#include <stdlib.h>

int main() {
  // sizeof를 쓰는 이유: 운영체제에 따라 int, float의 크기는 달라질 수 있기 때문
  // 7 미만을 썼을 때 에러가 생긴다. 
  int *arr = (int *)malloc(sizeof(int) * 7); // size 4 동적할당

  arr[0] = 100;
  arr[1] = 200;
  arr[2] = 300;
  arr[3] = 400;
  arr[4] = 500;
  arr[5] = 600;
  arr[6] = 700;

  printf("size=%lu\n", sizeof(arr));

  /* malloc
   * int type size의 4배만큼 memeory allocation 하고,
   * malloc의 디폴트 반환형이 void* 이므로 int *로 형변환 후 할당 
   * malloc은 단순히 메모리만 할당하는 함수이기 때문에 개발자가 어떠한 데이터 형을 저장하는지 예측할 수 없기 때문이다. */
  int *pArr = (int *)malloc(sizeof(int) * 8);

  if (pArr == NULL)
    printf("malloc error");

  for (int i = 0; i < 7; ++i) {
    pArr[i] = arr[i];
    printf("%i \n", pArr[i]);
  }

  /* free
   * allocate된 memory 해제 */

  free(arr);
  free(pArr);

  /* system("pause"); */

  char *c = (char *)malloc(sizeof(char)); // 1바이트 메모리 할당
  *c = 'h';
  printf("%p, %c\n", c, *c); // c의 주소값, c의 값 'h'
  free(c);                   //메모리 해제
                             
  int *a,i,n,sum = 0;

  printf("input an array size n : ");
  scanf("%d",&n);

  a=calloc(n, sizeof(int));

  for (i=0; i<n; ++i)
      scanf("%d", &a[i]);

  for (i=0; i<n; ++i)
      sum += a[i];

  free(a);

  printf("\n Number of elements : %7d \n Sum of elements : %7d\n\n", n,sum);

  return 0;
}
