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

// ! 动态分配二维数组（int ** 类型）
int **allocate_matrix(int rows, int cols);

// ! 输入l行m列的矩阵（适配 int ** 类型）
void matrix_produce(int l, int m, int **a);

// ! 打印l行n列的矩阵（适配 int ** 类型）
void matrix_print(int l, int n, int **c);

// ! 计算两个矩阵的和（补零相加）
int **add_matrices(int **A, int n1, int m1, int **B, int n2, int m2, int *result_rows, int *result_cols);

// ! 释放二维数组内存
void matrix_free(int **matrix, int rows);

int main()
{
    // 矩阵A和B的行列数
    int n1, m1, n2, m2;

    // 结果矩阵的行列数
    int result_rows, result_cols;

    // ! 输入矩阵A的行列数并动态分配内存
    printf("输入矩阵A的行数和列数（用空格分隔）: ");
    scanf("%d %d", &n1, &m1);

    // 动态分配矩阵A（int ** 类型）
    int **A = allocate_matrix(n1, m1); 
    printf("按行输入矩阵A的元素（每行%d个，用空格分隔）:\n", m1);
    matrix_produce(n1, m1, A);

    // ! 输入矩阵B的行列数并动态分配内存
    printf("输入矩阵B的行数和列数（用空格分隔）: ");
    scanf("%d %d", &n2, &m2);

    // 动态分配矩阵B（int ** 类型）
    int **B = allocate_matrix(n2, m2);
    printf("按行输入矩阵B的元素（每行%d个，用空格分隔）:\n", m2);
    matrix_produce(n2, m2, B);

    // ! 计算矩阵相加（补零相加）
    int **result = add_matrices(A, n1, m1, B, n2, m2, &result_rows, &result_cols);

    // ! 输出结果矩阵
    printf("\n结果矩阵（行列数: %d×%d）:\n", result_rows, result_cols);
    matrix_print(result_rows, result_cols, result);

    // ! 释放所有动态分配的内存
    matrix_free(A, n1);
    matrix_free(B, n2);
    matrix_free(result, result_rows);

    return 0;
}

// ! 动态分配二维数组（int ** 类型）
int **allocate_matrix(int rows, int cols)
{
    int **matrix = (int **)malloc(rows * sizeof(int *)); // 分配行指针数组
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = (int *)malloc(cols * sizeof(int)); // 分配每行的列空间
    }
    return matrix;
}

// ! 输入l行m列的矩阵（适配 int ** 类型）
void matrix_produce(int l, int m, int **a)
{
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &a[i][j]); // 通过指针访问动态分配的矩阵元素
        }
    }
}

// ! 计算两个矩阵的和（补零相加）
int **add_matrices(int **A, int n1, int m1, int **B, int n2, int m2, int *result_rows, int *result_cols)
{
    // 计算结果矩阵的尺寸（行数和列数的最大值）
    *result_rows = (n1 > n2) ? n1 : n2;
    *result_cols = (m1 > m2) ? m1 : m2;
    int **result = allocate_matrix(*result_rows, *result_cols); // 动态分配结果矩阵

    // 逐位置计算相加结果（补零逻辑）
    for (int i = 0; i < *result_rows; i++)
    {
        for (int j = 0; j < *result_cols; j++)
        {
            int a = (i < n1 && j < m1) ? A[i][j] : 0; // A超出范围则为0
            int b = (i < n2 && j < m2) ? B[i][j] : 0; // B超出范围则为0
            result[i][j] = a + b;
        }
    }
    return result;
}

// ! 打印l行n列的矩阵（适配 int ** 类型）
void matrix_print(int l, int n, int **c)
{
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", c[i][j]); // 通过指针访问动态分配的矩阵元素
        }
        printf("\n");
    }
}

// ! 释放二维数组内存
void matrix_free(int **matrix, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        free(matrix[i]); // 释放每行的内存
    }
    free(matrix); // 释放行指针数组
}