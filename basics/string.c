#include <stdio.h>
#include <string.h>


int main(){
    // 문자 : ASCII 코드값(16진수, 10진수) 혹은 단일 문자 할당
    // char은 1바이트 크기이기 때문에 ASCII 문자 외의 문자 혹은 2개 이상의 문자를 할당할 수 없다.
    char c1='a';
    char c2=98;
    char c3=0x63;
    /* char c4='ㄱ'; 
     * Character too large for enclosing character literal type */

    
    // char은 character, decimal, 16진수 형태로 모두 취급 가능
    printf("%c, %d, 0x%x\n", c1, c1, c1);    
    printf("%c, %d, 0x%x\n", c2, c2, c2);    
    printf("%c, %d, 0x%x\n", c3, c3, c3);     

    // pointer을 이용해서 문자열 저장가능. 
    // pointer은 메모리 주소를 저장하는 변수이기 때문.
    char *c5="abc";
    printf("%s\n", c5);

    // 문자열 : 문자로 이루어진 array 생성
    char str1[20] = "applebananacoconut";
    char str2[10];
    char str3[10] = "applE";
    int result;

    //strcpy : copy string
    strcpy(str2, str1);    
    printf("copy str1 to str2 : %s\n", str2);
    
    //strcmp : compare string
    result = strcmp(str1,str2);
    printf("strcmp(str1, str2) = %d\n", result);

    result = strcmp(str2,str3);
    printf("strcmp(str1, str3) = %d\n", result);

    // strncmp : compare string with certain length (3rd parameter)
    result = strncmp(str2,str3, 4);
    printf("strcmp(str1, str3) = %d\n", result);
    
    //strcat : catenates strings
    strcat(str1, str2);
    printf("strcat str1 str2 = %s\n", str1);

    //strlen : length of a string
    printf("length of str1 now = %zu\n", strlen(str1));
    
    return 0;
}
