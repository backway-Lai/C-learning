//排序：希尔排序
//
//以下函数
//bool is_first_shellsort(int arr[], int n);
//用于验证任意整数序列是否为第一趟希尔排序结果。排序目标是升序。
//请将此函数补充完整。
//输入规则：输入在一行：第1个整数n是序列长度，接下来是n个用空格隔开的整数序列。
//输入样例1：10 5 1 2 3 4 10 6 7 8 9    输出样例1：Yes
//输入样例2：5 5 4 3 2 1    输出样例2：No

#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 128
int arr[MAX_SIZE + 1];

// 检查数组 arr[1..n] 是否为第一趟希尔排序（gap = n/2）后的结果。
bool is_first_shellsort(int arr[], int n);

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &arr[i]);

    printf(is_first_shellsort(arr, n) ? "Yes\n" : "No\n");

    return 0;
}

// --- 测试代码结束 ---------------------------------------------------------

// 你的代码写在 TODO和END OF TODO之间。
// 请勿将你的代码写在这对标签之外！！！
// 请勿修改这对标签外的任何代码！！！
/**
 * @brief 检查数组 arr[1..n] 是否为第一趟希尔排序（gap = n/2）后的结果。
 *
 * @param arr 数组。下标从1开始
 * @param n 元素个数
 * @return bool 如果是返回true，否则返回false
 */
bool is_first_shellsort(int arr[], int n) {
    if (n <= 1) return true;

    // TODO
    int gap = n / 2;
    for (int i = gap + 1;i <= n;i++) {
        if (arr[i] < arr[i - gap]) return false;
    }
    return true;
    // END OF TODO
}