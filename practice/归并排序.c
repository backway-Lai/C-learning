#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void MergeSort(int arr[], int n) {
	int temp[128];

	for (int width = 1;width < n;width *= 2) {
		printf("width == %d\n", width);

		for (int left = 0;left < n;left += 2 * width) {
			int mid = left + width - 1;
			int right = left + 2 * width - 1;

			if (mid >= n) break;
			if (right >= n) right = n - 1;

			int i = left, j = mid + 1, k = left;
			while (i <= mid && j <= right) {
				if (arr[i] <= arr[j]) temp[k++] = arr[i++];
				else temp[k++] = arr[j++];
			}
			while (i <= mid) temp[k++] = arr[i++];
			while (j <= right) temp[k++] = arr[j++];

			for (int p = left;p <= right;p++) arr[p] = temp[p];
		}
	}
}

int main() {
	int arr[8];

	printf("Enter a array of 8 numbers\n");
	for (int i = 0;i < 8;i++) scanf("%d", &arr[i]);

	MergeSort(arr, 8);

	for (int i = 0;i < 8;i++) printf("%d ", arr[i]);

	return 0;
}