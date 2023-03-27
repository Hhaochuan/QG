#include "stack.h"
#include <stdlib.h>

// ��ʼ��ջ
void init(Stack* s) {
    s->top = NULL;
    s->size = 0;
}

// �ж�ջ�Ƿ�Ϊ��
bool isEmpty(Stack* s) {
    return s->top == NULL;
}

// ��ջ
void push(Stack* s, int x) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = s->top;
    s->top = newNode;
    s->size++;
}

// ����ջ��Ԫ�ز�������ֵ
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

// ����ջ��Ԫ�ص�ֵ��������
int top(Stack* s) {
    if (isEmpty(s)) {
        exit(EXIT_FAILURE);
    }
    return s->top->data;
}
