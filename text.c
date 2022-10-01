#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
extern int M, N, S;
void menu()
{
	printf("*********************************\n");
	printf("*********************************\n");
	printf("************1.井子棋*************\n");
	printf("************2.五子棋*************\n");
	printf("***********0.退出游戏************\n");
	printf("*********************************\n");
	printf("*********************************\n");
}
void text()
{
	int input = 0;
	do
	{
		menu();
		printf("请选择：输入1开始井字棋，输入2开始五子棋，输入0退出游戏\n");
		scanf("%d", &input);
		puts("\n(输入0回到选择界面)");
		switch (input)
		{
		case 1:puts("开始井字棋\n"); M = N = S = 3; game1(); break;
		case 2:puts("开始五子棋\n"); M = N = 10, S = 5; game2(); break;
		case 0:puts("退出游戏\n"); break;
		default:puts("输出错误\n"); break;
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