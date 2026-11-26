//排序：快速排序
//
//以下函数
//bool is_first_quicksort(int arr[], int n);
//用于验证任意整数序列是否为第一趟快速排序结果。排序目标是升序。
//请将此函数补充完整。
//输入规则：第一个数n是序列的长度；第二个数m是枢轴元素的下标，从1开始；接下来是n个用空格隔开的整数序列。
//输入样例1：8 5 33 45 12 26 50 99 76 82    输出样例1：Yes
//输入样例2：7 4 28 65 93 11 50 77 36    输出样例2：No

#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 128
int arr[MAX_SIZE + 1];

// 验证数组 arr[1..n] 是否是第一趟快速排序的结果
bool is_first_quicksort(int arr[], int n, int pivot);

int main() {
    int n, pivot;
    scanf("%d%d", &n, &pivot);
    for (int i = 1; i <= MAX_SIZE; ++i) arr[i] = -1;
    for (int i = 1; i <= n; ++i) scanf("%d", &arr[i]);

    printf(is_first_quicksort(arr, n, pivot) ? "Yes\n" : "No\n");

    return 0;
}

// --- 测试代码结束 ---------------------------------------------------------


// 你的代码写在 TODO和END OF TODO之间。
// 请勿将你的代码写在这对标签之外！！！
// 请勿修改这对标签外的任何代码！！！
/**
 * @brief 验证数组 arr[1..n] 是否是第一趟快速排序的结果
 *
 * @param arr 数组，下标从1开始
 * @param n 元素个数
 * @param pivot 枢轴元素下标
 * @return bool 如果是返回true，否则返回false
 */
bool is_first_quicksort(int arr[], int n, int pivot) {
    if (n <= 1) return true;

    // TODO
    for (int left = 1;left < pivot;left++) {
        if (arr[left] > arr[pivot]) return false;
    }
    for (int right = n;right > pivot;right--) {
        if (arr[right] < arr[pivot]) return false;
    }
    return true;
    // ENDOFTODO
}
