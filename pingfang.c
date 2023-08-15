/*
3.求一个整数
题目： 
	一个整数，它加上100后是一个完全平方数，再加上168又是一个完全平方数，请问该数是多少？（注：一个数如果是另一个整数的完全平方，那么我们就称这个数为完全平方数，也叫做平方数。）

程序分析：
	假设该数为x，则有：
	1）x+100=n^2，x+100+168=m^2 
	2）计算等式：m^2-n^2= (m+n)*(m-n)=168
	3）设：m+n=i, m-n = j, i*j=168 => i和j至少有一个是偶数
	4）可得：m=(i+j)/2, n = (i-j)/2, i和j要么都是偶数，要么都是奇数
	5）由3）和4）推导可知，i与j均为大于等于2的偶数
	6）由于i*j=168,j>=2,则1<i<168/2+1。
	7）接下来将i的所有数字循环计算即可 
*/
#include<stdio.h>

int main()
{
    int x,n,m,i,j;
    for(i=1;i<168/2+1;++i)
    {
        if(168%i==0)
        {
            j = 168/i;
            if(i>j&&(i+j)%2==0&&(i-j)%2==0)
            {
                m=(i+j)/2;
                n=(i-j)/2;
                x=n*n-100;
                printf("%d + 100 = %d * %d\n",x,n,n);
                printf("%d + 100 +168 = %d * %d\n",x,m,m);
            }
        }
    }
    return 0;
}