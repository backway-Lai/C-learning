栈 后缀表达式计算

请使用已定义好的栈完成后缀表达式计算：
(1)如果是操作数，直接入栈
(2)如果是操作符op，连续出栈两次，得到操作数x 和 y, 计算 x op y，并将结果入栈。

后缀表达式示例如下：
9  3  1 - 3 * +10  2 / +
13  445 + 51 / 6 -
操作数、操作符之间由空格隔开，操作符有 + ， - ，*, / , % 共 5 种符号，所有操作数都为整型。

栈的定义如下：

#define Stack_Size 50
typedef struct {
    ElemType elem[Stack_Size];
    int top;
}Stack;

bool push(Stack* S, ElemType x);
bool pop(Stack* S, ElemType* x);
void init_stack(Stack* S);
其中，栈初始化的实现为：

void init_stack(Stack* S) {
    S->top = -1;
}
需要完成的函数定义为：int compute_reverse_polish_notation(char* str);

函数接收一个字符指针，该指针指向一个字符串形式的后缀表达式，函数返回该表达式的计算结果。

#include <stdio.h>
#include <stdlib.h>
#include "list.h" // 请不要删除，否则检查不通过

int compute_reverse_polish_notation(char* str) {
    Stack stack;
    init_stack(&stack);
    char* p = str;

    while (*p != '\0') {
        while (*p == ' ') p++;
        if (*p == '\0') break;


        if (*p == '+' || *p == '-' || *p == '*' || *p == '/' || *p == '%') {
            char op = *p++;
            ElemType left, right, result;

            pop(&stack, &right);
            pop(&stack, &left);

            switch (op) {
            case '+':
                result = left + right;
                break;
            case '-':
                result = left - right;
                break;
            case '*':
                result = left * right;
                break;
            case '/':
                result = left / right;
                break;
            case '%':
                result = left % right;
                break;
            }
            push(&stack, result);
        }
        else {
            int num = 0;
            while (*p >= '0' && *p <= '9') {
                num = num * 10 + (*p - '0');
                p++;
            }
            push(&stack, (ElemType)num);
        }
    }

    ElemType ans;
    pop(&stack, &ans);
    return (int)ans;
}