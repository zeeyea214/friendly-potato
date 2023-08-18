#include <stdio.h>
#include <stdlib.h>

/*给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。

请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。

注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。为了应对这种情况，nums1 的初始长度为 m + n，其中前 m 个元素表示应合并的元素，
后 n 个元素为 0 ，应忽略。nums2 的长度为 n 。

*/
int cmp(int *a,int *b)//方法1：插入排序
{
    return (*a-*b);
}


void merge1(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int i;
    for(i=0;i<n;++i)
    {

            nums1[i+m] = nums2[i];
    }
     qsort(nums1,n+m,sizeof(int),cmp);//这是C语言中快速排序函数.
     /*
     void qsort(void *base,nitems,size,int(*cmp)(const *elem1,const *elem2));
        其中int(*cmp)(const *elem1,const *elem2)是一个函数指针。
        base：指向要排序的数组的首元素的指针。
        nitems：数组中元素的数量。
        size：每个元素的大小（以字节为单位）。
        comp：一个指向比较函数的指针，用于比较两个元素的大小关系。这个函数应该返回一个整数，表示两个元素的比较结果，具体规则如下：
        如果第一个元素小于第二个元素，返回一个负数。
        如果第一个元素大于第二个元素，返回一个正数。
        如果两个元素相等，返回 0。
     */
}

//方法二双指针
void merge2(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    int x=0,y=0,f;
    int *temp = calloc(n+m,sizeof(int));
    while(x<m||y<n)
    {
        f=x+y;
        if(x==m)
        temp[f]=nums2[y++];
        else if(y==n)
        temp[f]=nums1[x++];
        else if(nums1[x]<nums2[y])
        temp[f]=nums1[x++];
        else
        temp[f]=nums2[y++];
    }
    for(x=0;x<m+n;++x)
    {
        nums1[x]=temp[x];
    }
}
