/* 최소, 최대
 *
문제
N개의 정수가 주어진다. 이때, 최솟값과 최댓값을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 정수의 개수 N (1 ≤ N ≤ 1,000,000)이 주어진다. 둘째 줄에는 N개의 정수를
공백으로 구분해서 주어진다. 모든 정수는 -1,000,000보다 크거나 같고,
1,000,000보다 작거나 같은 정수이다.

출력
첫째 줄에 주어진 정수 N개의 최솟값과 최댓값을 공백으로 구분해 출력한다.

접근방식
데이터 : 정수의 개수 N, 둘째줄의 정수들을 담을 배열 array[N], 최종 최솟값과
최댓값을 담을 정수 min, max array가 필요 없다! 저장해서 쓰일 곳이 min, max인데
매번 비교하고 할당하거나 아예 안 쓰니까.
1. scanf를 통해 N과 정수들을 입력, 할당
2. 초기의 min, max의 값은 없기 때문에 (0), 맨 처음의 입력값을 무조건적으로 할당.
3. 반복문. 계속해서 최솟값, 최댓값과 현재 입력값을 비교해서 최소, 최대인 경우에
새로 할당.
4. printf(min, max)

주의점 : 정수의 범위를 한번 생각해봐야 할듯. int는 4byte로, 2의 32승까지 나타낼
수 있다. sign bit 때문에 2의 31승. 이는 문제의 조건을 충족한다.

수정 : min, max의 초기값을 주는게 더 깔끔하고 안정적이다. 
문제의 조건에 따라 min에는 일단 가장 큰 값, max에는 가장 작은 값을 할당. 
*/

#include <stdio.h>

int main2() {
  // 변수 정의
  int N, array[N], min, max;

  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &array[i]);
  }
  // 초창기에는 min, max가 없으므로 첫 요소를 무조건 할당
  min = max = array[0];
  for (int i = 0; i < N; i++) {
    if (array[i] > max)
      max = array[i];
    else if (array[i] < min)
      min = array[i];
  }

  printf("\n%d %d\n", min, max);
  return 0;
}

int main() {
  // 변수 정의
      // 초창기에는 min, max가 없으므로 무조건적으로 할당
  int N, input, min=10000001, max= -10000001;

  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &input);

    if (input > max)
      max = input;
    else if (input < min)
      min = input;
  }

  printf("%d %d", min, max);
}
