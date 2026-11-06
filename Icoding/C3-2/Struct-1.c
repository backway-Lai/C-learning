//结构：按字段排序
//
//有键值对类型以及相关定义如下
//typedef struct { //定义键值对类型 char key[10]; int value; } kv_pair; #define MAXN 30//定义用于比较的回调函数类型typedef int cmp_fn(const kv_pair *, const kv_pair *);
//	要求补充完整两个比较函数和冒泡排序函数。
//		输入规则：输入在一行：第1个整数n是键值对个数，接下来是n对键值对序列，最后一个整数c是选择用哪个字段排序。
//		输出形式：排序后的键值对序列。
//		输入样例1：4 dx 25 ac 5 def 30 ab 20 1   输出样例1：{ ab,20 }{ac, 5} { def, 30 } { dx, 25 }
//	输入样例2：4 dx 25 ac 5 def 30 ab 20 2   输出样例2：{ ac,5 }{ab, 20} { dx, 25 } { def, 30 }

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct { //定义键值对类型
    char key[10];
    int value;
} kv_pair;

#define MAXN 30 

//定义用于比较的回调函数类型
typedef int cmp_fn(const kv_pair*, const kv_pair*);

int cmp_key(const kv_pair* a, const kv_pair* b);
int cmp_value(const kv_pair* a, const kv_pair* b);
void bubble_sort(kv_pair* dict, int n, cmp_fn cmp);

kv_pair dict[MAXN];

int main() {
    int n;
    scanf("%d", &n); //测试用例保证0 < n <= 30
    for (int i = 0; i < n; ++i) {
        scanf("%s %d", dict[i].key, &dict[i].value);
    }

    int choice;
    scanf("%d", &choice);
    if (choice == 1) {
        bubble_sort(dict, n, cmp_key);   //为什么此处调用函数时不需要调用参数？
    }
    else {
        bubble_sort(dict, n, cmp_value);
    }

    for (int i = 0; i < n; ++i) {
        printf("{%s,%d}", dict[i].key, dict[i].value);
    }
    printf("\n");
    return 0;
}

//请勿删除或修改此行以上的所有内容！！！
//你的代码写在TODO和END OF TODO之间

//用于键的三向比较函数：a->key大于b->key 返回正值，相等返回0，小于返回负值
int cmp_key(const kv_pair* a, const kv_pair* b) {
    // TODO
    return strcmp(a->key, b->key);
    // END OF TODO
}

//用于值的比较函数：a->value大于b->value 返回正值，相等返回0，小于返回负值
int cmp_value(const kv_pair* a, const kv_pair* b) {
    // TODO
    if (a->value > b->value) return 1;
    else if (a->value < b->value) return -1;
    else return 0;
    // END OF TODO
}

//冒泡排序。dict：待排序的数组；n：数组的长度；cmp：比较函数
void bubble_sort(kv_pair* dict, int n, cmp_fn cmp) {
    // TODO
    for (int i = 0;i < n - 1;i++) {
        for (int j = 0;j < n - 1 - i;j++) {
            if (cmp(&dict[j], &dict[j + 1]) > 0) {
                kv_pair tem = dict[j + 1];
                dict[j + 1] = dict[j];
                dict[j] = tem;
            }
        }
    }
    // END OF TODO
}