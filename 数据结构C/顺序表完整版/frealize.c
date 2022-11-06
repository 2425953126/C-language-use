#define _CRT_SECURE_NO_WARNINGS 1
#define JudgeSpace(P)	if (P->size == P->capacity)	ExpanSpace(P);			//�ж�����
#include "seqlist.h"
void DataTypeJudge(SLDataType * num, int funct)		//����SLDataType���ͽ�����������
{
	SLDataType flag = 128.5;
	if (flag == 128.5)
		if (funct == 0)
			scanf(" %f", num);
		else
			printf("%f\n", *num);
	else if (flag == -128)
		if (funct == 0)
			scanf(" %c", num);
		else
			printf("%c\n", *num);
	else
		if (funct == 0)
			scanf(" %d", num);
		else
			printf("%d\n", *num);
}
void ExpanSpace(SeqList* ps)													//����
{	
	SLDataType* p = ps->a;
	int EachSpaceExpen = sizeof(SLDataType) * Initspace * 1.25;						//ÿ�����ݴ�С
	p = (SLDataType*)realloc(p, EachSpaceExpen+ ps->capacity * sizeof(SLDataType));
	if (p == NULL)
	{
		perror("#����ʧ��");
		exit(-1);
	}
	ps->a = p;
	ps->capacity +=EachSpaceExpen;
}

void SeqListInit(SeqList* ps,char*filename)										//��ʼ��
{	
	FILE* p = fopen(filename, "ab+");
	ps->a = (SLDataType*)malloc(sizeof(SLDataType) * Initspace);
	if (ps->a == NULL)
	{
		perror("SeqListInit malloc");
		return;
	}
	ps->size = 0;
	ps->capacity = Initspace;
	int i = 0;
	SLDataType y = 0;
	SLDataType *x =&y ;
	while (1)
	{	
		JudgeSpace(ps);
		if (fread(x, sizeof(SLDataType), 1, p) == 0)
			break;
		ps->a[i] = *x;
		ps->size++;
		i++;
	}
	fclose(p);
	puts("#��ʼ�����\n");
}

void SeqListPrint(SeqList* ps)													//��ӡ
{	
	SLDataType flag=128.5;
	printf("#�������:\n");
	if (flag == 128.5)													//�ж�SLDataTypeΪ������������
		for (int i = 0; i < ps->size; i++)
		{
			printf("\tsize-%d: %f", i + 1, ps->a[i]);
			if ((i + 1) % 6 == 0)	putchar('\n');
		}
	else if(flag==-128)
		for (int i = 0; i < ps->size; i++)
		{
			printf("\tsize-%d: %c", i + 1, ps->a[i]);
			if ((i + 1) % 6 == 0)	putchar('\n');
		}
	else
		for (int i = 0; i < ps->size; i++)
		{
			printf("\tsize-%d: %d", i + 1, ps->a[i]);
			if ((i + 1) % 6 == 0)	putchar('\n');
		}
	putchar('\n');
	putchar('\n');
}
void SeqListDestroy(SeqList* ps, char* filename)												//����
{
	FILE* p = fopen(filename, "wb");
	SLDataType y = 0;
	SLDataType* x = &y;
	for (int i = 0; i < ps->size; i++)
	{	
		*x = ps->a[i];
		fwrite(x, sizeof(SLDataType), 1, p);
	}
	fclose(p);
	free(ps->a);
	ps->size = 0;
	ps->capacity = 0;
	ps->a = NULL;
}
int SeqListInsert(SeqList* ps, int pos, SLDataType x)										//ָ��λ�ò���
{	
	if (pos<1 || pos>ps->size+1)
	{
		printf("#����λ�ô���\n");
		return EOF;																	//ps->a[pos] pos=3,��a[3]��ʼ����

	}
	JudgeSpace(ps);
	for (int i=ps->size;i>=pos;i--)
	{
		ps->a[i] = ps->a[i - 1];
	}
	ps->a[pos-1] = x;
	ps->size++;
}

void SeqListPushBack(SeqList* ps, SLDataType x)											//β��
{
	SeqListInsert(ps, ps->size+1, x);
}

void SeqListPushFront(SeqList* ps, SLDataType x)									//ͷ��
{
	SeqListInsert(ps, 1, x);
}

int SeqListErase(SeqList* ps, int pos)												//ָ��λ��ɾ��
{
	if (pos<1 || pos>ps->size)
	{
		printf("#ɾ��λ�ô���\n");
		return EOF;																	

	}
	for (int i = pos; i < ps->size; i++)
	{
		ps->a[i-1] = ps->a[i];
	}
	ps->size--;
}

void SeqListPopFront(SeqList* ps)					//ͷɾ
{
	SeqListErase(ps, 1);
}

void SeqListPopBack(SeqList* ps)					//βɾ
{
	SeqListErase(ps, ps->size);
}

void SeqListFind(SeqList* ps, SLDataType x)			//����
{
	int i = 0;
	while (ps->a[i++] != x&&i<ps->size);
	if (i >= ps->size)
	{
		printf("#Ҫ���ҵ���������\n");
		return;
	}
	printf("#size-%d: ", i);
	SLDataType* y = &ps->a[i - 1];
	DataTypeJudge(y, 1);
}
void SeqListModify(SeqList* ps, int pos,SLDataType x)		//�޸�
{	
	if(pos<1||pos>ps->size)
	{
		printf("#Ҫ�޸ĵ���������\n");
		return;
	}
	ps->a[pos - 1] = x;
	printf("#size-%d���޸�Ϊ: ", pos);
	SLDataType* y = &ps->a[ pos-1];
	DataTypeJudge(y, 1);
}

