#include<stdio.h>
#include<string.h>

void main(void)
{
	//const char *p1 = "�й���Ӣ������china!";��Ŀʹ�õ�const�ᵼ�´�����Ϊcharȡֵ��-128 ~127��Ӧȡunsigned
    unsigned char *p1 = "�й���Ӣ������china!";
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
