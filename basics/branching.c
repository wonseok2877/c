#include <stdio.h>

void ternary(){
  float a = getchar();
  int b = 'g';
  printf("a: %f b: %i \n" , a,b);
  int c = (a > b) ? a : b; // paranthesis로 가독성 올리기.

  printf("%i \n", c);

  a<b ? printf("b is bigger\n") : printf("a is bigger\n");

}
int main() {

    ternary();

  return 0;
}
