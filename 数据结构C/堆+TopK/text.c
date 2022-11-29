#define _CRT_SECURE_NO_WARNINGS 1
#include "Heap.h"
void text(HPDataType*a)
{	
	Heap* hp = NULL;
	hp = Initheap(hp);
	HeapCreate(hp, a, Maxnumber);
	HeapPush(hp, 1000);
	HeapPush(hp, 999);
	HeapPop(hp);

	PrintHeap(hp);
	printf("%d\n", HeapEmpty(hp));
}
void PrintTopK(int* a, int k)
{
	for (int i = 0; i < k; i++)
	{
		printf("%8d", a[i]);
	}
	putchar('\n');
}
void TestTopk()					
{	
	void Adjustbefore(HPDataType * a, int child);
	void Adjustbelow(HPDataType * a, int parent, int n);
	int k = 10;
	HPDataType a[10000];
	int n = 10000;
	for (int i = 0; i < n; i++)
		a[i] = rand() % 10001;
	int child=1;
	while (child<10)
	{
		Adjustbefore(a, child++);
	}
	while (child < n)
	{
		if (a[child] < a[0])
		{
			a[0] = a[child];
			Adjustbelow(a, 0, 10);
		}
		child++;
	}
	PrintTopK(a, k);
}
int main()
{
	HPDataType a[Maxnumber];
	srand((unsigned int)time(0));
	for (int i = 0; i < Maxnumber; i++)
		a[i] = rand()%101;
	text(a);
	TestTopk();
	return 0;
}