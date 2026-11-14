//队列 循环链表表示队列
//
//假设以带头结点的循环链表表示队列，并且只设一个指针指向队尾元素结点（注意不设头指针），请完成下列任务：
//
//
//1: 队列初始化，成功返回真，否则返回假： bool init_queue(LinkQueue * LQ);
//
//2: 入队列，成功返回真，否则返回假： bool enter_queue(LinkQueue * LQ, ElemType x);
//
//3: 出队列，成功返回真，且 * x为出队的值，否则返回假 bool leave_queue(LinkQueue * LQ, ElemType * x);
//
//相关定义如下：
//
//typedef struct _QueueNode {
//    ElemType data;          // 数据域
//    struct _QueueNode* next;      // 指针域
//}LinkQueueNode, * LinkQueue;

#include <stdio.h>
#include <stdlib.h>
#include "list.h" // 请不要删除，否则检查不通过

bool init_queue(LinkQueue* LQ)
{
	if (LQ == NULL) return false;

	*LQ = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
	(*LQ)->next = *LQ;
	return true;
}

bool enter_queue(LinkQueue* LQ, ElemType x)
{
	if (LQ == NULL || *LQ == NULL) return false;

	LinkQueue p = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
	if (p == NULL) return false;
	p->data = x;
	p->next = (*LQ)->next;

	(*LQ)->next = p;
	*LQ = p;

	return true;
}

bool leave_queue(LinkQueue* LQ, ElemType* x)
{
	if (LQ == NULL || *LQ == NULL) return false;
	if ((*LQ)->next == *LQ) return false;

	LinkQueue head = (*LQ)->next;
	LinkQueue delete = head->next;

	head->next = delete->next;
	*x = delete->data;
	free(delete);

	if (head->next == head) *LQ = head;
	return true;
}
