//顺序表 数据调整
//
//已知顺序表L中的数据元素类型为int。设计算法将其调整为左右两部分，左边的元素（即排在前面的）均为奇数，右边所有元素（即排在后面的）均为偶数，并要求算法的时间复杂度为O(n), 空间复杂度为O（1）。
//
//函数原型如下：
//void odd_even(SeqList* L);
//
//相关定义如下：
//struct _seqlist {
//    ElemType elem[MAXSIZE];
//    int last;
//};
//typedef struct _seqlist SeqList;

#include <stdio.h>
#include <stdlib.h>
#include "list.h" // 请不要删除，否则检查不通过

void odd_even(SeqList* L) {
    int left = 0;
    int right = L->last;
    int tem;

    while (left < right) {
        if (L->elem[left] % 2 != 0 && left < right) left++;
        if (L->elem[right] % 2 == 0 && left < right) right--;
        if (L->elem[left] % 2 == 0 && left < right && L->elem[right] % 2 != 0) {
            tem = L->elem[left];
            L->elem[left] = L->elem[right];
            L->elem[right] = tem;
        }
    }
}