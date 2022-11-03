#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 20

typedef int element;
typedef struct {
element data[MAX_STACK_SIZE];
int top;
}Stack;

/* is_empty : 공백 상태*/
int is_empty(Stack *s) { return (s->top == -1); }

/* is_full : 포화 상태 검출*/
int is_full(Stack *s) { return (s->top == (MAX_STACK_SIZE - 1)); }

/* push
 * s : stack pointer
 * item : 삽입할 정수 데이터 */
void push(Stack *s, element item) {
  if (is_full(s)) {
    fprintf(stderr, "stack overflow!\n");
    exit(1);
  } else
    s->data[++(s->top)] =
        item; // top을 +1 한 후, stack의 해당 위치( 맨위)에 item 삽입
}

/* pop
 * s : stack pointer
 */
element pop(Stack *s) {
  if (is_empty(s)) {
    fprintf(stderr, "stack underflow!\n");
    exit(1);
  } else
    return s
        ->data[(s->top)--]; // stack의 맨위 위치 데이터를 반환한 후, top을 -1
}

int check_brackets(const char *expr){
    Stack s;
        s.top = -1;

    char ch, left_br;
    int length = strlen(expr);
    
    for (int i = 0; i < length; i++){
    ch = expr[i]; // i번째 문자
    switch (ch) {
        case '(':case '[': case '{': // 왼쪽 괄호인 경우 push
            push(&s, ch);
            break;
        case ')': case ']': case '}' : // 오른쪽 괄호인 경우
            if (is_empty(s) ){
            fprintf(stderr, "꽉 참");
            return 0;
            }else {
            left_br = pop(&s); // 해당하는 왼쪽 괄호를 pop
            if ( (left_br == ) )
            }
    }
    }
}

int main(){
Stack my_stack;
my_stack.top = -1;

}
