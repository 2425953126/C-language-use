#define _CRT_SECURE_NO_WARNINGS 1
#include "sort1.h"
void TestOP();
int main()
{
	//int a[10] = { 4109,1,22,5513,7,24,18,6,3,5 };//{ 4,1,2,5,7,4,8,6,3,5 };
	//InsertSort(a, 10);
	/*ShellSort(a, 10);
	SelectSort(a, 10);
	HeapSort(a,10);
	BubbleSort(a, 10);*/
	/*QuickSortNonR(a, 0, 10 - 1);*/
	///*QuickSortNonR(a, 0, 10 - 1);*/
	/*MergeSortNonR(a, 10);*/
	/*RadixSorting(a,10,10);*/
	/*for (int i = 0; i < 10; i++)
		printf("%d ", a[i]);*/
	TestOP();
	return 0;
}
void TestOP()
{
	srand(time(0));
	const int N = 1000000;
	int* a1 = (int*)malloc(sizeof(int) * N);
	int* a2 = (int*)malloc(sizeof(int) * N);
	int* a3 = (int*)malloc(sizeof(int) * N);
	int* a4 = (int*)malloc(sizeof(int) * N);
	int* a5 = (int*)malloc(sizeof(int) * N);
	int* a6 = (int*)malloc(sizeof(int) * N);
	int count = 0;
	for (int i = 0; i < N; ++i)
	{
		/*a1[i] = rand();*/
		a1[i] = count++;
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
	}
	int begin1 = clock();
	QuickSortNonR(a1,0,N-1);
	int end1 = clock();
	int begin2 = clock();
	ShellSort(a2,N);
	int end2 = clock();
	int begin3 = clock();
	MergeSortNonR(a3,N);
	int end3 = clock();
	int begin4 = clock();
	HeapSort(a4,N);
	int end4 = clock();
	int begin5 = clock();
	CountSort(a5,N);
	int end5 = clock();
	int begin6 = clock();
	RadixSorting(a6, N,10);
	int end6 = clock();
	printf("¿ìÅÅ·ÇµÝ¹é:%d\n", end1 - begin1);
	printf("Ï£¶ûÅÅÐò:%d\n", end2 - begin2);
	printf("·ÇµÝ¹é¶þ·Ö¹é²¢:%d\n", end3 - begin3);
	printf("¶ÑÅÅÐò:%d\n", end4 - begin4);
	printf("¼ÆÊýÅÅÐò:%d\n", end5 - begin5);
	printf("»ùÊýÅÅÐò:% d\n", end6 - begin6);
	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
}