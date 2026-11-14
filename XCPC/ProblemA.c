#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	int n;
	char X, Y;
	char str[10000];

	scanf("%d %c", &n, &X);
	scanf("%s", str);
	scanf(" %c", &Y);

	char x = X + 32;
	char y = Y + 32;

	for (int i = 0;i <= n;i++) {
		if (str[i] == x || str[i] == X) {
			if (str[i] == x) str[i] = y;
			else str[i] = Y;
		}
	}

	printf("%s", str);

	return 0;
}