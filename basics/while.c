#include <ctype.h>
#include <stdio.h>
#include <string.h>

// atoi : convert s to integer
int atoi(char s[]) {
  int i, n, sign;

  for (i = 0; isspace(s[i]); i++) // skip white space
    ;

  sign = (s[i] == '-') ? -1 : 1;
  printf("sign : %i\n", sign);

  if (s[i] == '+' || s[i] == '-') {
    i++;
    printf("i : %i s[i] : %c\n", i, s[i]);
  }

  for (n = 0; isdigit(s[i]); i++)
    n = 10 * n + (s[i] - '0');

  return sign * n;
}

void reverse(char s[]) {
  int c, i, j;

  for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
   c = s[i], s[i] = s[j], s[j] = c;

    printf("s[i]:%c s[j] : %c \n", s[i], s[j]);
  }

  printf("%s\n", s);
}

void fahr_cels() {
  float fahr, celsius;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  fahr = lower;

  /* if an arithmetic operator has one floating point operand and one integer
   * operand, the integer will be converted to floating poing before the
   * operation is done.*/
  printf("=======while========\n");
  while (fahr <= upper) {
    /* in float type, 5.0/9.0 is not truncated. */
    celsius = (5.0 / 9.0) * (fahr - 32);
    printf("%3.0f\t%6.1f\n", fahr, celsius);
    fahr = fahr + step;
  }
  // for문의 expr 1,2,3을 꼭 다 채울 필요 없음!
  printf("=======for========\n");
  for (fahr = lower; fahr <= upper; fahr += step) {
    celsius = (5.0 / 9.0) * (fahr - 32);
    printf("%3.0f\t%6.1f\n", fahr, celsius);

    // break
    if (fahr == 180)
      break;
  }
}

int main() {
  char mystr[] = "hello~ i'm from korea~";
  reverse(mystr);
}
