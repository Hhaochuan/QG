#ifndef _STACKNODE_H
#define _STACKNODE_H

typedef struct stacknode {
    int data;
    struct stacknode* next;
} StackNode;

typedef struct {
    StackNode* top;
} Stack;

void init(Stack* s);
int isEmpty(Stack s);
void push(Stack* s, int item);
int pop(Stack* s);
int peek(Stack s);

#endif /* _STACKNODE_H */
