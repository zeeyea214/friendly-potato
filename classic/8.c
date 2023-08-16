//获取字符串并打印
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
void getmemory(char **p)
{
	*p = (char *)malloc(100);
	strcpy(*p, "hello world");
}

void main(void)
{
	char *str = NULL;
	getmemory(&str);
	printf("%s\r\n", str);
	free(str);
}
