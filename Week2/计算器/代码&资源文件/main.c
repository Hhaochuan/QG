#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "stack.h"

// 判断是否为操作符
bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

// 比较操作符优先级，返回-1、0或1
int comparePrecedence(char op1, char op2) {
    if ((op1 == '*' || op1 == '/') && (op2 == '+' || op2 == '-')) {
        return -1;
    }
    else if ((op1 == '+' || op1 == '-') && (op2 == '*' || op2 == '/')) {
        return 1;
    }
    else {
        return 0;
    }
}

// 计算表达式的值
int evaluateExpression(char* expr) {
    Stack operandStack;
    Stack operatorStack;
    init(&operandStack);
    init(&operatorStack);

    // 遍历表达式中的每个字符
    for (int i = 0; expr[i] != '\0'; i++) {
        if (isspace(expr[i])) {
            continue;
        }
        if (isdigit(expr[i])) {
            int num = 0;
            while (isdigit(expr[i])) {
                num = num * 10 + (expr[i] - '0');
                i++;
            }
            i--;
            push(&operandStack, num);
        }
        else if (expr[i] == '(') {
            push(&operatorStack, '(');
        }
        else if (expr[i] == ')') {
            while (top(&operatorStack) != '(') {
                char op = pop(&operatorStack);
                int operand2 = pop(&operandStack);
                int operand1 = pop(&operandStack);
                if (op == '+') {
                    push(&operandStack, operand1 + operand2);
                }
                else if (op == '-') {
                    push(&operandStack, operand1 - operand2);
                }
                else if (op == '*') {
                    push(&operandStack, operand1 * operand2);
                }
                else if (op == '/') {
                    push(&operandStack, operand1 / operand2);
                }
            }
            pop(&operatorStack);
        }
        else if (isOperator(expr[i])) {
            while (!isEmpty(&operatorStack) &&
                top(&operatorStack) != '(' &&
                comparePrecedence(top(&operatorStack), expr[i]) >= 0) {
                char op = pop(&operatorStack);
                int operand2 = pop(&operandStack);
                int operand1 = pop(&operandStack);
                if (op == '+') {
                    push(&operandStack, operand1 + operand2);
                }
                else if (op == '-') {
                    push(&operandStack, operand1 - operand2);
                }
                else if (op == '*') {
                    push(&operandStack, operand1 * operand2);
                }
                else if (op == '/') {
                    push(&operandStack, operand1 / operand2);
                }
            }
            push(&operatorStack, expr[i]);
        }
    }

    // 处理剩余的操作符
    while (!isEmpty(&operatorStack)) {
        char op = pop(&operatorStack);
        int operand2 = pop(&operandStack);
        int operand1 = pop(&operandStack);
        if (op == '+') {
            push(&operandStack, operand1 + operand2);
        }
        else if (op == '-') {
            push(&operandStack, operand1 - operand2);
        }
        else if (op == '*') {
            push(&operandStack, operand1 * operand2);
        }
        else if (op == '/') {
            push(&operandStack, operand1 / operand2);
        }
    }
    int result = pop(&operandStack);
    return result;
}

int main() {
    char expr[100];
    printf("Enter an expression: ");
    fgets(expr, 100, stdin);
    printf("Result = %d\n", evaluateExpression(expr));
    return 0;
}
