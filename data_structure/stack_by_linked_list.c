#include <stdio.h>
#include <stdlib.h>

typedef int element;
// linked list
typedef struct StackNode{
element item;
struct StackNode *link;
}SNode;

typedef struct {
    struct StackNode *top;
}LinkedStackType;

void push(LinkedStackType *s, element item){
Node *temp = (Node *)malloc(sizeof(Node));
}
