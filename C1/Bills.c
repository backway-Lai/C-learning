#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int amount;

	printf("Enter a dollar amount:\n");
	scanf("%d", &amount);

	int bill20 = amount / 20;
	int bill10 = (amount - bill20 * 20) / 10;
	int bill5 = (amount - bill20 * 20 - bill10 * 10 ) / 5;
	int bill1 = amount - bill20 * 20 - bill10 * 10 - bill5 * 5;

	printf("$20 bills:%d\n", bill20);
	printf("$10 bills:%d\n", bill10);
	printf("$5 bills:%d\n", bill5);
	printf("$1 bills:%d\n", bill1);

	return 0;
}