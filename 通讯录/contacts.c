#define _CRT_SECURE_NO_WARNINGS 1
#include "contacts.h"
void Initcontact(Contact*p)
{	
	memset(p, 0, sizeof(*p));
}
int Addcontact(Contact* p)
{
	if (p->size >= Max_datasize)
	{
		puts("ͨѶ¼�������޷��������\n");	//���մ� �� 20 17751111786 ����˹��
		return 0;
	}
	puts("������������ϵ�˵��������Ա����䡢�绰����͵�ַ���ÿո���������磺���� �� 22 1831111111 ������԰32��101\n");
	puts("Please input:");
	while (1)
	{	
		scanf("%s", p->data[p->size].name);
		if (strcmp(p->data[p->size].name, "0") == 0)
			break;
		scanf("%s %hd %s %s", p->data[p->size].sex, &(p->data[p->size].age), p->data[p->size].tel, p->data[p->size].addr);
		p->size++;
		puts("\n#��ӳɹ�\n");
		puts("������ӣ�����0��ֹ����\n");
	}
	return 1;
}
void Printfs(const Contact*p)
{
	int i;
	printf("\n	%-15s %-10s %-10s %-20s %-50s\n", "����", "�Ա�", "����", "�绰", "��ַ");
	for(i=0;i<p->size;i++)
	{ 
		printf("	%-15s %-10s %-10hd %-20s %-50s\n", p->data[i].name, p->data[i].sex,p->data[i].age, p->data[i].tel, p->data[i].addr);
	}
	puts("\n\n\n\n");
}
int find(Contact* p,char name[])
{
	int i = 0;
	for (i = 0; i < p->size; i++)
	{
		if (strcmp(p->data[i].name, name) == 0)
			return i;
	}
	return -1;
}
int deletes(Contact* p) 
{
	if (p->size <= 0)
	{
		puts("ͨѶ¼�ѿգ�");
		return 0;
	}
	char name1[Max_namesize]={0};
	int i=0;
	puts("������Ҫɾ������ϵ��������\n");
	getchar();
	gets(name1);
	i=find(p,name1);
	if (i == -1)
	{
		puts("����Ҫɾ������ϵ�˲�����\n");
		return 0;
	}
	for (; i-1 < p->size; i++)
	{
		strcpy(p->data[i].name, p->data[i + 1].name);
		strcpy(p->data[i].sex, p->data[i + 1].sex);
		p->data[i].age = p->data[i + 1].age;
		strcpy(p->data[i].tel, p->data[i + 1].tel);
		strcpy(p->data[i].addr, p->data[i + 1].addr);
	}
	p->size--;
	puts("\n#ɾ���ɹ�\n\n\n");
	return 1;
}
int searchs(Contact* p)
{
	int i;
	char name1[Max_namesize] = { 0 };
	puts("������Ҫ���ҵ���ϵ��������\n");
	getchar();
	gets(name1);
	i = find(p, name1);
	if (i == -1)
	{
		puts("����Ҫ���ҵ���ϵ�˲�����\n");
		return 0;
	}
	printf("����:%s\n�Ա�%s\n���䣺%hd\n���룺%s\n��ַ��%s\n\n\n", p->data[i].name, p->data[i].sex, p->data[i].age, p->data[i].tel, p->data[i].addr);
	return 1;
}
int modifys(Contact* p)
{
	int i;
	char name1[Max_namesize] = { 0 };
	puts("�������޸������ϵ��������\n");
	getchar();
	gets(name1);
	i = find(p, name1);
	if (i == -1)
	{
		puts("�����޸������\n");
		return 0;
	}
	printf("����:%s\n�Ա�%s\n���䣺%hd\n���룺%s\n��ַ��%s\n\n\n", p->data[i].name, p->data[i].sex, p->data[i].age, p->data[i].tel, p->data[i].addr);
	puts("������������ϵ�˵��������Ա����䡢�绰����͵�ַ���ÿո���������磺���� �� 22 1831111111 ������԰32��101\n");
	puts("Please input:");
	scanf("%s %s %hd %s %s", p->data[i].name, p->data[i].sex, &(p->data[i].age), p->data[i].tel, p->data[i].addr);
	puts("\n#�޸ĳɹ�\n");
	return 1;
}
int cmp(const void* a, const void* b)
{
	/*Peoinfo* p1 = a;
	Peoinfo* p2 = b;
	int i = 0;
	i = strcmp(p1->name, p2->name);
	return i;*/
	return (strcmp((*(Peoinfo*)a).name, (*(Peoinfo*)b).name));
}
void sorts(Contact* p)
{
	int (*pcmp)(const void*, const void*)=cmp;
	qsort(p->data, p->size, sizeof(p->data[0]),pcmp);
	puts("�������\n\n\n");
}