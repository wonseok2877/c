#include <stdio.h>

int main(){
int a=1;
int *p = &a;
int **pp = &p;

// pp가 가리키는 값 또한 pointer이다.
printf("*p : %i\t p : %p\t *pp : %p\t pp : %p\n", *p, p, *pp,pp);

int var = 10;
printf("var=%i\n", var);
int *ptr1 = &var;
*ptr1 = 20;
printf("var=%i\n", var);

int **ptr2 = &ptr1;
printf("&var=%p\t ptr1=%p\t &ptr1=%p\t ptr2=%p\n", &var, ptr1, &ptr1, ptr2);
**ptr2 = 30;
printf("var=%i\n", var);
*(*ptr2) = 40;
printf("var=%i\n", var);
}
