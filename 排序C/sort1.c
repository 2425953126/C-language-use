#define _CRT_SECURE_NO_WARNINGS 1
#include "sort1.h"
// ��������
void InsertSort(int* a, int n)
{	
	for (int i = 0; i < n; i++)
	{
		int x=a[i],end = i - 1;//endÿ������ָ����ǲ�����Ӧ�������λ�õ�ǰһ��λ��
		while (end >= 0)
		{
			if (x < a[end])//��ǰ���Ѿ��ź����Ԫ�ص����һ��Ԫ�ؿ�ʼ�Ƚ�,�������x��,��ô��������һλ
				a[end + 1] = a[end];
			else
				break;
			end--;
		}
		a[end + 1] = x;
	}
}

// ϣ������
void ShellSort(int* a, int n)
{	
	for (int gap=n/2;gap>0;gap/=2)//����gap��С
	{
		for (int begin = 0; begin < gap; begin++)//���Ʒ���
		{
			for (int i = begin; i < n; i += gap)//ֱ�Ӳ�������
			{
				int end = i - gap;
				int x = a[i];
				while (end >= 0)
				{
					if (x < a[end])
						a[end + gap] = a[end];
					else
						break;
					end -= gap;
				}
				a[end + gap] = x;
			}
		}
	}
}
void Swap(int* a, int* b)//����,ֵ��ע����,����������������ɽ�����,������ʱ��a��b��ָ��ͬһ���ռ�,����򷨽����ͻᵼ�¹���

{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
// ѡ������
void SelectSort(int* a, int n)
{
	int left=0;
	int right=n-1;
	for (; left < right; left++, right--)
	{
		int min = left;
		int max = right;
		for (int i = left; i <= right; i++)//ÿ���ҵ�ʣ��Ԫ���е���Сֵ�����ֵ
		{
			if (a[i] < a[min])
				min = i;
			if (a[i] > a[max])
				max = i;
		}
		Swap(&a[left], &a[min]);
		if (max == left)//��ֹ��ʱ�����ֵ����leftλ����ʱ�ڽ�����СԪ�صĹ�����,������leftλ�õ����Ԫ�ظ��Ƚ�����ԭ����СԪ�ص�λ������,�Ӷ�������λ����
			max = min;
		Swap(&a[right], &a[max]);
	}
}

// ������
void AdjustDwon(int* a, int n, int root)
{
	if (2 * root + 1 >= n)//rootû������(Ҳ�ض�û���Һ���),����
		return;
	int child = 2 * root + 1;
	if (2 * root + 2<n&&a[2 * root + 1] < a[2 * root + 2])//ȷ����ȸ��׽������,�������ӽ���и���Ľ���,�˴�ע��,Ҫ�ж�һ����û���Һ���
		child += 1;
	if (a[root] < a[child])//���µ���
	{
		Swap(&a[root], &a[child]);
		AdjustDwon(a, n, child);
	}
}
void HeapSort(int* a, int n)
{	
	int root = (n - 1 - 1) / 2;//n-1Ϊ���һ��Ҷ�ӽ��,���ĸ��׽���±�Ϊ(n-1-1)/2,�����һ����Ҷ�ӽ��,��ǰ��Ľ���Ϊ��Ҷ�ӽ��
	while (root > 0)//�������;
	{
		AdjustDwon(a, n, root);
		root--;
	}
	for (int i = n - 1; i >= 0; i--)//������
	{
		Swap(&a[0], &a[i]);
		AdjustDwon(a, --n, 0);//���ע��nÿ����Ҫ��1,��Ȼ���µ����㷨�Ͱ�֮ǰ�ŵ�ĩβ�����ֵ�ֵ�������ȥ��
	}
}

// ð������
void BubbleSort(int* a, int n)
{
	for (int i=n-1;i>0;i--)
	{
		int flag = 0;//�����־����
		for (int j = 0; j < i; j++)
		{
			if (a[j] > a[j + 1])
			{
				Swap(&a[j], &a[j + 1]);
				flag = 1;
			}
		}
		if (flag == 0)//������һ��ð�������һ��Ԫ�ؽ�����û�з�����,˵������Ԫ�ؽ�Ϊ����Ҫ��˳���,��ǰ��������
			break;
	}
}

// ��������ݹ�ʵ��
int getkey(int*a,int left,int right)//����ȡ��
{
	int mid = left + ((right - left) >> 1);
	if (a[left] < a[mid])
		if (a[mid] < a[right])
			return mid;
		else if (a[left] < a[right])
			return right;
		else
			return left;
	else
		if (a[mid] > a[right])
			return mid;
		else if (a[left] > a[right])
			return right;
		else
			return left;
}
// ��������hoare�汾
int PartSort1(int* a, int left, int right)
{
	int key = getkey(a, left, right);
	Swap(&a[key], &a[left]);//���������˸���������,�ҵ�key��,a[key]�ֺ�a[left]������λ��,ȴû�а�key��ֵΪleft
	key = left;
	while(left<right)
	{
		while (left<right&&a[right] >= a[key])//����Ҫ�ر�ע����Ҫ��ֹԽ�����ѭ��,������ҪԽ����a[key]��ȵ���,�����������ͬʱ��λ�����������ͻ������ظ�����,��ѭ��
			right--;
		while (left<right&&a[left] <= a[key])
			left++;
		Swap(&a[left], &a[right]);
		if (left == right)
			Swap(&a[key], &a[left]);
	}
	return left;
}
 //���������ڿӷ�
int  PartSort2(int* a, int left, int right)
 {
	int key = getkey(a, left, right);
	Swap(&a[key], &a[left]);
	key = left;
	int tmp = a[key];                                                                                                                                                                              
	while (left < right)
	{
		while (left < right && a[right] >=tmp)//����Ҫ�ر�ע����Ҫ��ֹԽ�����ѭ��,������ҪԽ����a[key]��ȵ���,�����������ͬʱ��λ�����������ͻ������ظ�����,��ѭ��
			right--;
		a[key] = a[right];
		key = right;
		while (left < right && a[left] <= tmp)
			left++;
		a[key] = a[left];
		key = left;
		if (left == right)
			a[left]=tmp;
	}
	return left;
 }
//��������ǰ��ָ�뷨
int PartSort3(int* a, int left, int right)
{
	int key = getkey(a, left, right);
	Swap(&a[key], &a[left]);
	key = left;
	int prev = left, cur = left + 1;
	while (cur <= right)
	{
		while (cur <= right && a[cur] >= a[key])
			cur++;
		if (cur <= right)//�Լ�д��ʱ��ûд���!ʱ��ע��Խ�����!
		{
			Swap(&a[++prev], &a[cur++]);//!!cur�ڽ���������++!!!!!,��Ȼ���´�ѭ��cur����ֱ��ͣ����!
		}								//ɵ��ɵ��ɵ��prev����,�������bug�����Ӻ���!!!!!!!!!!
										//ֻ��cur�ҵ��ɽ���ֵ��ʱ��,prev��������,Ȼ�󽻻�,���cur�ǵ��յ�ֹͣ,prevҲ����,��󽻻�a[key]ʱ,ֵ��Ȼ�Ͳ�����
										//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	}
	Swap(&a[prev], &a[key]);
	return prev;
}
//�ص��Ƽ�:
int PartSort3_supper(int* a, int left, int right)//ǰ��ָ�뷨�Ż���
{
	int key = getkey(a, left, right);
	Swap(&a[key], &a[left]);
	key = left;

	int prev = left, cur = left + 1;
	while (cur <= right)
	{
		if (a[cur] <a[key] &&++prev!=cur)//ԭ����Ϊͨ��ѭ�������Թ�����a[key]�����,�ҵ���a[key]С����,Ȼ�󽻻���ǰ��ȥ;ע���ʱ����Ҫ<=,��Ϊ��a[key]��ȵ���,���ý���λ��
			Swap(&a[prev], &a[cur]);		   //�Ż���Ϊ�ڲ���cur++�ı�����,�����б�a[key]С����,����. �ܽ����,ѭ��������û�б�,
										   //ֻ�����Ϸ������в���cur++������ѭ������ɵ�,���Ż�����,ÿ��cur++��ͳһ������ѭ�����,������д���
		cur++;//��Ϊԭ����,����a[cur]��С���,cur�����+1,���Ӧ����ȡ����++
	}
	Swap(&a[prev], &a[key]);
	return prev;
}
void QuickSort1(int* a, int left, int right)
{	
	if (left >= right)
		return;
	int lastposition= PartSort1(a, left, right); 
	QuickSort1(a, left, lastposition - 1);
	QuickSort1(a, lastposition+1,right);
}
void QuickSort2(int* a, int left, int right)
{
	if (left >= right)
		return;
	int lastposition = PartSort2(a, left, right);
	QuickSort2(a, left, lastposition - 1);
	QuickSort2(a, lastposition + 1, right);
}
//С�����Ż�
void QuickSort3(int* a, int left, int right)
{
	if (left >= right)
		return;
	if (right - left + 1 > 10)
	{
		int lastposition = PartSort3_supper(a, left, right);
		QuickSort3(a, left, lastposition - 1);
		QuickSort3(a, lastposition + 1, right);
	}
	else//���ʣ��Ԫ���������ڵ���10,����ֱ�Ӳ�������
		InsertSort(a + left, right-left+1);
}
void QuickSorttest1(int* a, int left, int right)
{
	if (left >= right)
		return;
	int lastposition = PartSort3(a, left, right);
	QuickSorttest1(a, left, lastposition - 1);
	QuickSorttest1(a, lastposition + 1, right);
}
void QuickSorttest2(int* a, int left, int right)
{
	if (left >= right)
		return;
	int lastposition = PartSort3_supper(a, left, right);
	QuickSorttest2(a, left, lastposition - 1);
	QuickSorttest2(a, lastposition + 1, right);
}
// �������� �ǵݹ�ʵ��
void QuickSortNonR(int* a, int left, int right)
{	
	Stack s;
	StackInit(&s);
	StackPush(&s, left);
	StackPush(&s, right);
	while (!StackEmpty(&s))
	{
		int sright = TopPop(&s);
		int sleft = TopPop(&s);//ע��ջ�Ƚ����������
		int lastposition= PartSort3_supper(a,sleft,sright);//ע��lastposition������Խλ��
		if (lastposition + 1 < sright)
		{
			StackPush(&s, lastposition + 1);
			StackPush(&s, sright);
		}
		if (sleft < lastposition - 1)
		{
			StackPush(&s, sleft);
			StackPush(&s, lastposition - 1);
		}
	}
	StackDestroy(&s);
}

void text()
{
	int i = 0;

	while (i++ < 100)
	{
		int flag = 0;
		printf("%d ", flag);
		flag++;
	}
}
void _MergeSort(int* a, int left, int right, int* tmp)
{
	if (left >= right)
		return;
	int mid = left + ((right - left) >> 1);
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp);
	int i = left, j = mid + 1,k=left;
	while (i <= mid && j <= right)//��ʼ�鲢����
		if (a[i] <= a[j])
			tmp[k++] = a[i++];
		else
			tmp[k++] = a[j++];
	while (i <= mid)//������������ʣ��,��β��
		tmp[k++] = a[i++];
	while (j<=right)//����Ұ�������ʣ��,��β��
		tmp[k++] = a[j++];
	i = left;
	while (i < k)//���������������ԭ����,��Ϊ������Ҫ������һ����ֵ�����,�����������õ����ݴ���ԭ����,����һ���ݹ���Ҳ��tmp��������ȡԪ�صĻ�,����ʱ���źõ�Ԫ���ݴ���������?
		a[i] = tmp[i++];
}
// �鲢����ݹ�ʵ��
void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n); 
	if (tmp == NULL)
		exit(-1);
	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);
}
// �鲢����ǵݹ�ʵ��
void MergeSortNonR(int* a, int n)
{	
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
		exit(-1);
	for (int gap = 1; gap < n; gap *= 2)
	{
		for (int i = 0; i < n; i = i + 2 * gap)
		{	
			int begin1 = i, begin2 = i+gap,j=i;
			while (begin1 < i+gap && begin2 < i + 2 * gap&& begin2 <n)//�������Խ��,begin2�ض�Խ��,begin1����Խ��
			{	
				if (a[begin1] <= a[begin2])//С�ڵ��ڿ��Ա�֤�ȶ���
					tmp[j++] = a[begin1++];
				else
					tmp[j++] = a[begin2++];
			}
			while (begin1 < i+gap&& begin1<n)//�˴�begin1����Խ��!!
				tmp[j++] = a[begin1++]; 
			while (begin2 < i + 2 * gap && begin2 < n)
				tmp[j++] = a[begin2++];
		}
		int s = 0;
		while (s < n)//�����˰�ÿ���źõĽ��������ԭ����
			a[s] = tmp[s++];
	}
}

//��������
void CountSort(int* a, int n)
{
	if (n <= 0)
		return;
	int max = a[0], min = a[0];
	int i = 0;
	while (i < n)
	{
		if (max < a[i])
			max = a[i];
		if (min > a[i])
			min = a[i];
		i++;
	}
	int NegativeCorrect = 0;//��������ֵ,��������������С�����ľ���ֵ,���Խ����еĸ����������Ǹ���
	if (min < 0)
	{
		NegativeCorrect = 0 - min;
		min += NegativeCorrect;
		max += NegativeCorrect;
		if (max + 1 < 0)//������ֵ���������ټ�1,ֵС��0,˵��ԭ���ֵ���ϸ�������ֵ���������,����ʧ��
			exit(-1);
		for (i = 0; i < n; i++)
			a[i] += NegativeCorrect;
	}
	int* tmp = (int*)malloc(sizeof(int) * (max - min + 1));//ע������Ŀռ�ʱһ��Ҫ���ǵ��±�0��Ҳ��Ҫ�ռ�
	memset(tmp, 0, sizeof(int) * (max - min + 1));//��Ҫ!
	for (i = 0; i < n; i++)//���������ʾ�����tmp�����±�����ʾҪ�����Ԫ��,�Կռ任ʱ��
		tmp[a[i] - min]++;
	for (int j = i = 0; i < max - min + 1; i++)
	{
		while (tmp[i] > 0)
		{
			a[j++] = i + min- NegativeCorrect;
			tmp[i]--;
		}
	}
	free(tmp);
}
//��������
int Digit(int* a,int n, int r)//�����λ��
{
	int max = a[0], i = 0;
	while(i < n)
	{
		if (max < a[i])
			max = a[i];
		i++;
	}
	int d = 0;
	while (max > 0)
	{
		d++;
		max /= r;
	}
	return d;
}
//��������
void RadixSorting(int* a,int n,int r)//rΪ����,�����Ǹ��������,Ͱ����û��̫��ʵ�ü�ֵ
{			
	if (n <= 0)
		return;
	int d = Digit(a, n, r);//�����λ��
	SQList ps;//�����������ָ�����Ͱ(����)��ָ���˳���
	InitSQList(&ps);//��ʼ��˳���
	for (int i = r; i > 0; i--)//����Ͱ
	{
		Queue* tmp = (Queue*)malloc(sizeof(Queue));
		QueueInit(tmp);//��ʼ��Ͱ
		SeqListPushBack(&ps,tmp);//��ָ��Ͱ��ָ�����˳���
	}
	int fetchbit = 1;
	for (int i=1;i<=d;i++)//iʵ��������������fetchbit��,��ÿ�ֱȽϵ��������ĵڼ�λ
	{	
		int j;
		for (j = 0; j < n; j++)
		{	
			int index = a[j] / fetchbit % 10;
			QueuePush(ps.data[index], a[j]);//�����ݷ����Ӧ��Ͱ
		}
		fetchbit *= 10;
		int Q ;
		for (Q=j=0; Q < r; Q++)//��һ�����Ľ���ռ���ԭ���� 
		{
			while (!QueueEmpty(ps.data[Q]))
			{
				a[j++] = QueueFront(ps.data[Q]);//ȡ��ͷԪ��
				QueuePop(ps.data[Q]);//������
			}
		}
	}
	for (int i = 0; i < r; i++)//����Ͱ
		QueueDestroy(ps.data[i]);
	SeqListDestroy(&ps);//���ٴ��Ͱ��˳���
}