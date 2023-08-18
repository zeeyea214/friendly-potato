/*第一种字符可以用一比特 0 表示
第二种字符可以用两比特（10 或 11）表示
给你一个以 0 结尾的二进制数组 bits ，如果最后一个字符必须是一个一比特字符，则返回 true 。*/

#include<stdio.h>
#include<stdlib.h>

bool isOneBitCharacter(int* bits, int bitsSize)
{
    for(int i=0;i<bitsSize;++i)
    {
        if(i == bitsSize-1) 
        {
            return (bits[i]?false:true);
        }
        if(bits[i]) ++i;
    }
    return false;
}

/*8.17_1*/