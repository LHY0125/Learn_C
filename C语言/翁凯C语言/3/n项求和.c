#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
    int N;
    printf("����������N: ");
    scanf("%d", &N);
    double a = 2.0, b = 1.0, sum = 0.0;
    
    for (int i = 0; i < N; i++)
    {
        sum += a / b;
        double next_a = a + b;  // ������һ��ķ���
        double next_b = a;      // ������һ��ķ�ĸ
        a = next_a;             // ���·���
        b = next_b;             // ���·�ĸ
    }
    printf("%.2f\n", sum);

    return 0;
}