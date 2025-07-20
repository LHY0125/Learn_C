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

void matrix_produce(int l,int m, int a[l][m]);
void matrix_multiply( int l, int m, int n, int a[l][m], int b[m][n], int c[l][n]);
void matrix_print(int l, int n, int c[l][n]);

// !���������ĳ˷�����
int main()
{
    int l, m, q, n;
    
    // !����Ķ���
    printf("���������a��������������\n");
    scanf("%d %d", &l, &m);
    printf("���������b��������������\n");
    scanf("%d %d", &q, &n);
    while (m!=q)
    {
        printf("����a�����������b����������ȣ��޷����о���˷����㣡\n");
        printf("�������������a��������������\n");
        scanf("%d %d", &l, &m);
        printf("�������������b��������������\n");
        scanf("%d %d", &q, &n);
    }

    int a[l][m];
    int b[m][n];
    int c[l][n];

    // !���������
    printf("���������a��Ԫ�أ�\n");
    matrix_produce(l, m, a);

    printf("���������b��Ԫ�أ�\n");
    matrix_produce(m, n, b);

    // !����ĳ˷�����
    matrix_multiply(l, m, n, a, b, c);

    // !����Ĵ�ӡ
    printf("����a�;���b�ĳ˷��������cΪ��\n");
    matrix_print(l, n, c);

    return 0;
}

void matrix_produce(int l,int m, int a[l][m])
{
    // !���������
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
    // !����ĳ˷�����
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
    // !����Ĵ�ӡ
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