#define _CRT_SECURE_NO_WARNINGS 1
#define Findtail(X) {														\
							while (X->next)									\
								X = X->next;								\
					}														\

#include "SLlist.h"
SListNode* BuySListNode(SLTDateType x)				// ��̬����һ���ڵ�
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
// �������ӡ
void SListPrint(SListNode* plist)
{	
	SListNode* tail = plist;
	while (tail)
	{
		printf("%d������", tail->data);
		tail = tail->next;
	}
}
// ������β��
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
// �������ͷ��
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
// �������βɾ
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
// ������ͷɾ
void SListPopFront(SListNode** pplist)
{
	assert(*pplist != NULL);
	SListNode* newhead = (*pplist)->next;
	free(*pplist);
	*pplist = newhead;
}
// ���������
SListNode* SListFind(SListNode* plist, SLTDateType x)
{	
	assert(plist != NULL);
	SListNode* findvalue = plist;
	while (findvalue != NULL&&findvalue->data != x)					//!=NULLһ��Ҫ��ǰ��,���򻹻�Ƿ�����!!!
		findvalue = findvalue->next;
	return findvalue;
}
// ��������posλ��֮�����x
void SListInsertAfter(SListNode* pos, SLTDateType x)
{	
		assert(pos != NULL);
		SListNode* insert = BuySListNode(x);
		insert->next = pos->next;
		pos->next = insert;
}
// ������ɾ��posλ��֮���ֵ
void SListEraseAfter(SListNode* pos)
{
	assert(pos != NULL && pos->next != NULL);
	SListNode* tmp = pos->next;
	pos->next = pos->next->next;
	free(tmp);
}
// �����������
void SListDestroy(SListNode** plist)
{	
	SListNode* tmp = *plist;
	while (*plist)
	{
		*plist = (*plist)->next;
		free(tmp);
		tmp = *plist;
	}
	printf("\n#������\n");
}
