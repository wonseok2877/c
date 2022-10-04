#include <stdio.h>

/* count digits, white space, others */
void main() {
  int c, i, nwhite, nother;
  int ndigit[10];
  int myLength = 5;
  int myArray[myLength];

   for (i = 0; i < myLength; ++i){
    myArray[i] = i;
    printf("%p \n", &myArray[i]);
   }

  nwhite = nother = 0;

  // for : initialize ndigit's elements as 0
  for (i = 0; i < 10; ++i)
    ndigit[i] = 0;

  while ((c=getchar()) != EOF)
    if (c >= '0' && c <= '9')
      ++ndigit[c];
    else if (c == ' ' || c == '\n' || c == '\t')
      ++nwhite;
    else
      ++nother;

  printf("digits=");
  for (i=0; i<10; ++i)
      printf(" %d", ndigit[i]);
  printf(", white space = %d, other = %d\n", nwhite, nother);
}
