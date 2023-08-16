//获取字符串并打印
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
void getmemory(char *p)
{
	strcpy(p, "hello world");
}

void main(void)
{
	char *str = NULL;
	str = (char *)malloc(100);
	getmemory(str);
	printf("%s\r\n", str);
	free(str);
}
