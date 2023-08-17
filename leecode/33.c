/*给定 N 个无限容量且初始均空的水缸，每个水缸配有一个水桶用来打水，第 i 个水缸配备的水桶容量记作 bucket[i]。小扣有以下两种操作：

升级水桶：选择任意一个水桶，使其容量增加为 bucket[i]+1
蓄水：将全部水桶接满水，倒入各自对应的水缸
每个水缸对应最低蓄水量记作 vat[i]，返回小扣至少需要多少次操作可以完成所有水缸蓄水要求。

注意：实际蓄水量 达到或超过 最低蓄水量，即完成蓄水要求。*/
#include<stdio.h>
#include<stdlib.h>

static int max(int a,int b)
{
    return a>b?a:b;
}

static int min(int a,int b)
{
    return a<b?a:b;
}


int storeWater(int* bucket, int bucketSize, int* vat, int vatSize)
{
    int maxk,i,j;
    for(i = 0;i<vatSize;++i)
    {
        maxk = max(maxk,vat[i]);
    }
    if(maxk == 0)
    {
        return 0;
    }
    int res = INT_MAX;
    for(j=1;j<=maxk&&j<res;++j)
    {
        int t = 0;
        for(i=0;i<bucketSize;++i)
        {
            t+=max(0,(vat[i]+j-1)/j-bucket[i]);
        }
        res = min(res,t+j);
    }
    return res;
}