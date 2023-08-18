/*给你一个 m * n 的矩阵 grid，矩阵中的元素无论是按行还是按列，都以非递增顺序排列。 请你统计并返回 grid 中 负数 的数目。*/
int countNegatives(int** grid, int gridSize, int* gridColSize)
{
    int count = 0,i,j;
    for(i = 0;i<gridSize;++i)
    {
        for(j = 0;j<*gridColSize;++j)
        {
            if(grid[i][j]<0)
            {
                count++;
            }
        }
    }
    return count;
}
/*8.17_3*/