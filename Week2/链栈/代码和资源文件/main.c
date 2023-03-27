#include <stdio.h>
#include "stacknode.h"

int main() {
    Stack s;
    init(&s);

    // 入栈
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);

    // 访问栈顶元素并出栈
    while (!isEmpty(s)) {
        int top = peek(s);
        printf("%d ", top);
        pop(&s);
    }

    printf("\n");

    return 0;
}
