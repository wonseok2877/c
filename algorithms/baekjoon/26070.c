/*
 * 식당에서는 치킨 식권 3장을 피자 식권 1장으로, 피자 식권 3장을 햄버거 식권
1장으로, 햄버거 식권 3장을 치킨 식권 1장으로 교환해주는 이벤트도 하고 있다.

입력
첫 번째 줄에 치킨을 먹고 싶은 곰곰이의 마릿수 $A$, 피자를 먹고 싶은 곰곰이의
마릿수 $B$, 햄버거를 먹고 싶은 곰곰이의 마릿수 $C$가 공백으로 구분되어 주어진다.
$(0\le A,B,C\le 10^{9})$ 

두 번째 줄에 총총이가 가지고 있는 치킨 식권 장수 $X$, 피자 식권 장수 $Y$, 햄버거
식권 장수 $Z$가 공백으로 구분되어 주어진다. $(0\le X,Y,Z\le 10^{9})$ 

입력은 모두 정수로 주어진다.

출력
주어진 식권과 이벤트를 적절히 활용해, 배불리 먹일 수 있는 곰곰이의 최대 마릿수를
출력하자.
*/

/*
# 문제접근
교환비가 중요.
일단 교환을 안 하고 다 먹일 때가 가장 최대로 먹일 수 있다.
1차적으로 다 먹인 다음, 가장 많이 남은 티켓부터 시작해서 다른 티켓으로
교환하면서 먹인다. 2차적으로 먹인 다음, 다음 티켓. 3차에서 끝낸다. 데이터: int
A,B,C,X,Y,Z, all 혹은.. 배열로 해볼까? 아니다. 마지막 index에서 첫번째 index 갈
때가 문제. %연산자를 쓰면 되긴 하겠지만..

1. scanf: 마릿수, 식권 장수. 마릿수 3종류를 all에 더한다. 나중의 출력 용도
2. 1차적으로 마릿수 A,B,C에서 식권 장수만큼 뺀다. 식권 장수 또한 마릿수만큼
뺀다.
3. X,Y,Z 중에서 가장 큰 값을 찾는다.
4. 가장 큰 값을 다음 식권 장수로 교환, 2차 실행
5. 그 다음 식권으로 교환 시도, 3차 실행

배운 점

*/
#include <stdio.h>

// max: int 배열에서 최댓값을 갖는 index 반환
int max(long long arr[], int length) {
  int top = -1, indx;
  while (length--)
    if (arr[length] > top) {
      top = arr[length];
      indx = length;
    }

  return indx;
}

int main() {
  long long  gomgom[3], ticket[3], total = 0;
  scanf("%lld %lld %lld", &gomgom[0], &gomgom[1], &gomgom[2]);
  scanf("%lld %lld %lld", &ticket[0], &ticket[1], &ticket[2]);

  for (int i = 0; i < 3; i++) {
    // 배식
    for (int j = 0; j < 3; j++) {
      int ate;
      // 수요가 많은 경우, 공급이 많은 경우 나눠서 생각
      if (gomgom[j] >= ticket[j])
        ate = ticket[j];
      else
        ate = gomgom[j];

      ticket[j] -= ate;
      gomgom[j] -= ate;
      total += ate;
    }

    // 티켓 교환
    int mdx = max(ticket, 3);
    ticket[(mdx + 1) % 3] += ticket[mdx] / 3;
    ticket[mdx] = ticket[mdx] % 3;
  }
  printf("%lld", total);
}
