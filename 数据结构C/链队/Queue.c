#define _CRT_SECURE_NO_WARNINGS 1
#include "Queue.h"
// 初始化队列 
void QueueInit(Queue* q)
{
	q->front = NULL;
	q->rear = NULL;
}
// 队尾入队列 
void QueuePush(Queue* q, QDataType data)
{	
	assert(q);
	QNode* tmp = (QNode*)malloc(sizeof(QNode));
	tmp->data = data;
	tmp->next = NULL;
	if (q->rear != NULL)
	{	
		q->rear->next = tmp;//链接到队列的尾部
		q->rear = tmp;//新增的成员变为新的尾部
	}
	else
	{
		q->rear = tmp;//如果队列原本为空,则新增的成员直接变为新的尾部和头部
		q->front = tmp;;
	}
}
// 队头出队列 
void QueuePop(Queue* q)
{
	assert(q && q->front !=NULL);
	QNode* tmp = q->front;
	q->front = q->front->next;//队头指向队列中第二位成员了
	if (q->front == NULL)//如果此时要删除的队头已经为队尾元素,则要一并修改队尾指针
		q->rear = NULL;
	free(tmp);//删除原队头成员
}
// 获取队列头部元素 
QDataType QueueFront(Queue* q)
{
	assert(q&&q->front!=NULL);
	return q->front->data;
}
// 获取队列队尾元素 
QDataType QueueBack(Queue* q)
{
	assert(q && q->rear != NULL);
	return q->rear->data;
}
// 获取队列中有效元素个数 
int QueueSize(Queue* q)
{	
	assert(q);
	if (q->front == NULL)
		return 0;
	QNode* tmp = q->front;
	int count=0;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return count;
}
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q)
{
	return q->front == NULL ? 0 : 1;
}
// 销毁队列 
void QueueDestroy(Queue* q)
{
	assert(q);
	QNode* tmp =NULL;
	while (q->front!=NULL)//如果队头本来就为空,就不必执行了
	{	
			tmp = q->front;
			q->front = q->front->next;
			free(tmp);
	}
	q->rear = NULL;//队尾指针也需为空,否则变为野指针不安全
}