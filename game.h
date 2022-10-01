#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
int M, N, S;
void Intiboard(char* chesbo, int row, int col);//格式化棋盘
void Displayboard(char* chesbo, int row, int col);//展示棋盘
int playermove(char* chesbo, int row, int col);//玩家行动
void computermove(char* chesbo, int row, int col);//电脑行动
char Is_win1(char* chesbo, int row, int col);//判断输赢
char Is_win2(char* chesbo, int row, int col);
void game1();//游戏运行主体
void game2();