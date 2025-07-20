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

int check_symmetry(int matrix[][200], int size);

int main()
{
    int n;
    scanf("%d", &n);
    int matrix1[100][100], matrix2[100][100], matrix3[100][100], matrix4[100][100];

    // 读取四个n×n的矩阵
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix1[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix2[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix3[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix4[i][j]);
        }
    }

    int big_matrix[200][200];
    // 方案一：常规左上、右上、左下、右下拼接
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            big_matrix[i][j] = matrix1[i][j];
            big_matrix[i][j + n] = matrix2[i][j];
            big_matrix[i + n][j] = matrix3[i][j];
            big_matrix[i + n][j + n] = matrix4[i][j];
        }
    }
    if (check_symmetry(big_matrix, 2 * n))
    {
        printf("YES\n");
        return 0;
    }

    // 方案二：交换右上和左下
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            big_matrix[i][j] = matrix1[i][j];
            big_matrix[i][j + n] = matrix3[i][j];
            big_matrix[i + n][j] = matrix2[i][j];
            big_matrix[i + n][j + n] = matrix4[i][j];
        }
    }
    if (check_symmetry(big_matrix, 2 * n))
    {
        printf("YES\n");
        return 0;
    }

    // 方案三：交换左上和右下
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            big_matrix[i][j] = matrix4[i][j];
            big_matrix[i][j + n] = matrix2[i][j];
            big_matrix[i + n][j] = matrix3[i][j];
            big_matrix[i + n][j + n] = matrix1[i][j];
        }
    }
    if (check_symmetry(big_matrix, 2 * n))
    {
        printf("YES\n");
        return 0;
    }

    // 方案四：交换左上和右上，左下和右下
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            big_matrix[i][j] = matrix2[i][j];
            big_matrix[i][j + n] = matrix1[i][j];
            big_matrix[i + n][j] = matrix4[i][j];
            big_matrix[i + n][j + n] = matrix3[i][j];
        }
    }
    if (check_symmetry(big_matrix, 2 * n))
    {
        printf("YES\n");
        return 0;
    }

    printf("NO\n");
    return 0;
}

// !检查矩阵是否为对称矩阵
int check_symmetry(int matrix[][200], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (matrix[i][j] != matrix[j][i])
            {
                return 0;
            }
        }
    }
    return 1;
}