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
		puts("	�� ��					1.��ʼ��		2.��ӡ\n");
		puts("	ӭ ��					3.����			4.�޸�\n");
		puts("	ʹ ��					5.ͷ��			6.β��\n");
		puts("	�� ��					7.ͷɾ			8.βɾ\n");
		puts("	�� ��					9.����			10.ɾ��\n");
		puts("	˳  !						    0.�˳�		  \n");
		puts("#�����빦�����:\n");
		scanf("%d", &input);
		int flag = 1;
		switch (input)
		{
		case 1:SeqListInit(ps, filename); break;
		case 2:SeqListPrint(ps); break;
		case 3:
		{
			printf("#������Ҫ�Ӳ��ҵ�Ԫ��:)\n");
			SLDataType x = 0;
			DataTypeJudge(&x, 0);
			SeqListFind(ps, x);
		}
			break;
		case 4:
		{	
			printf("#������Ҫ�޸ĵ�Ԫ�ص���ź��޸�ֵ:\n");
			scanf("%d", &pos);
			SLDataType x = 0;
			DataTypeJudge(&x, 0);
			SeqListModify(ps, pos, x);
		}
			break;
		case 5:
		{
			printf("#������Ҫ��ͷ�������,��$��β(���Ҫ����$,ֻ����$Ϊ��������ĵ�һ���ַ�ʱ�Ż����)\n");
			while (1)
			{
				SLDataType x = 0;
				DataTypeJudge(&x, 0);
				SeqListPushFront(ps, x);
				if (getchar() == '$')
					break;
			}
			printf("#����ɹ�\n");
			break;
		}
		case 6:
			printf("#������Ҫ��β�������,��$��β(���Ҫ����$,ֻ����$Ϊ��������ĵ�һ���ַ�ʱ�Ż����)\n");
			while (1)
			{
				SLDataType x = 0;
				DataTypeJudge(&x, 0);
				SeqListPushBack(ps, x);
				if (getchar() == '$')
					break;
			}
			printf("#����ɹ�\n");
			break;
		case 7:
		{	
			printf("#������Ҫ��ͷ��ʼɾ��Ԫ�صĸ���:)\n");
			scanf("%d", &pos);
			while(pos--)
				SeqListPopFront(ps);
		}
		printf("#ɾ���ɹ�\n");
			break;
		case 8: 
		{
			printf("#������Ҫ��β��ʼɾ��Ԫ�صĸ���:)\n");
			scanf("%d", &pos);
			while (pos--)
				SeqListPopBack(ps);
		}
		printf("#ɾ���ɹ�\n");
			 break;
		case 9:
		{
			printf("#������Ҫ�����������λ��:)\n");
			SLDataType x = 0;
			DataTypeJudge(&x, 0);
			scanf("%d", &pos);
			flag=SeqListInsert(ps, pos, x);
		}
		if(flag!=EOF)
			printf("#����ɹ�\n");
			break;
		case 10:
		{
			printf("#������Ҫɾ��������λ��:)\n");
			scanf("%d", &pos);
			flag=SeqListErase(ps, pos);
		}
		if (flag != EOF)
			printf("#ɾ���ɹ�\n");
			break;
		case 0:printf("#�˳����ݿ�\n"); SeqListDestroy(ps, filename); break;
		default:printf("#�����������������:\n");
			break;
		}
	} while (input);
}
int main()
{	
	system("color F1");
	SeqList Database_1;
	char filename[255] = {0};
	printf("������Ҫ���������ݿ�����������׺������\n");
	gets(filename);
	SLmenu(&Database_1,filename);
	return 0;
}
