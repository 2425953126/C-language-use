#define _CRT_SECURE_NO_WARNINGS 1
#include "STACK.h"
// 初始化栈 
void StackInit(Stack* ps)
{	
	assert(ps);
	ps->a = NULL;
	ps->capacity = 0;
	ps->top = -1;//以-1为底,即栈顶先加一,再存数据
}
// 销毁栈 
void StackDestroy(Stack* ps)
{	
	assert(ps);
	free(ps->a);
	ps->a=NULL;
	ps->capacity = 0;
	ps->top = -1;
}
//扩容函数,每次扩容为原容量的1.25倍+4个成员所占空间
void ExpanSpace(Stack*ps)
{
	STDataType* tmp=ps->a;//我草草草草草草草草草草草草2022/12/21调用栈来完成快排的非递归时候才发现的致命大错误!!!!!!!
						  //STDataType* tmp = NULL;这tm是什么jb!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
						  //这样relloc怎么搬运原内存空间里的值,复制了新建空间里的默认值啊!!!!!!!!!!!!!!!!!!
						  //傻逼bug害老子调了几个小时都想不明白,这傻逼vs调试监视里又看不了栈里面的值,默认a为char类型贼tm傻逼
						  //内存还没看明白!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	tmp = realloc(tmp,(int)(sizeof(STDataType)*ps->capacity*1.25+4*sizeof(STDataType)));//4*sizeof(STDataType)吊jb东西害老子调错一小时,
																						//这边如果只+4代表只申请一个字节空间,即一个int型空间
	if (tmp == NULL)
	{	
		perror("ExpanSpace");
		exit(-1);
	}
	else
		ps->a = tmp;
	ps->capacity = (int)( ps->capacity *1.25 + 4);
}
// 入栈 
void StackPush(Stack* ps, STDataType data)
{
	assert(ps);
	if (ps->top == (ps->capacity - 1))//容量不足,则扩容
		ExpanSpace(ps);
	ps->top++;//先自加,再存数据
	ps->a[ps->top] = data;
}
// 出栈 
void StackPop(Stack* ps)
{
	assert(ps && ps->top != -1);//检测栈指针是否为NULL,且栈内成员不得为无
	ps->top--;
}
// 获取栈顶元素 
STDataType StackTop(Stack* ps)
{
	assert(ps && ps->top != -1);
	return ps->a[ps->top]; 
}
//获取栈顶元素,并出栈
STDataType TopPop(Stack* ps)
{
	STDataType tmp = StackTop(ps);
	StackPop(ps);
	return tmp;
}
// 获取栈中有效元素个数 
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->top + 1;
}
// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
int StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->top > -1 ? 0 : 1;
}