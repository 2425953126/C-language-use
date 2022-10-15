#define _CRT_SECURE_NO_WARNINGS 1
#include "contacts.h"
void Page()
{
	puts("####################################################\n");
	puts("##  ****** 1.add    ********* 2.delete *********  ##\n");
	puts("##                                                ##\n");
	puts("##  ****** 3.search ********* 4.modify *********  ##\n");
	puts("##                                                ##\n");
	puts("##  ****** 5.sort   ********* 6.printf *********  ##\n");
	puts("##                   0.exit                       ##\n");
	puts("####################################################\n");
	puts("\n#Please   input:\n");
}
void working(Contact *p)
{	
	int input = 0;	
	Initcontact(p);
	do
	{
		Page();
		scanf("%d", &input);
		switch (input)
		{
		case Add: Addcontact(p);
				break;
		case Delete:deletes(p);
				break;
		case Search:searchs(p);
				break;
		case Modify:modifys(p);
				break;
		case Sort:sorts(p);
				break;
			case Printf: Printfs(p);
				break;
			case Exit:puts("退出通讯录\n");
				break;
			default:
				puts("输入错误，请重新输入：\n");	
			break;
		}
	} while (input);
}
int main()
{
	Contact number1;
	working(&number1);
}