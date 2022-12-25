#define _CRT_SECURE_NO_WARNINGS 1
#include "sort1.h"
void InitSQList(SQList* ps)//��ʼ��
{	
	assert(ps != NULL);
	ps->data = (SQLElement*)malloc(sizeof(SQLElement) * 10);
	if (ps->data == NULL)
		exit(-1);
	ps->size = 0;
	ps->capacity = 10;
}
void SeqListDestroy(SQList* ps)//����
{
	assert(ps != NULL);
	free(ps->data);
	int size = 0;
	int capacity = 0;
}
void ExpanSpaceqsqlist(SQList* ps)//����
{
	assert(ps != NULL);
	ps->data = realloc(ps->data,ps->capacity*sizeof(SQLElement)*2);
	if (ps->data == NULL)
		exit(-1);
	ps->capacity *= 2;
}
void SeqListPushBack(SQList* ps, SQLElement x)	//β��
{
	assert(ps);
	if (ps->size == ps->capacity)
		ExpanSpaceqsqlist(ps);
	ps->data[ps->size] = x;
	ps->size++;
}
