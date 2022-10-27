#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#define My_offsetof(x,stu)	int count=0;							\
							while(count<sizeof(*stu)&&stu!=&x)		\
							{										\
								count++;							\
								stu = (char*)stu + 1;				\
							}										\
							printf(#x"成员首地址偏移为%d\n",count);	 \

int main()
{
	struct test
	{
		int a;
		char s[10];
		float b;
		int c;
	}new={13,"abcde",3.14,20};
	struct test* p = &new;
	My_offsetof(new.b, p)
	return 0;
}