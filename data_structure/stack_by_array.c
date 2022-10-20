#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 10

typedef int element;
element stack[MAX_STACK_SIZE];
int top = -1;

void push(element item) {
  if (top >= MAX_STACK_SIZE - 1) {
    fprintf(stderr, "stack overflow!\n");
    exit(1);
  } else
    // 1. top을 1 증가 (전위 연산)
    // 2. 해당 자리에 item 할당
    stack[++top] = item;
}

element pop() {
  if (top == -1) {
    fprintf(stderr, "stack underflow!\n");
    exit(1);
  } else
    // 1. top을 1 감소 (후위 연산)
    // 2. 삭제된 element 반환
    return stack[top--];
}

element peek() {
  if (top == -1) {
    fprintf(stderr, "stack underflow!");
    exit(1);

  } else
    return stack[top];
}

void printStack() {
  printf("STACK [ ");
  for (int i = 0; i <= top; i++)
    printf("%i ", stack[i]);
  printf("]  \n");
}

int main() {
  int item;
  for (int i = 0; i < 8; i++) {
    push(i);
    printStack();
  }

  printf("\npeek: top=%i\n", peek());
  printStack();

  printf("pop: top=%i\n", pop());
  printStack();
  printf("pop: top=%i\n", pop());
  printStack();
  printf("pop: top=%i\n", pop());
  printStack();
  printf("pop: top=%i\n", pop());
  printStack();
  printf("pop: top=%i\n", pop());
  printStack();
  printf("pop: top=%i\n", pop());
  printStack();
  printf("pop: top=%i\n", pop());
  printStack();
  printf("pop: top=%i\n", pop());
  printStack();
  printf("pop: top=%i\n", pop());
  printStack();
  printf("pop: top=%i\n", pop());
}
