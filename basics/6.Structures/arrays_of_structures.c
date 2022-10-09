#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAXWORD 100

// TODO ch4 external variables 하고 난 다음에 돌아오자. getch, ungetch. + binsearch

struct key {
  char *word;
  int count;
} keytab[] = {{"auto", 0},
              {"break", 0},
              {"case", 0},
              {"char", 0},
              {"const", 0},
              {"continue", 0},
              {"default", 0},
              // ....
              {"unsigned", 0},
              {"while", 0}};

/* getword : get next word or character from input */

/* binsearch : find word in tab[0]...tab[n-1] */
int binsearch(char *word, struct key keytab[], int n) {
  int cond;

  int low = 0, high = n - 1;
  while (low <= high) {
    int mid = (low + high) / 2;
    if ((cond = strcmp(word, keytab[mid].word)) < 0)
      high = mid - 1;
    else if (cond > 0)
      low = mid + 1;
    else
      return mid;
  }
  return -1;
}

/* count C keywords */
int main(){
int n;
char word[MAXWORD];
}
