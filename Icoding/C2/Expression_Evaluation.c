//表达式求值（Expression Evaluation）
//
//编写程序对表达式求值。
//
//Enter an expression : 1 + 2.5 * 3
//Value of expression : 10.5
//
//
//表达式中的操作数是浮点数，运算符是 + 、 - 、 * 和 / 。表达式从左向右求值（所有运算符的优先级都⼀样）。
//
//
//输出范例：
//
//
//Enter an expression : 2 + 3 * 4 - 5 / 2
//Value of expression : 7.5

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(){
	float a, b;
	char c;

	printf("Enter an expression:\n");

	scanf("%f", &a);
	while (1) {
		c = getchar();
		if (c == '\n') break;
		scanf("%f", &b);
		switch (c) {
		case '+':
			a = a + b;
			break;
		case '-':
			a = a - b;
			break;
		case '*':
			a = a * b;
			break;
		case '/':
			a = a / b;
			break;
		}
	}
	printf("Value of the expression:%.1f\n", a);
	return 0;
}