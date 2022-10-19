#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
void single_dog(int* p, int n)
{
	int i, j;
	int* dz = (int*)malloc(n * sizeof(int));
	for (i = 0; i < n; i++)
	{
		dz[i] = 0;
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j<n; j++)
		{
			if (p[j] == p[i]&&i!=j)
				dz[i]++;
		}
	}
	for (i = 0; i < n; i++)
		if (dz[i] < 1)
			printf("%d\t", p[i]);
}
int main()
{
	int a[] = { 0,1,0,3,1,5,3,6};
	single_dog(a, 8);
	return 0;
}