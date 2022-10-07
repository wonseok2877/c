#include <stdio.h>

/* printd : print n in decimal */
void printd(int n) {

  if (n < 0) {
      // putchar(int char) : printf character 버전. 
      // writes a character (an unsigned char) specified by the argument char to stdout.
    putchar('-');
    n = -n;
  } else if (n / 10) {
    // recursive call
    printd(n / 10);
  }
  putchar(n % 10 + '0');
}

/* qsort : sort v[left]...v[right]*/

int main() { printd(123456); }
