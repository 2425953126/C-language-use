#define _CRT_SECURE_NO_WARNINGS 1
#include "Queue.h"
// ��ʼ������ 
void QueueInit(Queue* q)
{
	q->front = NULL;
	q->rear = NULL;
}
// ��β����� 
void QueuePush(Queue* q, QDataType data)
{	
	assert(q);
	QNode* tmp = (QNode*)malloc(sizeof(QNode));
	tmp->data = data;
	tmp->next = NULL;
	if (q->rear != NULL)
	{	
		q->rear->next = tmp;//���ӵ����е�β��
		q->rear = tmp;//�����ĳ�Ա��Ϊ�µ�β��
	}
	else
	{
		q->rear = tmp;//�������ԭ��Ϊ��,�������ĳ�Աֱ�ӱ�Ϊ�µ�β����ͷ��
		q->front = tmp;;
	}
}
// ��ͷ������ 
void QueuePop(Queue* q)
{
	assert(q && q->front !=NULL);
	QNode* tmp = q->front;
	q->front = q->front->next;//��ͷָ������еڶ�λ��Ա��
	if (q->front == NULL)//�����ʱҪɾ���Ķ�ͷ�Ѿ�Ϊ��βԪ��,��Ҫһ���޸Ķ�βָ��
		q->rear = NULL;
	free(tmp);//ɾ��ԭ��ͷ��Ա
}
// ��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* q)
{
	assert(q&&q->front!=NULL);
	return q->front->data;
}
// ��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* q)
{
	assert(q && q->rear != NULL);
	return q->rear->data;
}
// ��ȡ��������ЧԪ�ظ��� 
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
// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q)
{
	return q->front == NULL ? 0 : 1;
}
// ���ٶ��� 
void QueueDestroy(Queue* q)
{
	assert(q);
	QNode* tmp =NULL;
	while (q->front!=NULL)//�����ͷ������Ϊ��,�Ͳ���ִ����
	{	
			tmp = q->front;
			q->front = q->front->next;
			free(tmp);
	}
	q->rear = NULL;//��βָ��Ҳ��Ϊ��,�����ΪҰָ�벻��ȫ
}