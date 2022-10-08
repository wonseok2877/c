#include <stdio.h>

int main(){
int a=1;
int *p = &a;
int **pp = &p;

// pp가 가리키는 값 또한 pointer이다.
printf("*p : %i\t p : %p\t *pp : %p\t pp : %p\n", *p, p, *pp,pp);
}
