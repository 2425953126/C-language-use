#define _CRT_SECURE_NO_WARNINGS 1
#include "STACK.h"
void text(Stack*ps)
{
	StackInit(ps);
	StackPush(ps, 1);
	StackPush(ps, 2);
	StackPush(ps, 3);
	StackPush(ps, 4);
	while (!StackEmpty(ps))
	{
		printf(" %d", StackTop(ps));
		StackPop(ps);
	}
	StackDestroy(ps);
}
int main()
{
	Stack a;
	text(&a);
	return 0;
}