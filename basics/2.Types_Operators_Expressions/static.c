#include <stdio.h>

// https://dojang.io/mod/page/view.php?id=690

void increaseNumber()
{
        printf("%d", num1);

    int num1 = 0;    // 변수 선언 및 값 초기화

    num1++;    // 변수의 값을 1씩 증가
    printf("%d\n", num1);    // 변수 num1의 값을 출력
}

static int num1 = 0;

void increaseStaticNumber()
{
    printf("%d", num1);
    static int num1 = 0;     // 정적 변수 선언 및 값 초기화
    
    num1++;    // 정적 변수 num1의 값을 1 증가시킴
    printf("%d\n", num1);    // 정적 변수 num1의 값을 출력
}



void increaseGlobalStaticNumber()
{
    num1++;    // 전역 정적 변수 num1의 값을 1 증가시킴
    printf("%d\n", num1);    // 전역 정적 변수 num1의 값을 출력
    /* 전역 변수는 정적 변수가 아니더라도 값이 계속 유지되지만 외부에서 사용할 수 있느냐 없느냐의 차이가 있습니다.
     * static으로 선언한 변수를 extern으로 사용하려고 하면 컴파일(링크) 에러가 발생합니다. 즉, 정적 전역 변수는 자신이 선언된 소스 파일 안에서만 사용할 수 있고, 외부에서는 가져다 쓸 수 없습니다. 즉, 전역 변수에 static을 붙이면 변수의 범위를 파일 범위로 제한하는 효과를 냅니다.*/
}

int main()
{
    printf("not static---------\n");
    increaseNumber();    // 0
    increaseNumber();    // 0
    increaseNumber();    // 0
    increaseNumber();    // 0: 변수가 매번 생성되고 사라지므로 0이 출력됨
    
    printf("static------------\n");
    increaseStaticNumber();    // 0
    increaseStaticNumber();   // 1
    increaseStaticNumber();    // 2
    increaseStaticNumber();    // 3: 정적 변수가 사라지지 않고 유지되므로 값이 계속 증가함

    printf("global static-------\n");
    increaseGlobalStaticNumber();
    increaseGlobalStaticNumber();
    increaseGlobalStaticNumber();
    increaseGlobalStaticNumber();

    return 0;
}
