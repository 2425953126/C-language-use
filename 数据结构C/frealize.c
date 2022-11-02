#define _CRT_SECURE_NO_WARNINGS 1
#define JudgeSpace(P)	if (P->size == P->capacity)	ExpanSpace(P);			//判断容量
#include "seqlist.h"
void DataTypeJudge(SLDataType * num, int funct)		//根据SLDataType类型进行输入或输出
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
void ExpanSpace(SeqList* ps)													//扩容
{	
	SLDataType* p = ps->a;
	int EachSpaceExpen = sizeof(SLDataType) * Initspace * 1.25;						//每次扩容大小
	p = (SLDataType*)realloc(p, EachSpaceExpen+ ps->capacity * sizeof(SLDataType));
	if (p == NULL)
	{
		perror("#扩容失败");
		exit(-1);
	}
	ps->a = p;
	ps->capacity +=EachSpaceExpen;
}

void SeqListInit(SeqList* ps,char*filename)										//初始化
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
	puts("#初始化完成\n");
}

void SeqListPrint(SeqList* ps)													//打印
{	
	SLDataType flag=128.5;
	printf("#输出数据:\n");
	if (flag == 128.5)													//判断SLDataType为何种类型数据
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
void SeqListDestroy(SeqList* ps, char* filename)												//销毁
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
int SeqListInsert(SeqList* ps, int pos, SLDataType x)										//指定位置插入
{	
	if (pos<1 || pos>ps->size+1)
	{
		printf("#插入位置错误\n");
		return EOF;																	//ps->a[pos] pos=3,从a[3]开始后移

	}
	JudgeSpace(ps);
	for (int i=ps->size;i>=pos;i--)
	{
		ps->a[i] = ps->a[i - 1];
	}
	ps->a[pos-1] = x;
	ps->size++;
}

void SeqListPushBack(SeqList* ps, SLDataType x)											//尾插
{
	SeqListInsert(ps, ps->size+1, x);
}

void SeqListPushFront(SeqList* ps, SLDataType x)									//头插
{
	SeqListInsert(ps, 1, x);
}

int SeqListErase(SeqList* ps, int pos)												//指定位置删除
{
	if (pos<1 || pos>ps->size)
	{
		printf("#删除位置错误\n");
		return EOF;																	

	}
	for (int i = pos; i < ps->size; i++)
	{
		ps->a[i-1] = ps->a[i];
	}
	ps->size--;
}

void SeqListPopFront(SeqList* ps)					//头删
{
	SeqListErase(ps, 1);
}

void SeqListPopBack(SeqList* ps)					//尾删
{
	SeqListErase(ps, ps->size);
}

void SeqListFind(SeqList* ps, SLDataType x)			//查找
{
	int i = 0;
	while (ps->a[i++] != x&&i<ps->size);
	if (i >= ps->size)
	{
		printf("#要查找的数不存在\n");
		return;
	}
	printf("#size-%d: ", i);
	SLDataType* y = &ps->a[i - 1];
	DataTypeJudge(y, 1);
}
void SeqListModify(SeqList* ps, int pos,SLDataType x)		//修改
{	
	if(pos<1||pos>ps->size)
	{
		printf("#要修改的数不存在\n");
		return;
	}
	ps->a[pos - 1] = x;
	printf("#size-%d已修改为: ", pos);
	SLDataType* y = &ps->a[ pos-1];
	DataTypeJudge(y, 1);
}

