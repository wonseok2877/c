#include <stdio.h>
#include <linux/sound.h>

int main(void) {
  int sum;
  sum = 50 + 25;
  printf("The sum is : %i\n %i\n", sum, sum);

  int my_octal = 077;
  int my_hexa = 0x77;
  printf("%i %i \n", my_octal, my_hexa);

  const char VTAB = '\013';
  const char BELL = '\007'; 
  printf("%c %c %c\n", VTAB, BELL, '\a');
  return 0;
}
