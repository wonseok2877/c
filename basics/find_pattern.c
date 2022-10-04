#include <stdio.h>
#define MAXLINE 1000

// ?... 이거 뭐하는 함수인지 감이 안오네

char pattern[] = "ould";

// getline : get line into s, return length
int get_line(char s[], int lim) {
  int c, i = 0;

  // lim이 0보다 크고, getchar string이 끝나지 않고, c가 \n이 아닌 한 반복
  while (--lim > 0 && (c = getchar()) != EOF && c != '\n') {
    // s[i]에 c 할당 그리고 i 1 증가
    s[i++] = c;
  }
  if (c == '\n')
    s[i++] = c;

  printf("\nend of get_line\n");
  return i;
}

// strindex : return index of t in s, -1 if none
int strindex(char s[], char t[]) {
  printf("===strindex\n");
  int i, j, k;
    printf("s : %s\n t : %s\n", s, t);
  // s[i]가 \0, 즉 s string의 끝까지 반복
  for (i = 0; s[i] != '\0'; i++) {
    // t는 여기선 pattern "ould". t[k]가 끝나지 않고, s[j]와 t[k]가 같지 않은 한
    // 반복.)
    for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++) {
      printf("k : %i\t j : %i\t t[k] : %c\t s[j] : %c\n", k, j, t[k], s[j]);
    }
    if (k > 0 && t[k] == '\0'){
        printf("\n end of strindex. i : %i\n", i);
        return i;
    }
  }

  return -1; // none
}

// find all lines matching pattern
int main() {
  char line[MAXLINE];
  int found = 0;

  printf("pattern : %s\n", pattern);

  while (get_line(line, MAXLINE) > 0) {
      // ? while문이 안 끝난다. 그래서 found++도 동작 안 하는듯. 한번만 동작하거나. 
    if (strindex(line, pattern) >= 0) {
      found++;
    }
  }

  printf("\nend of main\n");
  printf("================found : %i=============\n",  found);
  return found;
}

/* input : Ah Love! could you and I with Fate conspire To grasp this sorry Scheme of Things entire, Would not we shatter it to bits -- and then Re-mould it nearer to the Heart's Desire! */
