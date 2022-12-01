/*
 * 임스는 기프티콘을 아껴 사용하기 위해 유효기간이 90일 이하로 남은 기프티콘만 사용할 것이다.

하트 곰곰

입력
첫 번째 줄에는 임스가 받은 기프티콘의 개수 정수 $N$이 주어진다. ($1 \le N \le 1\,000$)

두 번째 줄부터 $N$개의 줄에 걸쳐 $i$번째 기프티콘의 남은 유효기간 $x_i$가 D-xi 와 같은 형식으로 주어진다. ($1 \le x_i \le 365$)

출력
임스가 사용할 기프티콘의 개수를 출력하시오.

문제접근
90비교연산, count 증가 연산이 전부다.
data:
int N, input, count
1. loop: N만큼 반복. 
    1-1. scanf input
    1-2. if 90보다 작거나 같음: count ++
    1-3. printf count
*/

#include <stdio.h>

int main(){
    int N, count=0;
    scanf("%i", &N);
    
    while (N--){
        int input;
        scanf("%*c%*c%*c%i", &input);
        if (input <=90) count++;
    }
    printf("%i", count);
}
