#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#define EXCHANGE(a)	    char str[100]={0};				\
					    _itoa(a, str, 2);				\
						int i = 0;						\
						char tmp = 0;					\
						while (str[i] != '\0')			\
					{									\
						tmp = str[i];					\
						str[i] = str[i + 1];			\
						str[i + 1] = tmp;				\
						if (str[++i] == '\0')	break;	\
						++i;							\
					}									\
						a = atoi(str);					\

int main()
{
	int num = 144;
	EXCHANGE(num);
	printf("%d",num );
	return 0;
}

