#include <stdio.h>
#define ALLOCSIZE 10000 // size of available space

static char allocbuf[ALLOCSIZE]; // storage for alloc
static char *allocp = allocbuf;  // next free position

/*
 * return pointer to n characters*/
char *alloc(int n) {
  if (allocbuf + ALLOCSIZE - allocp >= n) {
    allocp += n;
    printf("n:%i\t allocp:%p\n", n, allocp);
    return allocp - n; // return old address
  } else               // not enough room
    return 0;
}

/*
 * free storage pointed to by p */
void afree(char *p) {
  if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
    allocp = p;
}

int main() {
alloc(10);
}
