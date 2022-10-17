#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
int my_atoi(char* p)
{
	int a=0,flag = 0;
	for (; *p != '\0'; p++)
		if (*p != ' ' && *p != '	')
			break;
	if (*p == '-')
	{
		flag = 1;
		p++;
	}
	if (*p == '+')
		p++;
	for (; *p != '\0';p++)
	{
		if (*p >= '0' && *p <= '9')
		{
			a *= 10;
			a += *p - '0';
		}
		else
			break;
	}
	if (flag == 1)
		return 0 - a;
	else
		return a;
}
char* my_strncat(char* dp, char* str, int n)
{
	assert(dp != NULL && str != NULL);
	char* p = dp;
	int i = 0;
	while (*dp != '\0')
	{
		dp++;
	}
	while (*str != '\0'&&i<n)
	{
		*dp++ = *str++;
		i++;
	}
	*dp = '\0';
	return	p;
}
char* my_strncpy(char* dp, char* sp, int n)
{
	assert(dp != NULL && sp != NULL);
	int i = 0;
	char* p = dp;
	while (*sp != '\0' && i < n)
	{
		*dp++ = *sp++;
		i++;
	}
	*dp = '\0';
	return p;
}
int main()
{
	char a[10] = "abcd";
	char b[10] = "fghijkl";
	char* p = NULL;
	my_strncpy(a, b, 4);
	printf("%s",a);
	return 0;
}