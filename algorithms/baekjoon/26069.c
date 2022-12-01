/*무지개 댄스를 추지 않고 있던 사람이 무지개 댄스를 추고 있던 사람을 만나게
된다면, 만난 시점 이후로 무지개 댄스를 추게 된다.

기록이 시작되기 이전 무지개 댄스를 추고 있는 사람은 총총이 뿐이라고 할 때,
마지막 기록 이후 무지개 댄스를 추는 사람이 몇 명인지 구해보자!

입력
첫번째 줄에는 사람들이 만난 기록의 수 $N\ (1 \le N \le 1\ 000)$이 주어진다.

두번째 줄부터 $N$개의 줄에 걸쳐 사람들이 만난 기록이 주어진다. $i + 1$번째
줄에는 $i$번째로 만난 사람들의 이름 $A_i$와 $B_i$가 공백을 사이에 두고 주어진다.
$A_i$와 $B_i$는 숫자와 영문 대소문자로 이루어진 최대 길이 $20$의 문자열이며,
서로 같지 않다.

총총이의 이름은 ChongChong으로 주어지며, 기록에서 1회 이상 주어진다.

동명이인은 없으며, 사람의 이름은 대소문자를 구분한다. (ChongChong과 chongchong은
다른 이름이다.)

출력
마지막 기록 이후 무지개 댄스를 추는 사람의 수를 출력하라.*/

/*
문제접근
배열을 쓰자. 지금까지 총총이 혹은 전염자를 만난 사람들을 저장하기 위함.
탐색하는 로직을 만들자.
만약 춤추는중인 사람을 만났다면, 배열에 삽입.
그런데 그 사람 또한 춤추는중이라면, 무시.
배열은 총총이가 들어가있는 상태로 initialize

data:
int N, 배열의 길이 sizeof(people) / sizeof(people[0])
char* people[1000], input1, input2

1. loop: N만큼 반복.
    1-1. 입력: input1, input2
    1-2. loop: 배열에 input1, input2가 있는지 탐색.
    1-3. if 둘중 한명만 춤추는중: 나머지 한명을 배열에 삽입.
    1-4. if 아무도 춤추지 않거나 둘 다 춤추는중: pass
2. printf: 배열의 길이


문제점
- 반복문의 3번째부터, 원래 있던 이전의 원소들 값이 바뀌었다.
이상한건, 삽입 로직 이전에 바뀌어있다는 점.

string array 기본기를 모르고 있었음!
char *arr[20]은 string이 아닌 char pointer가 20개 있는 배열...
-> char arr[20][70]으로 해야 길이 70인 string을 담는 배열이 된다.
https://stackoverflow.com/questions/7251307/using-strcpy-with-a-string-array-in-c

- c 언어 string의 특성 : 맨 끝에 \0 이 들어갈 자리를 줘야 함.
비교를 위해 strcmp, 복사를 위해 strcpy를 썼어야 함.
*/
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int main() {
  // data
  int N, count = 1;
  scanf("%i", &N);
  char people[1000][21] = {"ChongChong"};

  for (int i = 0; i < N; i++) {
    // 각각의 사람 데이터
    char x[21], y[21];
    bool is_x = false, is_y = false;
    scanf("%s %s", x, y);

    // 배열상에 x, y가 있는지 탐색
    for (int j = 0; j < count; j++) {
      // x가 이미 춤추고 있을 경우
      if (strcmp(people[j], x) == 0)
        is_x = true;
      // y가 이미 춤추고 있을 경우
      else if (strcmp(people[j], y) == 0)
        is_y = true;
    }

    // 분기처리. 둘중 한명만 춤추는 경우 해당 인원 삽입
    if (is_x && is_y) continue;
    else if (is_x)
      strcpy(people[count++], y);
    else if (is_y)
      strcpy(people[count++], x);

    /*  printf("[ "); */
    /* for (int j = 0; j < count; j++) printf("%s ", people[j]); */
    /* printf("]\n"); */
  }
  printf("%i", count);
}
