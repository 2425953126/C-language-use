#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
int M, N, S;
void Intiboard(char* chesbo, int row, int col);//��ʽ������
void Displayboard(char* chesbo, int row, int col);//չʾ����
int playermove(char* chesbo, int row, int col);//����ж�
void computermove(char* chesbo, int row, int col);//�����ж�
char Is_win1(char* chesbo, int row, int col);//�ж���Ӯ
char Is_win2(char* chesbo, int row, int col);
void game1();//��Ϸ��������
void game2();