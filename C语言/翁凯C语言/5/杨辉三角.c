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
    nt a[][5] =
    {
        {0,1,2,3,4},
        {2,3,4,5,6
    };
    �����Ǳ�������ģ����������ɱ���������ÿ��һ�������ŷָ�
    ���Ķ��ſ��Դ��ڣ��й��ϵĴ�ͳ
    ���ʡ�ԣ���ʾ����
    Ҳ�����ö�λ(*C99 ��׼)
*/

void yanghui(int rows);

int main()
{
    int rows;
    printf("������������ǵ�������");
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
        // !��һ�к����һ�ж�Ϊ1
        triangle[i][0] = 1;
        triangle[i][i] = 1;
        for (int j = 1; j < i; j++)
        { 
            // !�м���Ϊ��һ����������֮��
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