#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct {
    Node* top;
    int size;
} Stack;

void init(Stack* s);
bool isEmpty(Stack* s);
void push(Stack* s, int x);
int pop(Stack* s);
int top(Stack* s);

#endif

