#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

int num_sum(int a, int b)   // ��������
{
    int sum = 0;
    for (int i = a; i <= b;i++)
    {
        sum += i;
    }
    return sum;
}

int main()
{
    int a, b;
    printf("����������������");
    scanf("%d %d", &a, &b);
    printf("%d��%d֮����������ĺͣ�sum = %d\n", a, b, num_sum(a, b));

    return 0;
}