#include <stdio.h>
#include "stacknode.h"

int main() {
    Stack s;
    init(&s);

    // ��ջ
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);

    // ����ջ��Ԫ�ز���ջ
    while (!isEmpty(s)) {
        int top = peek(s);
        printf("%d ", top);
        pop(&s);
    }

    printf("\n");

    return 0;
}
