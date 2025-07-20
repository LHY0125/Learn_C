#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

// !��̬�����ά���飨int ** ���ͣ�
int **allocate_matrix(int rows, int cols);

// !����l��m�еľ���
void matrix_produce(int l, int m, int a[l][m]);

// !��ӡl��n�еľ���
void matrix_print(int l, int n, int c[l][n]);

// !����ĳ˷�����
void matrix_multiply(int l, int m, int n, int a[l][m], int b[m][n], int c[l][n]);

// !�������Ƿ�Գ�
int matrix_check_symmetry(int matrix[][200], int size);

// !ת�þ��󣺽�src[l][m]ת��Ϊdest[m][l]
void matrix_transpose(int l, int m, int src[l][m], int dest[m][l]);

// !���Ҿ����е����ֵ
int matrix_max_value(int l, int m, int mat[l][m]);

// !�������Խ��ߺͣ�i == j��
int calculate_main_diagonal(int n, int mat[n][n]);

// !���㸱�Խ��ߺͣ�i + j == n-1��
int calculate_anti_diagonal(int n, int mat[n][n]);

// !������������ĺͣ�������ӣ�
int **add_matrices(int **A, int n1, int m1, int **B, int n2, int m2, int *result_rows, int *result_cols);

// !�ҳ���ά�����еİ��㣨�����������С��
void matrix_find_saddle_point(int rows, int cols, int matrix[rows][cols]);

// !�ͷŶ�ά�����ڴ�
void matrix_free(int **matrix, int rows);

int main(void)
{
    
    return 0;
}

int **allocate_matrix(int rows, int cols)
{
    // !��̬�����ά���飨int ** ���ͣ�
    int **matrix = (int **)malloc(rows * sizeof(int *)); // ������ָ������
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = (int *)malloc(cols * sizeof(int)); // ����ÿ�е��пռ�
    }
    return matrix;
}

void matrix_produce(int l, int m, int a[l][m])
{
    // !���������
    int i, j;
    for (i = 0; i < l; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
}

void matrix_multiply(int l, int m, int n, int a[l][m], int b[m][n], int c[l][n])
{
    // !����ĳ˷�����
    int i, j, k;
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

int matrix_check_symmetry(int matrix[][200], int size)
{
    // !�������Ƿ�Գ�
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

void matrix_transpose(int l, int m, int src[l][m], int dest[m][l])
{
    // !ת�þ��󣺽�src[l][m]ת��Ϊdest[m][l]
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < m; j++)
        {
            dest[j][i] = src[i][j]; // ����ת���߼�
        }
    }
}

int matrix_max_value(int l, int m, int mat[l][m])
{
    // !����mat�����е����ֵ
    int max = mat[0][0]; // ��ʼ�����ֵΪ��һ��Ԫ��
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] > max)
            {
                max = mat[i][j]; // �������ֵ
            }
        }
    }
    return max; // �������ֵ
}

int calculate_main_diagonal(int n, int mat[n][n])
{
    // !�������Խ��ߺͣ�i == j��
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += mat[i][i];
    }
    return sum;
}

int calculate_anti_diagonal(int n, int mat[n][n])
{
    // !���㸱�Խ��ߺͣ�i + j == n-1��
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int j = n - 1 - i;
        sum += mat[i][j];
    }
    return sum;
}

int **add_matrices(int **A, int n1, int m1, int **B, int n2, int m2, int *result_rows, int *result_cols)
{
    // !������������ĺͣ�������ӣ�
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


void matrix_find_saddle_point(int rows, int cols, int matrix[rows][cols])
{
    // !�ҳ���ά�����еİ��㣨�����������С��
    // ����Ƿ��ҵ�����
    int has_saddle = 0;

    for (int i = 0; i < rows; i++)
    {
        // !����1���ҵ���ǰ�е����ֵ
        int row_max = matrix[i][0];
        int col_max = 0;

        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] > row_max)
            {
                row_max = matrix[i][j];
                col_max = j;
            }
        }

        // !����2�����������ֵ�Ƿ��������е���Сֵ
        int col_min = matrix[0][col_max]; // ��ʼ������СֵΪ��ǰ�е�һ��
        for (int k = 1; k < rows; k++)
        {
            // ������ǰ�е�������
            if (matrix[k][col_max] < col_min)
            {
                col_min = matrix[k][col_max]; // ��������Сֵ
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
    if (has_saddle == 0)
    {
        printf("�þ���û�а���!\n");
    }
}

void matrix_free(int **matrix, int rows)
{
    // !�ͷŶ�ά�����ڴ�
    for (int i = 0; i < rows; i++)
    {
        free(matrix[i]); // �ͷ�ÿ�е��ڴ�
    }
    free(matrix); // �ͷ���ָ������
}