/*
4.判断某日期是这一年的第几天
题目： 
	输入一个日期（年月日），判断这一天是这一年的第几天？
程序分析：
	需考虑闰年和平年（闰年二月比平年多一天） 
*/
//自己尝试写//
#include<stdio.h>

int main()
{
    int year,mounth,day,sum;
    printf("请输入年月日:(例如:2023-2-14)\n");
    scanf("%d-%d-%d",&year,&mounth,&day);
    switch (mounth)
    {
    case 1:sum = 0;break;
    case 2:sum = 31;break;
    case 3:sum = 59;break;
    case 4:sum = 90;break;
    case 5:sum = 120;break;
    case 6:sum = 151;break;
    case 7:sum = 181;break;
    case 8:sum = 212;break;
    case 9:sum = 243;break;
    case 10:sum = 273;break;
    case 11:sum = 304;break;
    case 12:sum = 334;break;
    default:printf("input error!");
        break;
    }
    sum+=day;
    /*if (year%400 == 0||year%4 == 0||year%100 == 0)
    {
        sum+=1;
    }这部分没有考虑到月份，二月之后闰年才多一天，错误写法
    */
   if ((year%400 == 0||year%4 == 0||year%100 == 0)&&mounth>2)
   {
    sum+=1;
   }
   printf("这是该年的%d天",sum);
   return 0;
}