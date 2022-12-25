#pragma once
#include "sort1.h"
typedef Queue* SQLElement;
typedef struct SQList
{
	SQLElement* data;
	int size;
	int capacity;
}SQList;
void InitSQList(SQList* ps);
void SeqListDestroy(SQList* ps);
void ExpanSpace(SQList* ps);
void SeqListPushBack(SQList* ps, SQLElement x);