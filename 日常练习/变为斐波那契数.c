#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{	
	int N = 0;
	printf("请输入要变为斐波那契数的数：\n");
	scanf("%d", &N);
	int a=0, b=1;
	int i;
	int tmp1=0,tmp2=0;
	while(1)
	{	
		if (N <=b)
			break;
		a = a + b;
		if (N <= a)
			break;
		b = b + a;
	}
	int n1 = 0, n2 = 0;
	n1 = n2 = N;
	if (a > b)
	{
		i = a;
		a = b;
		b = i;
	}
	while (1)
	{	
		if (a == n1)
			break;
		n1--;
		tmp1++;
		if (b == n2)
			break;
		n2++;
		tmp2++;
		
	}
	if (tmp1 <= tmp2)
		printf("至少要自减%d步", tmp1);
	else
		printf("至少要自增%d步", tmp2);
	return 0;
}
