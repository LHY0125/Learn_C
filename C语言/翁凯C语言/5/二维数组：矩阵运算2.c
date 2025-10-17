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

void matrix_produce(int l,int m, int a[l][m]);
void matrix_multiply( int l, int m, int n, int a[l][m], int b[m][n], int c[l][n]);
void matrix_print(int l, int n, int c[l][n]);

// !矩阵与矩阵的乘法运算
int main()
{
    int l, m, q, n;
    
    // !矩阵的定义
    printf("请输入矩阵a的行数、列数：\n");
    scanf("%d %d", &l, &m);
    printf("请输入矩阵b的行数、列数：\n");
    scanf("%d %d", &q, &n);
    while (m!=q)
    {
        printf("矩阵a的列数与矩阵b的行数不相等，无法进行矩阵乘法运算！\n");
        printf("请重新输入矩阵a的行数、列数：\n");
        scanf("%d %d", &l, &m);
        printf("请重新输入矩阵b的行数、列数：\n");
        scanf("%d %d", &q, &n);
    }

    int a[l][m];
    int b[m][n];
    int c[l][n];

    // !矩阵的输入
    printf("请输入矩阵a的元素：\n");
    matrix_produce(l, m, a);

    printf("请输入矩阵b的元素：\n");
    matrix_produce(m, n, b);

    // !矩阵的乘法运算
    matrix_multiply(l, m, n, a, b, c);

    // !矩阵的打印
    printf("矩阵a和矩阵b的乘法结果矩阵c为：\n");
    matrix_print(l, n, c);

    return 0;
}

void matrix_produce(int l,int m, int a[l][m])
{
    // !矩阵的输入
    int i, j;
    for ( i = 0; i < l; i++)
    {
        for ( j = 0; j < m; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
}

void matrix_multiply (int l, int m, int n, int a[l][m], int b[m][n], int c[l][n])
{
    // !矩阵的乘法运算
    int i, j, k;
    for ( i = 0; i < l; i++)
    {
        for ( j = 0; j < n; j++)
        {
            c[i][j] = 0;
            for ( k = 0; k < m; k++)
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