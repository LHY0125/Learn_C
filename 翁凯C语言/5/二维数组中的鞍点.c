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
    nt a[][5] = 
    { 
        {0,1,2,3,4}, 
        {2,3,4,5,6
    };
    列数是必须给出的，行数可以由编译器来数每行一个，逗号分隔
    最后的逗号可以存在，有古老的传统
    如果省略，表示补零
    也可以用定位(*C99 标准)
*/

// !输入l行m列的矩阵（）
void matrix_produce(int l, int m, int a[l][m]);

// !找出二维数组中的鞍点，即该位置上的元素在该行上最大、在该列上最小,也可能没有鞍点
void matrix_find_saddle_point(int rows, int cols, int matrix[rows][cols]);

// !打印l行n列的矩阵（）
void matrix_print(int l, int n, int c[l][n]);

// !释放二维数组内存
void matrix_free(int **matrix, int rows);

int main()
{
    int l, m;
    printf("输入矩阵的行数和列数（用空格分隔）: ");
    scanf("%d %d", &l, &m);

    int matrix[l][m];
    printf("按行输入矩阵元素（每行%d个，空格分隔）:\n", m);
    matrix_produce(l, m, matrix);

    printf("输入的矩阵为：\n");
    matrix_print(l, m, matrix);

    matrix_find_saddle_point(l, m, matrix);

    return 0;
}

// ! 输入l行m列的矩阵
void matrix_produce(int l, int m, int a[l][m])
{
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
}

// !找出二维数组中的鞍点（行最大且列最小）
void matrix_find_saddle_point(int rows, int cols, int matrix[rows][cols])
{
    // 标记是否找到鞍点
    int has_saddle = 0;
    
    for (int i = 0; i < rows; i++)
    {
        // !步骤1：找到当前行的最大值
        int row_max = matrix[i][0];
        int col_max = 0;

        for (int j = 0; j < cols;j++)
        {
            if (matrix[i][j]>row_max)
            {
                row_max = matrix[i][j];
                col_max = j;
            }
        }

        // !步骤2：检查该行最大值是否是所在列的最小值
        int col_min = matrix[0][col_max];       // 初始化列最小值为当前列第一行
        for (int k = 1; k < rows; k++)
        {
            // 遍历当前列的所有行
            if (matrix[k][col_max] < col_min)
            {
                col_min = matrix[k][col_max];   // 更新列最小值
            }
        }

        // !步骤3：判断是否为鞍点（行最大且列最小）
        if (row_max == col_min)
        {
            printf("鞍点坐标为(%d, %d),值为:%d\n", i, col_max, row_max);
            has_saddle = 1;
        }
    } 
   
    // 未找到鞍点时提示
    if (has_saddle==0)
    {
        printf("该矩阵没有鞍点!\n");
    }
}

// !打印l行n列的矩阵（适配 int ** 类型）
void matrix_print(int l, int n, int c[l][n])
{
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", c[i][j]);     // 通过指针访问动态分配的矩阵元素
        }
        printf("\n");
    }
}

// !释放二维数组内存
void matrix_free(int **matrix, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        free(matrix[i]);    // 释放每行的内存
    }
    free(matrix);           // 释放行指针数组
}