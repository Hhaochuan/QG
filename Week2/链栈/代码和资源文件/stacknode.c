#include <stdio.h>
#include <stdlib.h>
#include "stacknode.h"

/* 初始化栈 */
void init(Stack* s) {
    s->top = NULL;
}

/* 判断栈是否为空 */
int isEmpty(Stack s) {
    return (s.top == NULL);
}

/* 入栈 */
void push(Stack* s, int item) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    if (newNode == NULL) {
        printf("Error: Out of memory!\n");
        return;
    }
    newNode->data = item;
    newNode->next = s->top;
    s->top = newNode;
}

/* 出栈 */
int pop(Stack* s) {
    if (isEmpty(*s)) {
        printf("Error: Stack is empty!\n");
        return -1;  // 异常代码
    }
    StackNode* temp = s->top;
    int result = temp->data;
    s->top = temp->next;
    free(temp);
    return result;
}

/* 获取栈顶元素 */
int peek(Stack s) {
    if (isEmpty(s)) {
        printf("Error: Stack is empty!\n");
        return -1;  // 异常代码
    }
    return s.top->data;
}
