#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

// !二维数组
/*
    int a[3][5];
    通常理解为a是一个3行5列的矩阵
*/

// !二维数组的遍历
/*
    for ( i=0; i<3; i++)
    {
        for ( j=0; j<5; j++ )
        {
            a[i][j] = i*j;
        }
    }
    a[i][i]是一个int
    表示第i行第j列上的单元
    但a[i,j]是数学上表示a是一个i行j列的矩阵，在C语言是a[i][j]
*/

// !二维数组的初始化
/*
    nt a[] [5] = 
    { 
        {0,1,2,3,4}, 
        {2,3,4,5,6
    };
    列数是必须给出的，行数可以由编译器来数每行一个，逗号分隔
    最后的逗号可以存在，有古老的传统
    如果省略，表示补零
    也可以用定位(*C99 标准)
*/

// !输入l行m列的矩阵
void matrix_produce(int l, int m, int a[l][m])
{
    int i, j;
    for (i = 0; i < l; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
}

// !打印l行n列的矩阵
void matrix_print(int l, int n, int c[l][n])
{
    int i, j;
    for (i = 0; i < l; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
}

int main(void)
{
    int l, m;
    printf("请输入方阵的行数l和列数m（必须相等）：");
    scanf("%d %d", &l, &m);

    if (l != m)
    {
        printf("错误：输入的不是方阵（行数≠列数）！\n");
        return 1;
    }
    int n = l;

    int a[n][n];
    matrix_produce(n, n, a);

    int sum_main = 0;
    for (int i = 0; i < n; i++)
    {
        sum_main += a[i][i];
    }

    int sum_anti = 0;
    for (int i = 0; i < n; i++)
    {
        int j = n - 1 - i;
        sum_anti += a[i][j];
    }

    int total_sum;
    if (n % 2 == 1)
    {
        int duplicate_i = (n - 1) / 2;
        total_sum = sum_main + sum_anti - a[duplicate_i][duplicate_i];
    }
    else
    {
        total_sum = sum_main + sum_anti;
    }

    printf("主对角线和为：%d\n", sum_main);
    printf("副对角线和为：%d\n", sum_anti);
    printf("两条对角线总和（重复位置仅一次）：%d\n", total_sum);

    return 0;
}