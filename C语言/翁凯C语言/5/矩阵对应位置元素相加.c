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

// ! ��̬�����ά���飨int ** ���ͣ�
int **allocate_matrix(int rows, int cols);

// ! ����l��m�еľ������� int ** ���ͣ�
void matrix_produce(int l, int m, int **a);

// ! ��ӡl��n�еľ������� int ** ���ͣ�
void matrix_print(int l, int n, int **c);

// ! ������������ĺͣ�������ӣ�
int **add_matrices(int **A, int n1, int m1, int **B, int n2, int m2, int *result_rows, int *result_cols);

// ! �ͷŶ�ά�����ڴ�
void matrix_free(int **matrix, int rows);

int main()
{
    // ����A��B��������
    int n1, m1, n2, m2;

    // ��������������
    int result_rows, result_cols;

    // ! �������A������������̬�����ڴ�
    printf("�������A���������������ÿո�ָ���: ");
    scanf("%d %d", &n1, &m1);

    // ��̬�������A��int ** ���ͣ�
    int **A = allocate_matrix(n1, m1); 
    printf("�����������A��Ԫ�أ�ÿ��%d�����ÿո�ָ���:\n", m1);
    matrix_produce(n1, m1, A);

    // ! �������B������������̬�����ڴ�
    printf("�������B���������������ÿո�ָ���: ");
    scanf("%d %d", &n2, &m2);

    // ��̬�������B��int ** ���ͣ�
    int **B = allocate_matrix(n2, m2);
    printf("�����������B��Ԫ�أ�ÿ��%d�����ÿո�ָ���:\n", m2);
    matrix_produce(n2, m2, B);

    // ! ���������ӣ�������ӣ�
    int **result = add_matrices(A, n1, m1, B, n2, m2, &result_rows, &result_cols);

    // ! ����������
    printf("\n�������������: %d��%d��:\n", result_rows, result_cols);
    matrix_print(result_rows, result_cols, result);

    // ! �ͷ����ж�̬������ڴ�
    matrix_free(A, n1);
    matrix_free(B, n2);
    matrix_free(result, result_rows);

    return 0;
}

// ! ��̬�����ά���飨int ** ���ͣ�
int **allocate_matrix(int rows, int cols)
{
    int **matrix = (int **)malloc(rows * sizeof(int *)); // ������ָ������
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = (int *)malloc(cols * sizeof(int)); // ����ÿ�е��пռ�
    }
    return matrix;
}

// ! ����l��m�еľ������� int ** ���ͣ�
void matrix_produce(int l, int m, int **a)
{
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &a[i][j]); // ͨ��ָ����ʶ�̬����ľ���Ԫ��
        }
    }
}

// ! ������������ĺͣ�������ӣ�
int **add_matrices(int **A, int n1, int m1, int **B, int n2, int m2, int *result_rows, int *result_cols)
{
    // ����������ĳߴ磨���������������ֵ��
    *result_rows = (n1 > n2) ? n1 : n2;
    *result_cols = (m1 > m2) ? m1 : m2;
    int **result = allocate_matrix(*result_rows, *result_cols); // ��̬����������

    // ��λ�ü�����ӽ���������߼���
    for (int i = 0; i < *result_rows; i++)
    {
        for (int j = 0; j < *result_cols; j++)
        {
            int a = (i < n1 && j < m1) ? A[i][j] : 0; // A������Χ��Ϊ0
            int b = (i < n2 && j < m2) ? B[i][j] : 0; // B������Χ��Ϊ0
            result[i][j] = a + b;
        }
    }
    return result;
}

// ! ��ӡl��n�еľ������� int ** ���ͣ�
void matrix_print(int l, int n, int **c)
{
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", c[i][j]); // ͨ��ָ����ʶ�̬����ľ���Ԫ��
        }
        printf("\n");
    }
}

// ! �ͷŶ�ά�����ڴ�
void matrix_free(int **matrix, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        free(matrix[i]); // �ͷ�ÿ�е��ڴ�
    }
    free(matrix); // �ͷ���ָ������
}