#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

// !��ά����
/*
    int a[3][5];
    ͨ�����Ϊa��һ��3��5�еľ���
*/

// !��ά����ı���
/*
    for ( i=0; i<3; i++)
    {
        for ( j=0; j<5; j++ )
        {
            a[i][j] = i*j;
        }
    }
    a[i][i]��һ��int
    ��ʾ��i�е�j���ϵĵ�Ԫ
    ��a[i,j]����ѧ�ϱ�ʾa��һ��i��j�еľ�����C������a[i][j]
*/

// !��ά����ĳ�ʼ��
/*
    nt a[] [5] = 
    { 
        {0,1,2,3,4}, 
        {2,3,4,5,6}, 
    };
    �����Ǳ�������ģ����������ɱ���������ÿ��һ�������ŷָ�
    ���Ķ��ſ��Դ��ڣ��й��ϵĴ�ͳ
    ���ʡ�ԣ���ʾ����
    Ҳ�����ö�λ(*C99 ��׼)
*/

// !tic-tac-toe��Ϸ
int main()
{
    const int size = 3;
    int board[size][size];
    int i, j;
    int numfx, numfo;
    int result = -1;

    // д�����̾���
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            printf("�������%d�е�%d�е����ӣ�1����X��0����O��:", i + 1, j + 1);
            scanf("%d", &board[i][j]);
        }
    }

    // �����
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

    // �����
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

    // ������Խ���
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

    // ���ζԽ���
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

    // ������
    if (result == 1)
    {
        printf("X��ʤ��\n");
    }
    else if (result == 0)
    {
        printf("O��ʤ��\n");
    }
    else
    {
        printf("ƽ�֣�\n");
    }

    return 0;
}