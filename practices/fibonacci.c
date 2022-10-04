// written by WONSEOK LEE 17007149, USW C LANGUAGE CLASS
// ON 04TH OCTOBER 2022 22:18

#include <stdio.h>

int fibonacci(int n) {
  // initialize first and second terms
  int t1 = 0, t2 = 1;

  // initialize the next term (3rd term)
  int nextTerm = t1 + t2;

  // print the first two terms t1 and t2
  printf("Fibonacci Series: %d %d ", t1, t2);

  // print 3rd to nth terms
  for (int i = 3; i <= n; ++i) {
    printf("%d ", nextTerm);
    t1 = t2;
    t2 = nextTerm;
    nextTerm = t1 + t2;

    if (i==n)
        printf("\n");
  }

  return nextTerm;
}

int main() {
  fibonacci(10);
}
