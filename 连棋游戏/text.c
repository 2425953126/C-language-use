#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
extern int M, N, S;
void menu()
{
	printf("*********************************\n");
	printf("*********************************\n");
	printf("************1.������*************\n");
	printf("************2.������*************\n");
	printf("***********0.�˳���Ϸ************\n");
	printf("*********************************\n");
	printf("*********************************\n");
}
void text()
{
	int input = 0;
	do
	{
		menu();
		printf("��ѡ������1��ʼ�����壬����2��ʼ�����壬����0�˳���Ϸ\n");
		scanf("%d", &input);
		puts("\n(����0�ص�ѡ�����)");
		switch (input)
		{
		case 1:puts("��ʼ������\n"); M = N = S = 3; game1(); break;
		case 2:puts("��ʼ������\n"); M = N = 10, S = 5; game2(); break;
		case 0:puts("�˳���Ϸ\n"); break;
		default:puts("�������\n"); break;
		}

	}
	while (input);
}
int main()
{
	system("color 70");
	text();
	return 0;
}