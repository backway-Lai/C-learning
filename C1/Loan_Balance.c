#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	float loan, rate, pay, first, second, third, monthly_rate;

	printf("Enter amount of loan:\n");
	scanf("%f", &loan);

	printf("Enter interest rate:\n");
	scanf("%f", &rate);

	printf("Enter monthly payment:\n");
	scanf("%f", &pay);

	monthly_rate = rate / 100 / 12;

	first = loan - pay + loan * monthly_rate;
	second = first - pay + first * monthly_rate;
	third = second - pay + second * monthly_rate;

	printf("Balance remaining after first payment:%.2f\n", first);
	printf("Balance remaining after second payment:%.2f\n", second);
	printf("Balance remaining after third payment:%.2f\n", third);

	return 0;
}