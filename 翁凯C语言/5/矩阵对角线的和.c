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
        {2,3,4,5,6
    };
    �����Ǳ�������ģ����������ɱ���������ÿ��һ�������ŷָ�
    ���Ķ��ſ��Դ��ڣ��й��ϵĴ�ͳ
    ���ʡ�ԣ���ʾ����
    Ҳ�����ö�λ(*C99 ��׼)
*/

// !����l��m�еľ���
void matrix_produce(int l, int m, int a[l][m])
{
    int i, j;
    for (i = 0; i < l; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
}

// !��ӡl��n�еľ���
void matrix_print(int l, int n, int c[l][n])
{
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

int main(void)
{
    int l, m;
    printf("�����뷽�������l������m��������ȣ���");
    scanf("%d %d", &l, &m);

    if (l != m)
    {
        printf("��������Ĳ��Ƿ�����������������\n");
        return 1;
    }
    int n = l;

    int a[n][n];
    matrix_produce(n, n, a);

    int sum_main = 0;
    for (int i = 0; i < n; i++)
    {
        sum_main += a[i][i];
    }

    int sum_anti = 0;
    for (int i = 0; i < n; i++)
    {
        int j = n - 1 - i;
        sum_anti += a[i][j];
    }

    int total_sum;
    if (n % 2 == 1)
    {
        int duplicate_i = (n - 1) / 2;
        total_sum = sum_main + sum_anti - a[duplicate_i][duplicate_i];
    }
    else
    {
        total_sum = sum_main + sum_anti;
    }

    printf("���Խ��ߺ�Ϊ��%d\n", sum_main);
    printf("���Խ��ߺ�Ϊ��%d\n", sum_anti);
    printf("�����Խ����ܺͣ��ظ�λ�ý�һ�Σ���%d\n", total_sum);

    return 0;
}