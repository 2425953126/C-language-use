#define _CRT_SECURE_NO_WARNINGS 1
#include "BTNode.h"
// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
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
		printf("检测到给予的数组不能全部元素构成二叉树,只将可以构成的部分进行了构建\n");
	else
		printf("已根据前序遍历构建二叉树:\n");
	return tree;
}
// 二叉树销毁
void BinaryTreeDestory(BTNode**root)
{
	if (!(*root))
		return;
	BinaryTreeDestory(&( *root)->left);
	BinaryTreeDestory(&( * root)->right);
	free(*root);
	*root = NULL;
}
// 二叉树节点个数
int BinaryTreeSize(BTNode* root)
{	
	return root == NULL ? 0 : BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}
// 二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* root)
{
	if (!root)
		return NULL;
	return !root->left && !root->right ? 1 :
		BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}
// 二叉树第k层节点个数
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
		printf("错误,第二个参数应大于0\n");
		return NULL;
	}
}
// 二叉树查找值为x的节点
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
// 二叉树前序遍历 
void BinaryTreePrevOrder(BTNode* root)
{
	if (!root)
		return;
	printf("%8c", root->data);
	BinaryTreePrevOrder(root->left);
	BinaryTreePrevOrder(root->right);
}
// 二叉树中序遍历
void BinaryTreeInOrder(BTNode* root)
{
	if (!root)
		return;
	BinaryTreePrevOrder(root->left);
	printf("%8c", root->data);
	BinaryTreePrevOrder(root->right);
}
// 二叉树后序遍历
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
// 层序遍历
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
// 判断二叉树是否是完全二叉树
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