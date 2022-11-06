#define _CRT_SECURE_NO_WARNINGS 1
#include "SLlist.h"
void test(SListNode**pplist)
{
	SListPushBack(pplist, 1);
	SListPushBack(pplist, 2);
	SListPushBack(pplist, 3);
	SListPushFront(pplist, 0);
	SListPopBack(pplist);
	SListPopFront(pplist);
	SListInsertAfter(SListFind(*pplist, 1),88);
	SListEraseAfter(SListFind(*pplist, 88));
	SListPrint(*pplist);
	SListDestroy(pplist);
}
int main()
{
	SListNode* Origtable = NULL;
	test(&Origtable);
	return;
}