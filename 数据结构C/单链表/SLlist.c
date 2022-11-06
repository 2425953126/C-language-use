#define _CRT_SECURE_NO_WARNINGS 1
#define Findtail(X) {														\
							while (X->next)									\
								X = X->next;								\
					}														\

#include "SLlist.h"
SListNode* BuySListNode(SLTDateType x)				// 动态申请一个节点
{
	SListNode* p = (SListNode*)malloc(sizeof(SListNode));
	if (p == NULL)
	{
		perror("BuySListNode molloc");
		exit(-1);
	}
	p->data = x;
	return p;
}
// 单链表打印
void SListPrint(SListNode* plist)
{	
	SListNode* tail = plist;
	while (tail)
	{
		printf("%d——》", tail->data);
		tail = tail->next;
	}
}
// 单链表尾插
void SListPushBack(SListNode** pplist, SLTDateType x)
{	
	if (*pplist == NULL)
	{
		*pplist = BuySListNode(x);
		(*pplist)->next = NULL;
	}
	else
	{
		SListNode* tail = *pplist;
		Findtail(tail)
		tail->next = BuySListNode(x);
		tail->next->next = NULL;
	}
}
// 单链表的头插
void SListPushFront(SListNode** pplist, SLTDateType x)
{
	if (*pplist == NULL)
	{
		*pplist = BuySListNode(x);
		(*pplist)->next = NULL;
	}
	else
	{
		SListNode* head = BuySListNode(x);
		head->next = *pplist;
		*pplist = head;
	}
}
// 单链表的尾删
void SListPopBack(SListNode** pplist)
{
	assert(*pplist != NULL);
	if ((*pplist)->next == NULL)
	{
		free(*pplist);
		*pplist = NULL;
	}
	else
	{
		SListNode* tail = *pplist;
		while (tail->next->next)
			tail = tail->next;
		free(tail->next);
		tail->next = NULL;
	}
}
// 单链表头删
void SListPopFront(SListNode** pplist)
{
	assert(*pplist != NULL);
	SListNode* newhead = (*pplist)->next;
	free(*pplist);
	*pplist = newhead;
}
// 单链表查找
SListNode* SListFind(SListNode* plist, SLTDateType x)
{	
	assert(plist != NULL);
	SListNode* findvalue = plist;
	while (findvalue != NULL&&findvalue->data != x)					//!=NULL一定要放前面,否则还会非法访问!!!
		findvalue = findvalue->next;
	return findvalue;
}
// 单链表在pos位置之后插入x
void SListInsertAfter(SListNode* pos, SLTDateType x)
{	
		assert(pos != NULL);
		SListNode* insert = BuySListNode(x);
		insert->next = pos->next;
		pos->next = insert;
}
// 单链表删除pos位置之后的值
void SListEraseAfter(SListNode* pos)
{
	assert(pos != NULL && pos->next != NULL);
	SListNode* tmp = pos->next;
	pos->next = pos->next->next;
	free(tmp);
}
// 单链表的销毁
void SListDestroy(SListNode** plist)
{	
	SListNode* tmp = *plist;
	while (*plist)
	{
		*plist = (*plist)->next;
		free(tmp);
		tmp = *plist;
	}
	printf("\n#已销毁\n");
}
