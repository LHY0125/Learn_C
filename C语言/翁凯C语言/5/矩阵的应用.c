#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

// !动态分配二维数组（int ** 类型）
int **allocate_matrix(int rows, int cols);

// !输入l行m列的矩阵
void matrix_produce(int l, int m, int a[l][m]);

// !打印l行n列的矩阵
void matrix_print(int l, int n, int c[l][n]);

// !矩阵的乘法运算
void matrix_multiply(int l, int m, int n, int a[l][m], int b[m][n], int c[l][n]);

// !检查矩阵是否对称
int matrix_check_symmetry(int matrix[][200], int size);

// !转置矩阵：将src[l][m]转置为dest[m][l]
void matrix_transpose(int l, int m, int src[l][m], int dest[m][l]);

// !查找矩阵中的最大值
int matrix_max_value(int l, int m, int mat[l][m]);

// !计算主对角线和（i == j）
int calculate_main_diagonal(int n, int mat[n][n]);

// !计算副对角线和（i + j == n-1）
int calculate_anti_diagonal(int n, int mat[n][n]);

// !计算两个矩阵的和（补零相加）
int **add_matrices(int **A, int n1, int m1, int **B, int n2, int m2, int *result_rows, int *result_cols);

// !找出二维数组中的鞍点（行最大且列最小）
void matrix_find_saddle_point(int rows, int cols, int matrix[rows][cols]);

// !释放二维数组内存
void matrix_free(int **matrix, int rows);

int main(void)
{
    
    return 0;
}

int **allocate_matrix(int rows, int cols)
{
    // !动态分配二维数组（int ** 类型）
    int **matrix = (int **)malloc(rows * sizeof(int *)); // 分配行指针数组
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = (int *)malloc(cols * sizeof(int)); // 分配每行的列空间
    }
    return matrix;
}

void matrix_produce(int l, int m, int a[l][m])
{
    // !矩阵的输入
    int i, j;
    for (i = 0; i < l; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
}

void matrix_multiply(int l, int m, int n, int a[l][m], int b[m][n], int c[l][n])
{
    // !矩阵的乘法运算
    int i, j, k;
    for (i = 0; i < l; i++)
    {
        for (j = 0; j < n; j++)
        {
            c[i][j] = 0;
            for (k = 0; k < m; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void matrix_print(int l, int n, int c[l][n])
{
    // !矩阵的打印
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

int matrix_check_symmetry(int matrix[][200], int size)
{
    // !检查矩阵是否对称
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

void matrix_transpose(int l, int m, int src[l][m], int dest[m][l])
{
    // !转置矩阵：将src[l][m]转置为dest[m][l]
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < m; j++)
        {
            dest[j][i] = src[i][j]; // 核心转置逻辑
        }
    }
}

int matrix_max_value(int l, int m, int mat[l][m])
{
    // !查找mat矩阵中的最大值
    int max = mat[0][0]; // 初始化最大值为第一个元素
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] > max)
            {
                max = mat[i][j]; // 更新最大值
            }
        }
    }
    return max; // 返回最大值
}

int calculate_main_diagonal(int n, int mat[n][n])
{
    // !计算主对角线和（i == j）
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += mat[i][i];
    }
    return sum;
}

int calculate_anti_diagonal(int n, int mat[n][n])
{
    // !计算副对角线和（i + j == n-1）
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int j = n - 1 - i;
        sum += mat[i][j];
    }
    return sum;
}

int **add_matrices(int **A, int n1, int m1, int **B, int n2, int m2, int *result_rows, int *result_cols)
{
    // !计算两个矩阵的和（补零相加）
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


void matrix_find_saddle_point(int rows, int cols, int matrix[rows][cols])
{
    // !找出二维数组中的鞍点（行最大且列最小）
    // 标记是否找到鞍点
    int has_saddle = 0;

    for (int i = 0; i < rows; i++)
    {
        // !步骤1：找到当前行的最大值
        int row_max = matrix[i][0];
        int col_max = 0;

        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] > row_max)
            {
                row_max = matrix[i][j];
                col_max = j;
            }
        }

        // !步骤2：检查该行最大值是否是所在列的最小值
        int col_min = matrix[0][col_max]; // 初始化列最小值为当前列第一行
        for (int k = 1; k < rows; k++)
        {
            // 遍历当前列的所有行
            if (matrix[k][col_max] < col_min)
            {
                col_min = matrix[k][col_max]; // 更新列最小值
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
    if (has_saddle == 0)
    {
        printf("该矩阵没有鞍点!\n");
    }
}

void matrix_free(int **matrix, int rows)
{
    // !释放二维数组内存
    for (int i = 0; i < rows; i++)
    {
        free(matrix[i]); // 释放每行的内存
    }
    free(matrix); // 释放行指针数组
}