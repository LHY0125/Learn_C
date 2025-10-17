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
    int l, m, max;
    printf("请输入矩阵的行数l和列数m：");
    scanf("%d %d", &l, &m);

    int a[l][m];

    printf("请输入%d行%d列的矩阵数据：\n", l, m);
    matrix_produce(l, m, a);

    max = a[0][0];
    int row = 0;
    int col = 0;

    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] > max)
            {
                max = a[i][j];
                row = i;
                col = j;
            }
        }
    }

    printf("矩阵为：\n");
    matrix_print(l, m, a);
    printf("矩阵的最大值为：%d,位置为(%d,%d)\n", max, row, col);

    return 0;
}