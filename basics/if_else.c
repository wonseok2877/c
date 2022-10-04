#include <stdio.h>
#include<stdbool.h>  

int main() {
  int a = 98, b = 'b';
  int biggest = 0;
  // simple boolean expression (conversion?)
  if (a)
    printf("true\n");
  if (b)
    printf("true\n");

  // indentation으로도 여러 nesting 알아먹네ㅋㅋ
  if (true)
    if (a > b)
      biggest = a;
    else if (b > a)
      biggest = b;
    else
      printf("same! \n");
  else
      printf("error! \n");

  printf("%i \n", biggest);
  return 0;
}
