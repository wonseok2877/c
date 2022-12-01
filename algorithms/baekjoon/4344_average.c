/*문제
대학생 새내기들의 90%는 자신이 반에서 평균은 넘는다고 생각한다. 당신은 그들에게
슬픈 진실을 알려줘야 한다.

입력
첫째 줄에는 테스트 케이스의 개수 C가 주어진다.

둘째 줄부터 각 테스트 케이스마다 학생의 수 N(1 ≤ N ≤ 1000, N은 정수)이 첫 수로
주어지고, 이어서 N명의 점수가 주어진다. 점수는 0보다 크거나 같고, 100보다 작거나
같은 정수이다.

출력
각 케이스마다 한 줄씩 평균을 넘는 학생들의 비율을 반올림하여 소수점 셋째
자리까지 출력한다.

문제접근
본질은 평균과 비교.
각 테스트케이스마다 평균을 산출하고, N명중의 몇명이 평균 초과인지를 float값으로
산출.

logic:
1. data:
int C, N, arr[N]
float average, rate
2. loop: for C
    3. loop: for N
    3-1. scanf arr[i]
    3-2. total 산출
    4. 평균값 산출
    5. loop: for N
    5-1. 평균값 초과인 원소들로 rate 산출
    6. printf rate

주의점:
반올림하여 소수점 셋째자리까지. float, double 써야함.
'%'도 출력해야 함.
*/
#include <stdio.h>

int main() {
  int C, N;
  scanf("%d", &C);

  // test case횟수만큼 반복
  while (C--) {
    scanf("%d", &N);
    // initialize
    double arr[N], average = 0, count = 0;

    // 각 학생들의 점수 배열, 평균값 산출
    for (int i = 0; i < N; i++) {
      scanf("%lf", &arr[i]);
      average += arr[i] / N;
    }

    // 평균을 초과한 학생 수
    for (int j = 0; j < N; j++)
      if (arr[j] > average) count++;

    // percent로 변환
    printf("%.3f%%\n", (count / N) * 100);
  }
  return 0;
}
