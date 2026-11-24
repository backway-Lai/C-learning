#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAXSIZE 6

int main() {
	int arr[MAXSIZE];

	printf("Enter a array of numbers\n");
	for (int i = 0;i < MAXSIZE;i++) {
		scanf("%d", &arr[i]);
	}

	for (int gap = MAXSIZE / 2;gap >= 1;gap /= 2) {
		for (int i = gap;i < MAXSIZE;i++) {
			int temp = arr[i];
			int j = i - gap;

			while (j >= 0 && arr[j] > temp) {
				arr[j + gap] = arr[j];
				j -= gap;
			}
			arr[j + gap] = temp;
		}
	}
	for (int i = 0;i < MAXSIZE;i++) {
		printf("%d ", arr[i]);
	}

	return 0;
}