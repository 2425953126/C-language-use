#define _CRT_SECURE_NO_WARNINGS 1
#include "sort1.h"
// 插入排序
void InsertSort(int* a, int n)
{	
	for (int i = 0; i < n; i++)
	{
		int x=a[i],end = i - 1;//end每轮最终指向的是插入数应当插入的位置的前一个位置
		while (end >= 0)
		{
			if (x < a[end])//从前面已经排好序的元素的最后一个元素开始比较,如果它比x大,那么则将它后移一位
				a[end + 1] = a[end];
			else
				break;
			end--;
		}
		a[end + 1] = x;
	}
}

// 希尔排序
void ShellSort(int* a, int n)
{	
	for (int gap=n/2;gap>0;gap/=2)//控制gap大小
	{
		for (int begin = 0; begin < gap; begin++)//控制分组
		{
			for (int i = begin; i < n; i += gap)//直接插入排序
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
void Swap(int* a, int* b)//交换,值得注意是,起初我是用异或法来完成交换的,但是有时候a和b会指向同一处空间,用异或法交换就会导致归零

{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
// 选择排序
void SelectSort(int* a, int n)
{
	int left=0;
	int right=n-1;
	for (; left < right; left++, right--)
	{
		int min = left;
		int max = right;
		for (int i = left; i <= right; i++)//每次找到剩余元素中的最小值和最大值
		{
			if (a[i] < a[min])
				min = i;
			if (a[i] > a[max])
				max = i;
		}
		Swap(&a[left], &a[min]);
		if (max == left)//防止有时候最大值处在left位置上时在交换最小元素的过程中,将处于left位置的最大元素给先交换到原本最小元素的位置上了,从而导致移位错误
			max = min;
		Swap(&a[right], &a[max]);
	}
}

// 堆排序
void AdjustDwon(int* a, int n, int root)
{
	if (2 * root + 1 >= n)//root没有左孩子(也必定没有右孩子),结束
		return;
	int child = 2 * root + 1;
	if (2 * root + 2<n&&a[2 * root + 1] < a[2 * root + 2])//确保与比父亲结点更大的,且两个子结点中更大的交换,此处注意,要判断一下有没有右孩子
		child += 1;
	if (a[root] < a[child])//向下调整
	{
		Swap(&a[root], &a[child]);
		AdjustDwon(a, n, child);
	}
}
void HeapSort(int* a, int n)
{	
	int root = (n - 1 - 1) / 2;//n-1为最后一个叶子结点,它的父亲结点下标为(n-1-1)/2,即最后一个非叶子结点,它前面的结点皆为非叶子结点
	while (root > 0)//建立大堆;
	{
		AdjustDwon(a, n, root);
		root--;
	}
	for (int i = n - 1; i >= 0; i--)//堆排序
	{
		Swap(&a[0], &a[i]);
		AdjustDwon(a, --n, 0);//这边注意n每次需要减1,不然向下调整算法就把之前放到末尾的最大值又调整到顶去了
	}
}

// 冒泡排序
void BubbleSort(int* a, int n)
{
	for (int i=n-1;i>0;i--)
	{
		int flag = 0;//定义标志变量
		for (int j = 0; j < i; j++)
		{
			if (a[j] > a[j + 1])
			{
				Swap(&a[j], &a[j + 1]);
				flag = 1;
			}
		}
		if (flag == 0)//当进行一轮冒泡排序后一次元素交换都没有发生过,说明余下元素皆为符合要求顺序的,提前结束排序
			break;
	}
}

// 快速排序递归实现
int getkey(int*a,int left,int right)//三数取中
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
// 快速排序hoare版本
int PartSort1(int* a, int left, int right)
{
	int key = getkey(a, left, right);
	Swap(&a[key], &a[left]);//这里曾犯了个致命错误,找到key后,a[key]又和a[left]交换了位置,却没有把key赋值为left
	key = left;
	while(left<right)
	{
		while (left<right&&a[right] >= a[key])//这里要特别注意需要防止越界和死循环,即必须要越过和a[key]相等的数,否则两边如果同时定位到这样的数就会无限重复交换,死循环
			right--;
		while (left<right&&a[left] <= a[key])
			left++;
		Swap(&a[left], &a[right]);
		if (left == right)
			Swap(&a[key], &a[left]);
	}
	return left;
}
 //快速排序挖坑法
int  PartSort2(int* a, int left, int right)
 {
	int key = getkey(a, left, right);
	Swap(&a[key], &a[left]);
	key = left;
	int tmp = a[key];                                                                                                                                                                              
	while (left < right)
	{
		while (left < right && a[right] >=tmp)//这里要特别注意需要防止越界和死循环,即必须要越过和a[key]相等的数,否则两边如果同时定位到这样的数就会无限重复交换,死循环
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
//快速排序前后指针法
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
		if (cur <= right)//自己写的时候没写这句!时刻注意越界情况!
		{
			Swap(&a[++prev], &a[cur++]);//!!cur在交换完后必须++!!!!!,不然就下次循环cur还会直接停下来!
		}								//傻逼傻逼傻逼prev自增,你个臭吊bug让老子好找!!!!!!!!!!
										//只有cur找到可交换值的时候,prev才能自增,然后交换,如果cur是到终点停止,prev也自增,最后交换a[key]时,值自然就不对了
										//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	}
	Swap(&a[prev], &a[key]);
	return prev;
}
//重点推荐:
int PartSort3_supper(int* a, int left, int right)//前后指针法优化版
{
	int key = getkey(a, left, right);
	Swap(&a[key], &a[left]);
	key = left;

	int prev = left, cur = left + 1;
	while (cur <= right)
	{
		if (a[cur] <a[key] &&++prev!=cur)//原方法为通过循环主动略过到比a[key]大的数,找到比a[key]小的数,然后交换到前面去;注意此时不需要<=,因为与a[key]相等的数,不用交换位置
			Swap(&a[prev], &a[cur]);		   //优化版为在不断cur++的遍历中,发现有比a[key]小得数,交换. 总结就是,循环次数并没有变,
										   //只不过老方法中有部分cur++是在内循环中完成的,而优化版中,每次cur++都统一交由外循环完成,便于书写理解
		cur++;//因为原方法,无论a[cur]大小如何,cur最后都需+1,因此应当提取出来++
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
//小区间优化
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
	else//如果剩余元素数量少于等于10,采用直接插入排序
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
// 快速排序 非递归实现
void QuickSortNonR(int* a, int left, int right)
{	
	Stack s;
	StackInit(&s);
	StackPush(&s, left);
	StackPush(&s, right);
	while (!StackEmpty(&s))
	{
		int sright = TopPop(&s);
		int sleft = TopPop(&s);//注意栈先进后出的特性
		int lastposition= PartSort3_supper(a,sleft,sright);//注意lastposition可能是越位的
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
	while (i <= mid && j <= right)//开始归并排序
		if (a[i] <= a[j])
			tmp[k++] = a[i++];
		else
			tmp[k++] = a[j++];
	while (i <= mid)//如果左半数组有剩余,添到尾上
		tmp[k++] = a[i++];
	while (j<=right)//如果右半数组有剩余,添到尾上
		tmp[k++] = a[j++];
	i = left;
	while (i < k)//必须把排序结果赋回原数组,因为归排是要额外有一个存值数组的,如果不把排序好的数据传回原数组,那上一个递归中也用tmp数组来读取元素的话,归排时把排好的元素暂存在哪里呢?
		a[i] = tmp[i++];
}
// 归并排序递归实现
void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n); 
	if (tmp == NULL)
		exit(-1);
	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);
}
// 归并排序非递归实现
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
			while (begin1 < i+gap && begin2 < i + 2 * gap&& begin2 <n)//如果出现越界,begin2必定越界,begin1可能越界
			{	
				if (a[begin1] <= a[begin2])//小于等于可以保证稳定性
					tmp[j++] = a[begin1++];
				else
					tmp[j++] = a[begin2++];
			}
			while (begin1 < i+gap&& begin1<n)//此处begin1可能越界!!
				tmp[j++] = a[begin1++]; 
			while (begin2 < i + 2 * gap && begin2 < n)
				tmp[j++] = a[begin2++];
		}
		int s = 0;
		while (s < n)//别忘了把每次排好的结果拷贝回原数组
			a[s] = tmp[s++];
	}
}

//计数排序
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
	int NegativeCorrect = 0;//负数修正值,即所有数加上最小负数的绝对值,用以将所有的负数修正到非负数
	if (min < 0)
	{
		NegativeCorrect = 0 - min;
		min += NegativeCorrect;
		max += NegativeCorrect;
		if (max + 1 < 0)//如果最大值经修正后再加1,值小于0,说明原最大值加上负数修正值出现了溢出,排序失败
			exit(-1);
		for (i = 0; i < n; i++)
			a[i] += NegativeCorrect;
	}
	int* tmp = (int*)malloc(sizeof(int) * (max - min + 1));//注意申请的空间时一定要考虑到下标0处也需要空间
	memset(tmp, 0, sizeof(int) * (max - min + 1));//重要!
	for (i = 0; i < n; i++)//计数排序本质就是用tmp数组下标来表示要排序的元素,以空间换时间
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
//基数排序
int Digit(int* a,int n, int r)//求最大位数
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
//基数排序
void RadixSorting(int* a,int n,int r)//r为基数,不考虑负数情况了,桶排序没有太大实用价值
{			
	if (n <= 0)
		return;
	int d = Digit(a, n, r);//求最大位数
	SQList ps;//定义用来存放指向各个桶(队列)的指针的顺序表
	InitSQList(&ps);//初始化顺序表
	for (int i = r; i > 0; i--)//创建桶
	{
		Queue* tmp = (Queue*)malloc(sizeof(Queue));
		QueueInit(tmp);//初始化桶
		SeqListPushBack(&ps,tmp);//将指向桶的指针放入顺序表
	}
	int fetchbit = 1;
	for (int i=1;i<=d;i++)//i实际上是用来控制fetchbit的,即每轮比较的是整数的第几位
	{	
		int j;
		for (j = 0; j < n; j++)
		{	
			int index = a[j] / fetchbit % 10;
			QueuePush(ps.data[index], a[j]);//把数据放入对应的桶
		}
		fetchbit *= 10;
		int Q ;
		for (Q=j=0; Q < r; Q++)//将一遍分配的结果收集回原数组 
		{
			while (!QueueEmpty(ps.data[Q]))
			{
				a[j++] = QueueFront(ps.data[Q]);//取队头元素
				QueuePop(ps.data[Q]);//出队列
			}
		}
	}
	for (int i = 0; i < r; i++)//销毁桶
		QueueDestroy(ps.data[i]);
	SeqListDestroy(&ps);//销毁存放桶的顺序表
}