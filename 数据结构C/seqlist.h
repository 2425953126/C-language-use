#define _CRT_SECURE_NO_WARNINGS 1
#define Initspace 100
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <windows.h>
typedef float SLDataType;
typedef struct SeqList
{	
	SLDataType* a;
	int size;
	int capacity;
}SeqList;
// 对数据的管理:增删查改 
void SeqListInit(SeqList* ps, char* filename);						//初始化
void SeqListDestroy(SeqList* ps, char* filename);					//销毁

void SeqListPrint(SeqList* ps);						//打印
void SeqListPushBack(SeqList* ps, SLDataType x);	//尾插
void SeqListPushFront(SeqList* ps, SLDataType x);	//头插
void SeqListPopFront(SeqList* ps);					//头删
void SeqListPopBack(SeqList* ps);					//尾删

													// 顺序表查找
void SeqListFind(SeqList* ps, SLDataType x);
													// 顺序表在pos位置插入x
int SeqListInsert(SeqList* ps, int pos, SLDataType x);
													// 顺序表删除pos位置的值
int SeqListErase(SeqList* ps, int pos);
void SeqListModify(SeqList* ps, SLDataType x);		//修改

void DataTypeJudge(SLDataType* num, int funct);		//根据SLDataType类型进行输入或输出