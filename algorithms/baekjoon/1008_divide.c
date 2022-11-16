#include <stdio.h>
#include <float.h>
/* 나눗셈
 * 입력 : 정수 A와 B (0 < A, B < 10)
 * 출력 : 첫째 줄에 A/B를 출력한다. 실제 정답과 출력값의 절대오차 또는 상대오차가 10-9 이하이면 정답
 *
 * 주의 : 나눗셈 결과값은 일단 float, double이어야 한다. 소수점 밑 자리까지 정확하게 표현해야 함.
 *        소수점 밑 9자리까지만 일치하면 된다.*/
int main1(){
    double a,b;
    scanf("%lf %lf", &a,&b);
    // printf("%.9f\n", a/b);
    // printf("%.17g\n", a/b);
    // .*e : maximum precision
    printf("%.*e\n",DECIMAL_DIG, a/b);
    return 0;
}

// 문제 조건에 가장 정확하게 부합한 코드!
void main(void)
{
    int A, B;
    scanf("%d %d", &A, &B);
    if (A>0 && B<10)
        printf("%.9lf", (double)A/B);
    
}
