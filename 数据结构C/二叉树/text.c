#define _CRT_SECURE_NO_WARNINGS 1
#include "BTNode.h"
void text(char* a)
{	
	int n = 0;
	BTNode* tree = pBinaryTreeCreate(a, &n);
	BinaryTreePrevOrder(tree);
	printf("\n结点个数为:%d\n", BinaryTreeSize(tree));
	printf("叶子结点个数为%d\n", BinaryTreeLeafSize(tree));
	printf("第三层结点个数为%d\n", BinaryTreeLevelKSize(tree,3));
	if (BinaryTreeFind(tree, 'G') != NULL)
		printf("找到了值为%c的结点\n", 'G');
	else
		printf("未找到值为 % c的结点\n", 'G');
	printf("中序遍历:\n");
	BinaryTreeInOrder(tree);
	printf("\n后序遍历:\n");
	BinaryTreePostOrder(tree);
	putchar('\n');
	printf("\n层序遍历:\n");
	BinaryTreeLevelOrder(tree);
	if (BinaryTreeComplete(tree))
		printf("\n是完全二叉树\n");
	else
		printf("\n不是完全二叉树\n");
	printf("\n销毁二叉树......\n");
	BinaryTreeDestory(&tree);
	if (tree == NULL)
		printf("#销毁成功\n");
}
int main()
{
	char a [] = "ABD##E#H##CF##G##";
	text(a);
	return NULL;
}
