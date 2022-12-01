/*
 * 입력
첫 줄에는 전체 사람의 수 N이 주어진다. 그리고 이어지는 N개의 줄에는 각 사람의
몸무게와 키를 나타내는 양의 정수 x와 y가 하나의 공백을 두고 각각 나타난다.

출력
여러분은 입력에 나열된 사람의 덩치 등수를 구해서 그 순서대로 첫 줄에 출력해야
한다. 단, 각 덩치 등수는 공백문자로 분리되어야 한다.

제한
2 ≤ N ≤ 50
10 ≤ x, y ≤ 200

문제접근
중요 포인트: 덩치 비교, 등수 저장.

data:
int N
struct Person {int x, int y, int rank}
array[N]

1. loop: N만큼
    2. loop: i-1 만큼
        2-1. 뒤의 원소들과 덩치 비교, 자신보다 큰 원소들의 수 count 저장.

*/

#include <stdio.h>

typedef struct {
  int x, y, rank;
} Person;

int main() {
  int N;
  Person arr[50];
  scanf("%d", &N);

  // 배열에 입력값(사람과 덩치) 저장
  for (int i = 0; i < N; i++) {

    int x, y, rank = 1;
    scanf("%i %i", &arr[i].x, &arr[i].y);
    arr[i].rank = 1;
  }

  // N만큼 반복. 원소들끼리 덩치 비교
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      // x가 작고 y도 작을 때 랭크 +1
      if (arr[i].x < arr[j].x && arr[i].y < arr[j].y)
        arr[i].rank++;
    }
    printf("%i ", arr[i].rank);
  }
}
