#include "contacts.h"
void capacity_expansion(Contact* p)									//扩容
{
	Peoinfo* p1 = p->data;
	p1 = (Peoinfo*)realloc(p1, (p->capacity + 2) * sizeof(Peoinfo));
	if (p1 == NULL)
	{
		perror("Expand capacity");
		return;
	}
	p->data = p1;
	p->capacity += 2;
}
void Initcontact(Contact*p)
{
	p->capacity = Max_Initsize;
	p->size = 0;
	Peoinfo* p1 = p->data;
	p1 = (Peoinfo*)malloc(sizeof(Peoinfo) * Max_Initsize);
	if (p1 == NULL)
	{
		perror("Initcontact malloc");
		return;
	}
	memset(p1, 0, sizeof(Peoinfo)* Max_Initsize);
	p->data = p1;
	FILE* contactbook =NULL;
	if ((contactbook=fopen("contactbook.txt","ab+"))==NULL)
	{
		perror("Contactbook fopen");
		return;
	}
	Peoinfo tmp = { 0 };
	while (fread(&tmp, sizeof(Peoinfo), 1, contactbook))
	{
		if (p->size == p->capacity)
		{
			capacity_expansion(p);	//大苏打 男 20 17751111786 阿迪斯的
		}
		p->data[p->size] = tmp;
		p->size++;	
	}
	fclose(contactbook);
	contactbook = NULL;
}
int Addcontact(Contact* p)
{
	if (p->size==p->capacity)
	{
		capacity_expansion(p);	//大苏打 男 20 17751111786 阿迪斯的
	}
	puts("请依次输入联系人的姓名、性别、年龄、电话号码和地址，用空格隔开，例如：张三 男 22 1831111111 新区花园32栋101\n");
	puts("Please input:");
	while (1)
	{	
		if (p->size == p->capacity)
		{
			capacity_expansion(p);	
		}
		scanf("%s", p->data[p->size].name);
		if (strcmp(p->data[p->size].name, "0") == 0)
			break;
		scanf("%s %hd %s %s", p->data[p->size].sex, &(p->data[p->size].age), p->data[p->size].tel, p->data[p->size].addr);
		p->size++;
		puts("\n#添加成功\n");
		puts("继续添加（输入0终止）：\n");
	}
	return 1;
}
void Printfs(const Contact*p)
{
	int i;
	printf("\n	%-15s %-10s %-10s %-20s %-50s\n", "姓名", "性别", "年龄", "电话", "地址");
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
void capacity_reduce(Contact*p)									//减容
{
	Peoinfo* p1 = p->data;
	p1 = (Peoinfo*)realloc(p1, (p->capacity-1) * sizeof(Peoinfo));
	if (p1 == NULL)
	{
		perror("Reduce capacity");
		return;
	}
	p->data = p1;
	p->capacity -= 1;
	puts("\n#空间已回收\n");
}
int deletes(Contact* p) 
{
	if (p->size <= 0)
	{
		puts("通讯录已空！");
		return 0;
	}
	char name1[Max_namesize]={0};
	int i=0;
	puts("请输入要删除的联系人姓名：\n");
	getchar();
	gets(name1);
	i=find(p,name1);
	if (i == -1)
	{
		puts("错误，要删除的联系人不存在\n");
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
	capacity_reduce(p);
	puts("\n#删除成功\n\n\n");
	return 1;
}
int searchs(Contact* p)
{
	int i;
	char name1[Max_namesize] = { 0 };
	puts("请输入要查找的联系人姓名：\n");
	getchar();
	gets(name1);
	i = find(p, name1);
	if (i == -1)
	{
		puts("错误，要查找的联系人不存在\n");
		return 0;
	}
	printf("姓名:%s\n性别：%s\n年龄：%hd\n号码：%s\n地址：%s\n\n\n", p->data[i].name, p->data[i].sex, p->data[i].age, p->data[i].tel, p->data[i].addr);
	return 1;
}
int modifys(Contact* p)
{
	int i;
	char name1[Max_namesize] = { 0 };
	puts("请输入修改项的联系人姓名：\n");
	getchar();
	gets(name1);
	i = find(p, name1);
	if (i == -1)
	{
		puts("错误，修改项不存在\n");
		return 0;
	}
	printf("姓名:%s\n性别：%s\n年龄：%hd\n号码：%s\n地址：%s\n\n\n", p->data[i].name, p->data[i].sex, p->data[i].age, p->data[i].tel, p->data[i].addr);
	puts("请依次输入联系人的姓名、性别、年龄、电话号码和地址，用空格隔开，例如：张三 男 22 1831111111 新区花园32栋101\n");
	puts("Please input:");
	scanf("%s %s %hd %s %s", p->data[i].name, p->data[i].sex, &(p->data[i].age), p->data[i].tel, p->data[i].addr);
	puts("\n#修改成功\n");
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
	puts("排序完成\n\n\n");
}
void DestoryContact(Contact* p)
{
	FILE* contactbook = fopen("contactbook.txt", "wb");
	if (contactbook == NULL)
	{
		perror("Write failed");
		return;
	}
	int i = 0;
	while (i<p->size)
	{	
		fwrite(&p->data[i], sizeof(Peoinfo), 1, contactbook);
		i++;
	}
	fclose(contactbook);
	free(p->data);
	p->data = NULL;
	p->size = 0;
	p->capacity = 0;
}