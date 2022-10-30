#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
int* singleNumbers(int* nums, int numsSize, int* returnSize) {
    int tmp = 0;
    int i = 0;
    while (i < numsSize)
    {
        tmp ^= nums[i++];
    }
    int flag = tmp & (-tmp);
    int regs = 0;
    for (i = 0; i < numsSize; i++)
    {
        if ((flag & nums[i]) != 0)
            regs ^= nums[i];
    }
    int regs1 = tmp ^ regs;
    returnSize = (int*)malloc(sizeof(int) * 2);
    returnSize[0] = regs;
    returnSize[1] = regs1;
    return returnSize;
}
int main()
{
    int a[4] = { 4,1,4,6 };
    int n = 4;
    int* p=NULL; 
    p=singleNumbers(a, n, p);
    printf("%d %d", p[0], p[1]);
    free(p);
    return 0;
}