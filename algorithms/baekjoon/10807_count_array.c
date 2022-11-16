#include <stdio.h>

/* 배열에서 원소 개수 찾기
 * 입력
 *      첫째 줄에 정수의 개수 N(1 ≤ N ≤ 100)이 주어진다.
 *      둘째 줄에는 정수가 공백으로 구분되어져있다.
 *      셋째 줄에는 찾으려고 하는 정수 v가 주어진다. 입력으로 주어지는 정수와
 * v는 -100보다 크거나 같으며, 100보다 작거나 같다. 출력 첫째 줄에 입력으로
 * 주어진 N개의 정수 중에 v가 몇 개인지 출력한다.
 *
 * 사고과정
 *
 * 데이터 : 입력 정수인 개수 N, 배열을 이룰 N개의 정수, 찾아야 할 정수 v
 *      정수들을 담을 배열 array (length = N)
 *      배열 속에 v가 몇개인지 카운팅할 정수 count
 * 1. scanf : N
 * 2. for (int i=0; i<N; i++) scanf("%i ", &array[i]);
 * 3. scanf("%i", &v);
 * 4. for (int i=0; i<N; i++) if(array[i] ==v ) count ++;
 * 5. printf("%i", count);
 * */

int main() {
  int N, array[100], V, count = 0;

  scanf("%d", &N);
  for (int i = 0; i < N; i++)
    scanf("%d ", &array[i]);
  scanf("%d", &V);

  for (int i = 0; i < N; i++) {
    if (array[i] == V)
      count++;
  }
  printf("%d", count);

  return 0;
}
