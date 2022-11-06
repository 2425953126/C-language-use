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
// �����ݵĹ���:��ɾ��� 
void SeqListInit(SeqList* ps, char* filename);						//��ʼ��
void SeqListDestroy(SeqList* ps, char* filename);					//����

void SeqListPrint(SeqList* ps);						//��ӡ
void SeqListPushBack(SeqList* ps, SLDataType x);	//β��
void SeqListPushFront(SeqList* ps, SLDataType x);	//ͷ��
void SeqListPopFront(SeqList* ps);					//ͷɾ
void SeqListPopBack(SeqList* ps);					//βɾ

													// ˳������
void SeqListFind(SeqList* ps, SLDataType x);
													// ˳�����posλ�ò���x
int SeqListInsert(SeqList* ps, int pos, SLDataType x);
													// ˳���ɾ��posλ�õ�ֵ
int SeqListErase(SeqList* ps, int pos);
void SeqListModify(SeqList* ps, SLDataType x);		//�޸�

void DataTypeJudge(SLDataType* num, int funct);		//����SLDataType���ͽ�����������