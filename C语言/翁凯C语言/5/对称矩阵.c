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

int check_symmetry(int matrix[][200], int size);

int main()
{
    int n;
    scanf("%d", &n);
    int matrix1[100][100], matrix2[100][100], matrix3[100][100], matrix4[100][100];

    // ��ȡ�ĸ�n��n�ľ���
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix1[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix2[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix3[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix4[i][j]);
        }
    }

    int big_matrix[200][200];
    // ����һ���������ϡ����ϡ����¡�����ƴ��
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            big_matrix[i][j] = matrix1[i][j];
            big_matrix[i][j + n] = matrix2[i][j];
            big_matrix[i + n][j] = matrix3[i][j];
            big_matrix[i + n][j + n] = matrix4[i][j];
        }
    }
    if (check_symmetry(big_matrix, 2 * n))
    {
        printf("YES\n");
        return 0;
    }

    // ���������������Ϻ�����
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            big_matrix[i][j] = matrix1[i][j];
            big_matrix[i][j + n] = matrix3[i][j];
            big_matrix[i + n][j] = matrix2[i][j];
            big_matrix[i + n][j + n] = matrix4[i][j];
        }
    }
    if (check_symmetry(big_matrix, 2 * n))
    {
        printf("YES\n");
        return 0;
    }

    // ���������������Ϻ�����
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            big_matrix[i][j] = matrix4[i][j];
            big_matrix[i][j + n] = matrix2[i][j];
            big_matrix[i + n][j] = matrix3[i][j];
            big_matrix[i + n][j + n] = matrix1[i][j];
        }
    }
    if (check_symmetry(big_matrix, 2 * n))
    {
        printf("YES\n");
        return 0;
    }

    // �����ģ��������Ϻ����ϣ����º�����
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            big_matrix[i][j] = matrix2[i][j];
            big_matrix[i][j + n] = matrix1[i][j];
            big_matrix[i + n][j] = matrix4[i][j];
            big_matrix[i + n][j + n] = matrix3[i][j];
        }
    }
    if (check_symmetry(big_matrix, 2 * n))
    {
        printf("YES\n");
        return 0;
    }

    printf("NO\n");
    return 0;
}

// !�������Ƿ�Ϊ�Գƾ���
int check_symmetry(int matrix[][200], int size)
{
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