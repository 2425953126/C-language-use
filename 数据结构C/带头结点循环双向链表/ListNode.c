#define _CRT_SECURE_NO_WARNINGS 1
#include "ListNode.h"
ListNode* ListCreate()
{
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	assert(head != NULL);
	head->_next = head;
	head->_prev = head;
	return head;
}
void ListDestory(ListNode* pHead)
{	
	assert(pHead);
	ListNode* p = pHead->_next;
	while (p->_next != pHead)
	{	
		free(p->_prev);
		p = p->_next;
	}
	free(p);
	p = NULL;
	pHead = NULL;
}
void ListPrint(ListNode* pHead)
{	
	assert(pHead && pHead->_next != pHead);
	ListNode* p = pHead->_next;
	while (p!= pHead)
	{
		printf("%3d-->", p->_data);
		p = p->_next;
	}
}
ListNode* ListFind(ListNode* pHead, LTDataType x)
{
	assert(pHead&&pHead->_next!=pHead);
	ListNode* p = pHead->_next;
	while (p != pHead)
	{
		if (p->_data == x)
			return p;
		p = p->_next;
	}
	printf("\t#未找到所查结点!\n");
	return NULL;
}
void ListInsert(ListNode* pos, LTDataType x)
{	
	assert(pos);
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->_data = x;
	p->_next = pos;
	p->_prev = pos->_prev;
	pos->_prev->_next = p;
	pos->_prev = p;
	printf("\t#插入成功\n");
}
void ListPushFront(ListNode* pHead, LTDataType x)
{	
	assert(pHead);
	ListInsert(pHead->_next, x);
}
void ListPushBack(ListNode* pHead, LTDataType x)
{
	ListInsert(pHead, x);
}
void ListErase(ListNode* pos)
{	
	assert(pos&&pos->_next!=pos);
	pos->_prev->_next = pos->_next;
	pos->_next->_prev = pos->_prev;
	free(pos);
	pos = NULL;
	printf("\t#删除成功\n");
}
void ListPopFront(ListNode* pHead)
{	
	ListErase(pHead->_next);
}
void ListPopBack(ListNode* pHead)
{	
	ListErase(pHead->_prev);
}
