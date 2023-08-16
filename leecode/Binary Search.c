#include<stdio.h>
int binarysearch(int *nums,int numsSize,int target)
{
    int left = 0,rigt = numsSize-1;
    int mid;
    while(left<=rigt)
    {
        mid = left+(rigt-left)/2;
        if(nums[mid] == target)
        return mid;
        else if(nums[mid]>target)
        rigt = mid-1;
        else if(nums[mid]<target)
        left = mid+1;
        else if(left == rigt)
        return left;
    }

}

int main()
{
    int s[]={1,3,5,6},size,p;
    size = sizeof(s)/sizeof(int);
    p = binarysearch(s,size,7);
    printf("%d",p);
}