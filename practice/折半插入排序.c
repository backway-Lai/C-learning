#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAXSIZE 6

int main() {
	int str[MAXSIZE];

	printf("Enter a string of numbers\n");
	for (int i = 0;i < MAXSIZE;i++) {
		scanf("%d", &str[i]);
	}

	for (int i = 1;i < MAXSIZE;i++) {
		if (str[i] >= str[i - 1]) continue;

		int temp = str[i];
		int low = 0;
		int high = i - 1;

		while (low <= high) {
			int mid = (low + high) / 2;

			if (temp >= str[mid]) low = mid + 1;
			else high = mid - 1;
		} 

		for (int j = i;j > low;j--) {
			str[j] = str[j - 1];
		}
		str[low] = temp;
	}

	for (int i = 0;i < MAXSIZE;i++) {
		printf("%d ", str[i]);
	}

	return 0;
}