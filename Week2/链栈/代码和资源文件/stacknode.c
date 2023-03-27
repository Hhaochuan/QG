#include <stdio.h>
#include <stdlib.h>
#include "stacknode.h"

/* ��ʼ��ջ */
void init(Stack* s) {
    s->top = NULL;
}

/* �ж�ջ�Ƿ�Ϊ�� */
int isEmpty(Stack s) {
    return (s.top == NULL);
}

/* ��ջ */
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

/* ��ջ */
int pop(Stack* s) {
    if (isEmpty(*s)) {
        printf("Error: Stack is empty!\n");
        return -1;  // �쳣����
    }
    StackNode* temp = s->top;
    int result = temp->data;
    s->top = temp->next;
    free(temp);
    return result;
}

/* ��ȡջ��Ԫ�� */
int peek(Stack s) {
    if (isEmpty(s)) {
        printf("Error: Stack is empty!\n");
        return -1;  // �쳣����
    }
    return s.top->data;
}
