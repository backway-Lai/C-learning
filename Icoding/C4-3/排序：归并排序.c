//排序：归并排序
//
//以下函数
//bool is_first_mergesort(int arr[], int n);
//用于验证任意整数序列是否为第一趟二路归并排序结果。排序目标是升序。
//请将此函数补充完整。
//输入规则：输入在一行：第1个整数n是序列长度，接下来是n个用空格隔开的整数序列。
//输入样例1：7 30 12 23 15 40 50 35    输出样例1：No
//输入样例2：5 10 30 20 40 50    输出样例2：Yes

#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 128
int arr[MAX_SIZE + 1];

// 验证数组 arr[1..n] 是否是第一趟二路归并排序的结果
bool is_first_mergesort(int arr[], int n);

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= MAX_SIZE; ++i) arr[i] = -1;
    for (int i = 1; i <= n; ++i) scanf("%d", &arr[i]);

    printf(is_first_mergesort(arr, n) ? "Yes\n" : "No\n");

    return 0;
}

/**
 * @brief 验证数组 arr[1..n] 是否是第一趟二路归并排序的结果
 *
 *  * @param arr 数组。下标从1开始
 * @param n 元素个数
 * @return bool 如果是返回true，否则返回false
 */
bool is_first_mergesort(int arr[], int n) {
    if (n <= 1) return true;

    // TODO
    int width = 1;
    for (int left = 1;left <= n;left += 2 * width) {
        if (left == n) return true;
        int right = left + 1;

        if (arr[left] <= arr[right]) continue;
        else return false;
    }
    // END OF TODO
}