#include "stack.h"
#include <stdlib.h>

// 初始化栈
void init(Stack* s) {
    s->top = NULL;
    s->size = 0;
}

// 判断栈是否为空
bool isEmpty(Stack* s) {
    return s->top == NULL;
}

// 入栈
void push(Stack* s, int x) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = s->top;
    s->top = newNode;
    s->size++;
}

// 弹出栈顶元素并返回其值
int pop(Stack* s) {
    if (isEmpty(s)) {
        exit(EXIT_FAILURE);
    }
    int value = s->top->data;
    Node* temp = s->top;
    s->top = s->top->next;
    free(temp);
    s->size--;
    return value;
}

// 返回栈顶元素的值但不弹出
int top(Stack* s) {
    if (isEmpty(s)) {
        exit(EXIT_FAILURE);
    }
    return s->top->data;
}
