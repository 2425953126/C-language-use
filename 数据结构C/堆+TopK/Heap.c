#define _CRT_SECURE_NO_WARNINGS 1
#include "Heap.h"
Heap* Initheap(Heap* p)//初始化
{
	p = (Heap*)malloc(sizeof(Heap));
	p->_a = NULL;
	p->_size = p->_capacity = 0;
	return p;
}
// 堆的销毁
void HeapDestory(Heap* hp)
{
	free(hp->_a);
	free(hp);
}
void PrintHeap(Heap* hp)
{
	for (int i = 0; i < hp->_size; i++)
		printf("%8d", hp->_a[i]);
	putchar('\n');
}
void ExtandSpace(Heap* hp)//扩容
{
	hp->_a = realloc(hp->_a, sizeof(HPDataType) *( hp->_capacity * 1.5+4));
	if (hp->_a == NULL)
		exit(EOF);
	hp->_capacity = hp->_capacity * 1.5 + 4;
}
//交换
void Swap(HPDataType*a,int i,int j)
{
	a[i] ^= a[j];
	a[j] ^= a[i];
	a[i] ^= a[j];
}
//向下调整算法
void Adjustbelow(HPDataType*a,int parent,int n)
{
	int child = 2 * parent+1;
	while (child < n)
	{
		if (child + 2 < n)
			child = a[child] > a[child + 1] ? child: child + 1;
		if (a[parent] < a[child])
			Swap(a, parent, child);
		else
			break;
		parent = child;
		child = 2 * parent + 1;
	}
}
//向上调整算法
void Adjustbefore(HPDataType* a, int child)
{
	int parent=(child-1)/2;
	while (child>0)
	{
		if (a[child] > a[parent])
			Swap(a, child, parent);
		else
			break;
		child = parent;
		parent = (child - 1) / 2;
	}
}
// 堆的构建
void HeapCreate(Heap* hp, HPDataType* a, int n)
{
	assert(hp && a);
	int i = 0;
	while (i < n)
	{
		if (hp->_size >= hp->_capacity)
			ExtandSpace(hp);
		hp->_a[i] = a[i];
		i++;
		hp->_size++;
	}
	int parent = n - 1;
	/*while ((2 * parent + 1) > n)
		parent--;*/
	parent = (parent - 1) / 2;
	int child = 0;
	while (parent >= 0)
	{
		Adjustbelow(hp->_a, parent, n);
		parent--;
	}
}
// 堆的插入
void HeapPush(Heap* hp, HPDataType x)
{	
	assert(hp);
	if (hp->_size >= hp->_capacity)
		ExtandSpace(hp);
	hp->_a[hp->_size++] = x;
	if (hp->_size - 1 != 0)
		Adjustbefore(hp->_a, hp->_size-1);
}
// 堆的删除
void HeapPop(Heap* hp)
{	
	assert(hp);
	Swap(hp->_a, 0, hp->_size - 1);
	hp->_size--;
	Adjustbelow(hp->_a, 0, hp->_size);
}
// 取堆顶的数据
HPDataType HeapTop(Heap* hp)
{	
	assert(hp);
	return hp->_a[0];
}
// 堆的数据个数
int HeapSize(Heap* hp)
{	
	assert(hp);
	return hp->_size;
}
// 堆的判空
int HeapEmpty(Heap* hp)
{
	return hp->_size == 0;
}
