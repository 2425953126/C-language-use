#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define Max_namesize 20
#define Max_datasize 1000
typedef struct Peoinfo
{
	char name[Max_namesize];
	char sex[10];
	 short int age;
	 char tel[20];
	 char addr[50];
}Peoinfo;
typedef struct Contact
{
	Peoinfo data[Max_datasize];
	int size;
}Contact;
enum opt
{
	Add = 1,
	Delete,
	Search,
	Modify,
	Sort,
	Printf,
	Exit=0,
};
void Initcontact(Contact* p);											//��ʼ��
int Addcontact(Contact* p);												//�����ϵ��
void Printfs(const Contact* p);											//��ӡ
int searchs(Contact* p);												//����
int deletes(Contact* p);												//ɾ��
void sorts(Contact* p);													//��������ͨѶ¼