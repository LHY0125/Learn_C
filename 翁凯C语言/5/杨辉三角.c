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

void yanghui(int rows);

int main()
{
    int rows;
    printf("请输入杨辉三角的行数：");
    scanf("%d", &rows);

    yanghui(rows);

    return 0;
}

void yanghui(int rows)
{
    int triangle[rows][rows];
    triangle[0][0] = 1;

    for (int i = 1; i < rows; i++)
    {
        // !第一列和最后一列都为1
        triangle[i][0] = 1;
        triangle[i][i] = 1;
        for (int j = 1; j < i; j++)
        { 
            // !中间数为上一行相邻两数之和
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            printf("%d ", triangle[i][j]);
        }
        printf("\n");
    }
}