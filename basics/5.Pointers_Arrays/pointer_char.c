#include <stdio.h>

int main(){
/* string의 내부 동작원리
 * printf는 해당 character array의 1th element에 대한 pointer을 받는다.
 * 즉, string constant는 pointer을 통해 접근한다. */
printf("hello, world\n");

/* amessage : array의 이름이며, 변수가 아니다.
 * individual chaamessage will always refer to the same storage.
 * pmessage : pointer 변수이다. initialized to point to a string constant
 * the pointer may subsequently be modified to point elsewhere. */
char amessage[] = "now is the time";
char *pmessage = "now is the time";

// amessage = "now?";
pmessage = "now?";

printf("amessage : %s \n", amessage);
printf("pmessage : %s \n", pmessage);

}
