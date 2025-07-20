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

// !����l��m�еľ��󣨣�
void matrix_produce(int l, int m, int a[l][m]);

// !�ҳ���ά�����еİ��㣬����λ���ϵ�Ԫ���ڸ���������ڸ�������С,Ҳ����û�а���
void matrix_find_saddle_point(int rows, int cols, int matrix[rows][cols]);

// !��ӡl��n�еľ��󣨣�
void matrix_print(int l, int n, int c[l][n]);

// !�ͷŶ�ά�����ڴ�
void matrix_free(int **matrix, int rows);

int main()
{
    int l, m;
    printf("���������������������ÿո�ָ���: ");
    scanf("%d %d", &l, &m);

    int matrix[l][m];
    printf("�����������Ԫ�أ�ÿ��%d�����ո�ָ���:\n", m);
    matrix_produce(l, m, matrix);

    printf("����ľ���Ϊ��\n");
    matrix_print(l, m, matrix);

    matrix_find_saddle_point(l, m, matrix);

    return 0;
}

// ! ����l��m�еľ���
void matrix_produce(int l, int m, int a[l][m])
{
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
}

// !�ҳ���ά�����еİ��㣨�����������С��
void matrix_find_saddle_point(int rows, int cols, int matrix[rows][cols])
{
    // ����Ƿ��ҵ�����
    int has_saddle = 0;
    
    for (int i = 0; i < rows; i++)
    {
        // !����1���ҵ���ǰ�е����ֵ
        int row_max = matrix[i][0];
        int col_max = 0;

        for (int j = 0; j < cols;j++)
        {
            if (matrix[i][j]>row_max)
            {
                row_max = matrix[i][j];
                col_max = j;
            }
        }

        // !����2�����������ֵ�Ƿ��������е���Сֵ
        int col_min = matrix[0][col_max];       // ��ʼ������СֵΪ��ǰ�е�һ��
        for (int k = 1; k < rows; k++)
        {
            // ������ǰ�е�������
            if (matrix[k][col_max] < col_min)
            {
                col_min = matrix[k][col_max];   // ��������Сֵ
            }
        }

        // !����3���ж��Ƿ�Ϊ���㣨�����������С��
        if (row_max == col_min)
        {
            printf("��������Ϊ(%d, %d),ֵΪ:%d\n", i, col_max, row_max);
            has_saddle = 1;
        }
    } 
   
    // δ�ҵ�����ʱ��ʾ
    if (has_saddle==0)
    {
        printf("�þ���û�а���!\n");
    }
}

// !��ӡl��n�еľ������� int ** ���ͣ�
void matrix_print(int l, int n, int c[l][n])
{
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", c[i][j]);     // ͨ��ָ����ʶ�̬����ľ���Ԫ��
        }
        printf("\n");
    }
}

// !�ͷŶ�ά�����ڴ�
void matrix_free(int **matrix, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        free(matrix[i]);    // �ͷ�ÿ�е��ڴ�
    }
    free(matrix);           // �ͷ���ָ������
}