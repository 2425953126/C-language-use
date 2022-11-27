#define _CRT_SECURE_NO_WARNINGS 1
#include "ListNode.h"
void text(ListNode* p)
{	
	p = ListCreate();
	ListPushBack(p, 1);
	ListPushBack(p, 2);
	ListPushBack(p, 3);
	ListPushBack(p, 4);
	ListPushFront(p, 1);
	ListPushFront(p, 2);
	ListPushFront(p, 3);
	ListPushFront(p, 4);
	ListNode* pf = ListFind(p, 3);
	ListInsert(pf, 10);
	ListPopFront(p);
	ListPopBack(p);
	pf = ListFind(p, 2);
	ListErase(pf);
	ListPrint(p);
}

int main()
{	
	ListNode* p = NULL;
	text(p);
	return 0;
}