#define _CRT_SECURE_NO_WARNINGS 1
#include "Queue.h"
void text(QNode* q)
{
	QueueInit(q);
	QueuePush(q,1);
	QueuePush(q,2);
	QueuePush(q,3);
	QueuePush(q,4);
	QueuePush(q,10);
	printf("%d \n", QueueSize(q));
	printf("%d \n", QueueBack(q));
	while (QueueEmpty(q))
	{
		printf("%d ", QueueFront(q)) ;
		QueuePop(q);
	}
	QueueDestroy(q);
}
int main()
{
	Queue a;
	text(&a);
	return 0;
}