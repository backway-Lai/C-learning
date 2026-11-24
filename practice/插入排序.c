#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAXSIZE 6

int main() {
	int str[MAXSIZE];
	int temp;

	printf("Enter a string of numbers:\n");
	for (int i = 0;i < MAXSIZE;i++) {
		scanf("%d", &str[i]);
	}

	for (int j = 1;j < MAXSIZE;j++) {
		temp = str[j];
		int i = j - 1;

		while (i >= 0 && temp < str[i]) {
			str[i + 1] = str[i];
			i--;
		}
		str[i + 1] = temp;
	}

	for (int i = 0;i < MAXSIZE;i++) {
		printf("%d ", str[i]);
	}

	return 0;
}