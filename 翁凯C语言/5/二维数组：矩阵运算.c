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

// !���������ĳ˷�����
int main()
{
    int l, m, n;
    int i, j, k;

    printf("����������������������\n");
    scanf("%d %d %d", &l, &m, &n);
    int a[l][m];
    int b[m][n];
    int c[l][n];

    // !���������
    printf("���������a��Ԫ�أ�\n");
    for (i = 0; i < l; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("���������b��Ԫ�أ�\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }

    // !����ĳ˷�����
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

    // !����Ĵ�ӡ
    printf("����a�;���b�ĳ˷��������cΪ��\n");
    for (i = 0; i < l; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    return 0;
}
