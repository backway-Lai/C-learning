#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	float amount;

	printf("Enter an amount:\n");
	scanf("%f", &amount);

	printf("with tax added:%.2f\n", amount * 1.05);

	return 0;
}