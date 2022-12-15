/*
 * 문제접근
 * 밑의 줄의 각 자릿수마다 곱하는게 포인트.
 * (3)= 472 * 5, (4)=  472 * 8, (5)= 472 * 3
 * 그리고 (6)= 472 * 385
 *
 * 밑의 줄 입력값을 각 자릿수별로 쪼개야 한다.
 * /, % 연산으로 해보자.
 * 385 / 100 = 3
 * 385 / 10 = 38, 38 % 10 = 8
 * 385 / 1 = 385, 385 % 10 = 5
 *
 * 1. 입력: int input1, input2
 * 2. first를 구하고, 곱한 값을 출력
 * 3. second
 * 4. third
 * 5. input1 * input2 를 출력
 * */
#include <stdio.h>

// 야매 pow 함수. 양의 정수 혹은 0만 연산 가능
int poww(int x,int y ){
    int result =1;
    if (y > 0)
        while (y--)
            result *= x;
    return result;
}

int main(){
    int input1,input2;
    scanf("%i %i", &input1, &input2);
    
    // pow(10, 자릿수-1)로 나눈 다음에 10으로 나눈 나머지.
    for (int i=0; i<3; i++){
        int operand = input2 / poww(10, i) % 10;
        printf("%i\n", input1 * operand);
    }
    
    printf("%i", input1 * input2);
}
