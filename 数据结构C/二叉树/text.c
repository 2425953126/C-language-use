#define _CRT_SECURE_NO_WARNINGS 1
#include "BTNode.h"
void text(char* a)
{	
	int n = 0;
	BTNode* tree = pBinaryTreeCreate(a, &n);
	BinaryTreePrevOrder(tree);
	printf("\n������Ϊ:%d\n", BinaryTreeSize(tree));
	printf("Ҷ�ӽ�����Ϊ%d\n", BinaryTreeLeafSize(tree));
	printf("�����������Ϊ%d\n", BinaryTreeLevelKSize(tree,3));
	if (BinaryTreeFind(tree, 'G') != NULL)
		printf("�ҵ���ֵΪ%c�Ľ��\n", 'G');
	else
		printf("δ�ҵ�ֵΪ % c�Ľ��\n", 'G');
	printf("�������:\n");
	BinaryTreeInOrder(tree);
	printf("\n�������:\n");
	BinaryTreePostOrder(tree);
	putchar('\n');
	printf("\n�������:\n");
	BinaryTreeLevelOrder(tree);
	if (BinaryTreeComplete(tree))
		printf("\n����ȫ������\n");
	else
		printf("\n������ȫ������\n");
	printf("\n���ٶ�����......\n");
	BinaryTreeDestory(&tree);
	if (tree == NULL)
		printf("#���ٳɹ�\n");
}
int main()
{
	char a [] = "ABD##E#H##CF##G##";
	text(a);
	return NULL;
}
