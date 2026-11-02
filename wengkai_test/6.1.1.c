//求符合给定条件的整数集

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int N;

	scanf("%d", &N);

	int i = N;
	int j = N;
	int k = N;
	while (i <= N + 3) {
		while (j <= N + 3 && j != i) {
			while (k <= N + 3 && k != j && k != i) {
				printf("%d%d%d ", i, j, k);
				k++;
			}
			j++;
		}
		i++;
	}

	return 0;
}