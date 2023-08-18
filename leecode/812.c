/*给你一个由 X-Y 平面上的点组成的数组 points ，其中 points[i] = [xi, yi] 。从其中取任意三个不同的点组成三角形，
返回能组成的最大三角形的面积。与真实值误差在 10-5 内的答案将会视为正确答案。*/
#include<stdio.h>
#include<stdlib.h>
static double max(double a,double b)
{
    return a>b?a:b;
}
static double TriangleArea(double x1,double y1,double x2,double y2,double x3,double y3)
{
    return 0.5*abs(x1*y2+x2*y3+x3*y1-x1*y3-x2*y1-x3*y2);
}
double largestTriangleArea(int** points, int pointsSize, int* pointsColSize)
{
    int i,j,k;
    double res=0;
    for ( i = 0; i < pointsSize; ++i)
    {
        for(j = i+1;j<pointsSize; ++j)
        {
            for(k = j+1;k<pointsSize; ++k)
            {
                res = max(res,TriangleArea(points[i][0],points[i][1],points[j][0],points[j][1],points[k][0],points[k][1]));
            }
        }
    }
    return res;
}
/*8.17_2*/