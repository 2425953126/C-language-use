#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
extern int M, N, S;
void Intiboard(char* chesbo, int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++)
			*(chesbo + i * col+ j) =32;
}
void Displayboard(char* chesbo, int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf("  %c  ", *(chesbo + i * N + j));
			if(j<col-1)
				printf("|");
		}
		putchar(10);
		for (j = 0; j < col; j++)
				{	if(i<row-1)
						printf("_ _ _", *(chesbo + i * N + j));
					else
						printf("     ", *(chesbo + i * N + j));
					if (j < col - 1)
						printf("|");
				}
			putchar(10);
	}
}
int playermove(char*chesbo,int row,int col)
{
	int i, j;
	int m, n;
	printf("Please input:");
	while (1)
	{
		scanf("%d", &m);
		if (m == 0)
		{
			puts("退出当前游戏！");
			return 1;
		}
		scanf("%d", &n);
		if (m > 0 && m <= row && n > 0 && n <= col)
		{
			if (*(chesbo + (m - 1) * col+ n - 1) == 32)
			{
				*(chesbo + (m - 1) * col+ n - 1) = '*'; break;
			}
			else
				printf("格子被占用，请重新输入");
		}
		else
			printf("输入错误，请重新输入");
	}
	return 0;
}
int pj(char chesbo[10][10], int row, int col)//判断平局
{
	int i, j;
	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++)
			if (chesbo[i][j] != 32)
				return 0;
	return 1;
}
void computermove(char*chesbo,int row,int col)
{
	int x, y;
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (*(chesbo + x * row + y) == 32)
		{
			*(chesbo + x * row + y) = '#'; break;
		}
	}
}

char Is_win1(char chesbo[][3], int row, int col)
{
	int i,j,count;
	for (i = 0,count=1; i < row; i++,count=1)//判断行连棋
	{
		for (j = 0; j <col-1; j++)
		{
			if ((chesbo[i][j] == chesbo[i][j + 1]) && chesbo[i][j] != 32)
			{
				count++;
				if (count == S)
					return chesbo[i][j];
			}
			else count = 1;
		}
	}
	for (j = 0,count=1; j < col; j++,count=1)//判断列连棋
	{
		for (i = 0; i < row-1 ; i++)
		{
			if ((chesbo[i][j] == chesbo[i+1][j]) && chesbo[i][j] != 32)
			{
				count++;
				if (count == S)
					return chesbo[i][j];
			}
			else count = 1;
		}
	}
	int x;
	for (i = S - 1,count=1; i < row;i++,count=1)//从左斜向下，上半部分
	{
			for (x=i,j = 0; x>=0&&j <= i; x--,j++)
			{
				if((chesbo[x][j]==chesbo[x-1][j+1])&&chesbo[x][j]!=32)
				{
					count++;
					if (count == S)
						return chesbo[x][j];
				}
				else count = 1;
			}
	}
	int y ;
	for (j = col - S, count = 1; j > 0; j--,count=1)//从左斜向下，下半部分
	{
			for(y=j,i=row-1;y<col&&i>=1;y++,i--)
		{
			if((chesbo[i][y]==chesbo[i-1][y+1])&&chesbo[i][y]!=32)
			{
				count++;
				if (count == S)
					return chesbo[x][j];
			}
			else count = 1;
		}
	}
	int count2;
	for (i = row-S, count = 1,count2=1; i>=0; i--,count=1,count2=1)//从右斜向上
	{
			for (x=i,j = 0; x<row&&j<row-i ; x++,j++)
			{
				if ((chesbo[x][j] == chesbo[x+1][j+1]) && chesbo[x][j] != 32)
				{
					count++;
					if (count == S)
						return chesbo[x][j];
				}
				else count = 1;
				
				if ((chesbo[j][x] == chesbo[j+1][x+1]) && chesbo[j][x] != 32)
				{
					count2++;
					if (count2 == S)
						return chesbo[j][x];
				}
				else count2 = 1;
			}
	}
	if (pj(chesbo, row, col))
		return 'Q';
	return 'C';
}
char Is_win2(char chesbo[][10], int row, int col)
{
	int i, j, count;
	for (i = 0, count = 1; i < row; i++, count = 1)//判断行连棋
	{
		for (j = 0; j <= col-1; j++)
		{
			if ((chesbo[i][j] == chesbo[i][j + 1]) && chesbo[i][j] != 32)
			{
				count++;
				if (count == S)
					return chesbo[i][j];
			}
			else count = 1;
		}
	}
	for (j = 0, count = 1; j < col; j++, count = 1)//判断列连棋
	{
		for (i = 0; i <= row -1; i++)
		{
			if ((chesbo[i][j] == chesbo[i + 1][j]) && chesbo[i][j] != 32)
			{
				count++;
				if (count == S)
					return chesbo[i][j];
			}
			else count = 1;
		}
	}
	int x;
	for (i = S - 1, count = 1; i < row; i++, count = 1)//从左斜向下，上半部分
	{
		for (x = i, j = 0; x >= 0 && j <= i; x--, j++)
		{
			if ((chesbo[x][j] == chesbo[x - 1][j + 1]) && chesbo[x][j] != 32)
			{
				count++;
				if (count == S)
					return chesbo[x][j];
			}
			else count = 1;
		}
	}
	int y;
	for (j = col - S, count = 1; j > 0; j--, count = 1)//从左斜向下，下半部分
	{
		for (y = j, i = row - 1; y < col && i >= 1; y++, i--)
		{
			if ((chesbo[i][y] == chesbo[i - 1][y + 1]) && chesbo[i][y] != 32)
			{
				count++;
				if (count == S)
					return chesbo[x][j];
			}
			else count = 1;
		}
	}
	int count2;
	for (i = row - S, count = 1, count2 = 1; i >= 0; i--, count = 1, count2 = 1)//从右斜向上
	{
		for (x = i, j = 0; x < row && j < row - i; x++, j++)
		{
			if ((chesbo[x][j] == chesbo[x + 1][j + 1]) && chesbo[x][j] != 32)
			{
				count++;
				if (count == S)
					return chesbo[x][j];
			}
			else count = 1;

			if ((chesbo[j][x] == chesbo[j + 1][x + 1]) && chesbo[j][x] != 32)
			{
				count2++;
				if (count2 == S)
					return chesbo[j][x];
			}
			else count2 = 1;
		}
	}
	if (pj(chesbo, row, col))
		return 'Q';
	return 'C';
}
void game1()
{
	char ret=0;
	char chesbo[3][3] = {0};
	srand((unsigned int)time(0));
	Intiboard(chesbo, M, N);//初始化棋盘
	Displayboard(chesbo, M, N);//打印棋盘
	while(1)
	{
		if(playermove(chesbo, M, N)==1)
			break;
		ret = Is_win1(chesbo, M, N);
		if (ret != 'C')
		{
			if (ret == 'Q')
			{
				puts("\n游戏结束，和棋！"); Displayboard(chesbo, M, N);  break;
			}
			else
			{
				printf("\n游戏结束，%c赢了！！\n", ret); Displayboard(chesbo, M, N); break;
			}
		}
		printf("Computer input：\n");
		computermove(chesbo, M, N);
		ret = Is_win1(chesbo, M, N);
		if (ret != 'C')
		{
			if (ret == 'Q')
			{
				puts("\n游戏结束，和棋！"); Displayboard(chesbo, M, N); break;
			}
			else
			{
				printf("\n游戏结束，%c赢了！！\n", ret); Displayboard(chesbo, M, N); break;
			}
		}
		Displayboard(chesbo, M, N);
	}
}
void game2()
{
	char ret = 0;
	char chesbo[10][10] = { 0 };
	srand((unsigned int)time(0));
	Intiboard(chesbo, M, N);//初始化棋盘
	Displayboard(chesbo, M, N);//打印棋盘
	while (1)
	{
		if (playermove(chesbo, M, N) == 1)
			break;
		ret = Is_win2(chesbo, M, N);
		if (ret != 'C')
		{
			if (ret == 'Q')
			{
				puts("\n游戏结束，和棋！"); Displayboard(chesbo, M, N);  break;
			}
			else
			{
				printf("\n游戏结束，%c赢了！！\n", ret); Displayboard(chesbo, M, N); break;
			}
		}
		printf("Computer input：\n");
		computermove(chesbo, M, N);
		ret = Is_win2(chesbo, M, N);
		if (ret != 'C')
		{
			if (ret == 'Q')
			{
				puts("\n游戏结束，和棋！"); Displayboard(chesbo, M, N); break;
			}
			else
			{
				printf("\n游戏结束，%c赢了！！\n", ret); Displayboard(chesbo, M, N); break;
			}
		}
		Displayboard(chesbo, M, N);
	}
}