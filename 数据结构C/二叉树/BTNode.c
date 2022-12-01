#define _CRT_SECURE_NO_WARNINGS 1
#include "BTNode.h"
// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
BTNode* BinaryTreeCreate(BTDataType* a, int*n)
{	
	if (a[*n] == '#'||a[*n]=='\0')
	{
		(* n)++;
		return NULL;
	}
	BTNode*pi= (BTNode*)malloc(sizeof(BTNode));
	pi->data = a[( * n)++];
	pi->left=BinaryTreeCreate(a, n);
	pi->right=BinaryTreeCreate(a, n);
	return pi;
}
BTNode* pBinaryTreeCreate(BTDataType* a, int* n)
{
	BTNode* tree = BinaryTreeCreate(a, n);
	if (a[*n] != '\0')
		printf("��⵽��������鲻��ȫ��Ԫ�ع��ɶ�����,ֻ�����Թ��ɵĲ��ֽ����˹���\n");
	else
		printf("�Ѹ���ǰ���������������:\n");
	return tree;
}
// ����������
void BinaryTreeDestory(BTNode**root)
{
	if (!(*root))
		return;
	BinaryTreeDestory(&( *root)->left);
	BinaryTreeDestory(&( * root)->right);
	free(*root);
	*root = NULL;
}
// �������ڵ����
int BinaryTreeSize(BTNode* root)
{	
	return root == NULL ? 0 : BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}
// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root)
{
	if (!root)
		return NULL;
	return !root->left && !root->right ? 1 :
		BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}
// ��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
		return NULL;
	if (k == 1)
		return 1;
	else if (k > 1)
		return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
	else
	{
		printf("����,�ڶ�������Ӧ����0\n");
		return NULL;
	}
}
// ����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (!root)
		return NULL;
	if (root->data == x)
		return root;
	BTNode* p = BinaryTreeFind(root->left, x);
	if (p != NULL)
		return p;
	else
		return BinaryTreeFind(root->right, x);
}
// ������ǰ����� 
void BinaryTreePrevOrder(BTNode* root)
{
	if (!root)
		return;
	printf("%8c", root->data);
	BinaryTreePrevOrder(root->left);
	BinaryTreePrevOrder(root->right);
}
// �������������
void BinaryTreeInOrder(BTNode* root)
{
	if (!root)
		return;
	BinaryTreePrevOrder(root->left);
	printf("%8c", root->data);
	BinaryTreePrevOrder(root->right);
}
// �������������
void BinaryTreePostOrder(BTNode* root)
{
	if (!root)
		return;
	BinaryTreePrevOrder(root->left);
	BinaryTreePrevOrder(root->right);
	printf("%8c", root->data);
}
typedef BTNode* BTDataType1;
typedef struct
{
	BTDataType1 data[4096];
	int	front, rear;
}Squeue;
void enQueue(Squeue* q,BTDataType1 e)
{
	if ((q->rear + 1) % 4096 == q->front)
		exit(-1);
	q->rear = (q->rear + 1) % 4096;
	q->data[q->rear] = e;
}
BTDataType1 deQueue(Squeue* q)
{
	if (q->front == q->rear)
		exit(-1);
	q->front = (q->front + 1) % 4096;
	return q->data[q->front];
}
// �������
void BinaryTreeLevelOrder(BTNode* root)
{
	Squeue *q=(Squeue*)malloc(sizeof(Squeue));
	q->front = 0;
	q->rear = 0;
	enQueue(q,root);
	while (q->front != q->rear)
	{
		BTNode* p = deQueue(q);
		printf("%8c", p->data);
		if (p->left != NULL)
			enQueue(q, p->left);
		if (p->right != NULL)
			enQueue(q, p->right);
	}
	free(q);
}
// �ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(BTNode* root)
{
	Squeue* q = (Squeue*)malloc(sizeof(Squeue));
	q->front = 0;
	q->rear = 0;
	enQueue(q, root);
	while (q->front != q->rear)
	{
		BTNode* p = deQueue(q);
		if (p == NULL)
			break;
		enQueue(q, p->left);
		enQueue(q, p->right);
	}
	while (q->front != q->rear)
	{
		if (deQueue(q) != NULL)
		{	
			free(q);
			return 0;
		}
	}
	free(q);
	return 1;
}