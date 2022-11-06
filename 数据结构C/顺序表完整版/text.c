#define _CRT_SECURE_NO_WARNINGS 1
#include "seqlist.h"
void SLmenu(SeqList* ps, char* filename)
{
	int input = 0;
	int pos = 0;
	do
	{
		putchar('\n');
		puts("************************************************************************************************************************\n");
		puts("	欢 序					1.初始化		2.打印\n");
		puts("	迎 表					3.查找			4.修改\n");
		puts("	使 数					5.头插			6.尾插\n");
		puts("	用 据					7.头删			8.尾删\n");
		puts("	本 库					9.插入			10.删除\n");
		puts("	顺  !						    0.退出		  \n");
		puts("#请输入功能序号:\n");
		scanf("%d", &input);
		int flag = 1;
		switch (input)
		{
		case 1:SeqListInit(ps, filename); break;
		case 2:SeqListPrint(ps); break;
		case 3:
		{
			printf("#请输入要从查找的元素:)\n");
			SLDataType x = 0;
			DataTypeJudge(&x, 0);
			SeqListFind(ps, x);
		}
			break;
		case 4:
		{	
			printf("#请输入要修改的元素的序号和修改值:\n");
			scanf("%d", &pos);
			SLDataType x = 0;
			DataTypeJudge(&x, 0);
			SeqListModify(ps, pos, x);
		}
			break;
		case 5:
		{
			printf("#请输入要从头插入的数,以$结尾(如果要输入$,只有以$为本次输入的第一个字符时才会读入)\n");
			while (1)
			{
				SLDataType x = 0;
				DataTypeJudge(&x, 0);
				SeqListPushFront(ps, x);
				if (getchar() == '$')
					break;
			}
			printf("#插入成功\n");
			break;
		}
		case 6:
			printf("#请输入要从尾插入的数,以$结尾(如果要输入$,只有以$为本次输入的第一个字符时才会读入)\n");
			while (1)
			{
				SLDataType x = 0;
				DataTypeJudge(&x, 0);
				SeqListPushBack(ps, x);
				if (getchar() == '$')
					break;
			}
			printf("#插入成功\n");
			break;
		case 7:
		{	
			printf("#请输入要从头开始删除元素的个数:)\n");
			scanf("%d", &pos);
			while(pos--)
				SeqListPopFront(ps);
		}
		printf("#删除成功\n");
			break;
		case 8: 
		{
			printf("#请输入要从尾开始删除元素的个数:)\n");
			scanf("%d", &pos);
			while (pos--)
				SeqListPopBack(ps);
		}
		printf("#删除成功\n");
			 break;
		case 9:
		{
			printf("#请输入要插入的数及其位置:)\n");
			SLDataType x = 0;
			DataTypeJudge(&x, 0);
			scanf("%d", &pos);
			flag=SeqListInsert(ps, pos, x);
		}
		if(flag!=EOF)
			printf("#插入成功\n");
			break;
		case 10:
		{
			printf("#请输入要删除的数的位置:)\n");
			scanf("%d", &pos);
			flag=SeqListErase(ps, pos);
		}
		if (flag != EOF)
			printf("#删除成功\n");
			break;
		case 0:printf("#退出数据库\n"); SeqListDestroy(ps, filename); break;
		default:printf("#输入错误，请重新输入:\n");
			break;
		}
	} while (input);
}
int main()
{	
	system("color F1");
	SeqList Database_1;
	char filename[255] = {0};
	printf("请输入要操作的数据库名（包括后缀名）：\n");
	gets(filename);
	SLmenu(&Database_1,filename);
	return 0;
}
