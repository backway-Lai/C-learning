//出现次数（Number Occurrences）
//
//修改如下程序，使其打印⼀份列表，显示出每个数字在数中出现的次数。
//
//输出范例：
//
//Enter a number : 41271092
//
//Digit : 0	1	2	3	4	5	6	7	8	9
//Occurrences : 1	2	2	0	1	0	0	1	0	

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int num[10] = { 0 };

	char c;
	printf("Enter a number:\n");

	while (1) {
		c = getchar();
		if (c == '\n') break;
		num[c - '0']++;
	}
	printf("Digit : 0	1	2	3	4	5	6	7	8	9\n");
	printf("Occurrences:");
	for (int i = 0;i <= 9;i++) {
		printf("%d ", num[i]);
	}
	return 0;
}
