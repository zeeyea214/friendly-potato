/**
 * Note: The returned array must be malloced, assume caller calls free().
 * 给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。

最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。

你可以假设除了整数 0 之外，这个整数不会以零开头。
 */
#include<stdio.h>
#include<stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize)
{
    for(int i = digitsSize-1;i>=0;--i)
    {
        digits[i] = digits[i] + 1;
        if(digits[i] != 10)
        {
            *returnSize = digitsSize;
            return digits;
        }
        if(digits[i] == 10)
        {
            digits[i] = 0;
        }
    }
    *returnSize = digitsSize + 1;
    int *a = (int*)malloc(sizeof(int)*(digitsSize+1));
    memset(a,0,sizeof(int)*(digitsSize+1));
    a[0] = 1;
    return a;

}