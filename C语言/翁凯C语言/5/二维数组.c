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
        {2,3,4,5,6}, 
    };
    列数是必须给出的，行数可以由编译器来数每行一个，逗号分隔
    最后的逗号可以存在，有古老的传统
    如果省略，表示补零
    也可以用定位(*C99 标准)
*/

// !tic-tac-toe游戏
int main()
{
    const int size = 3;
    int board[size][size];
    int i, j;
    int numfx, numfo;
    int result = -1;

    // 写入棋盘矩阵
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            printf("请输入第%d行第%d列的棋子（1代表X，0代表O）:", i + 1, j + 1);
            scanf("%d", &board[i][j]);
        }
    }

    // 检查行
    for (i = 0; i < size && result == -1; i++)
    {
        numfx = numfo = 0;
        for (j = 0; j < size;j++)
        {
            if (board[i][j]==1)
            {
                numfx++;
            }
            else
            {
                numfo++;
            }
        }

        if (numfo == size)
        {
            result = 0;
        }
        else if (numfx == size)
        {
            result = 1;
        }
    }

    // 检查列
    if (result == -1)
    {
        for (j = 0; j < size && result == -1; j++)
        {
            numfx = numfo = 0;
            for (i = 0; i < size; i++)
            {
                if (board[i][j] == 1)
                {
                    numfx++;
                }
                else
                {
                    numfo++;
                }
            }

            if (numfo == size)
            {
                result = 0;
            }
            else if (numfx == size)
            {
                result = 1;
            }
        }
    }

    // 检查主对角线
    if (result == -1)
    {
        numfx = numfo = 0;
        for (i = 0; i < size;i++)
        {
            if (board[i][i]==1)
            {
                numfx++;
            }
            else
            {
                numfo++;
            }
        }

        if (numfo ==size)
        {
            result = 0;
        }
        else if (numfx == size)
        {
            result = 1;
        }
    }

    // 检查次对角线
    if (result == -1)
    {
        numfx = numfo = 0;
        for (i = 0; i < size; i++)
        {
            if (board[i][size - i - 1] == 1)
            {
                numfx++;
            }
            else
            {
                numfo++;
            }
        }

        if (numfo == size)
        {
            result = 0;
        }
        else if (numfx == size)
        {
            result = 1;
        }
    }

    // 输出结果
    if (result == 1)
    {
        printf("X获胜！\n");
    }
    else if (result == 0)
    {
        printf("O获胜！\n");
    }
    else
    {
        printf("平局！\n");
    }

    return 0;
}