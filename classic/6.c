#include<stdio.h>
#include<string.h>

void main(void)
{
	//const char *p1 = "中国的英文名是china!";题目使用的const会导致错误，因为char取值在-128 ~127，应取unsigned
    unsigned char *p1 = "中国的英文名是china!";
	int i, len, n_assic = 0, n_other = 0;
	
	len = strlen(p1);
	for(i = 0; i < len; i++)
	{
		if(p1[i] > 0x80)
		{
			n_other ++;
			i ++;
		}
		else
		{
			n_assic++;
		}
	}
	printf("assic num=%d, other num = %d\r\n", n_assic, n_other);
}
