#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

// !数组是一种特殊的指针，数组名就是数组的首地址
/*
    数组变量本身表达地址,所以
    int a[10]; int*p=a;//无需用&取地址
    但是数组的单元表达的是变量，需要用&取地址
    a == &a[O]
    []运算符可以对数组做，也可以对指针做:
    p[0] <==>a[0]
    *运算符可以对指针做，也可以对数组做：
    *a= 25:
    数组变量是const的指针，所以不能被赋值
    int a[] <==> int * const a=...
*/

void minmax(int a[], int len, int *max, int *min);

int main(void)
{
    int c[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 12, 13, 14, 16, 17, 21, 23, 55};
    int min, max;
    printf("min sizeof(c) = %lu\n", sizeof(c));
    minmax(c, sizeof(c) / sizeof(c[0]), &max, &min);
    printf("max = %d, min = %d\n", max, min);

    int *p = &min;
    printf("*p = %d\n", *p);
    printf("p[0]=%d\n", p[0]);

    return 0;
}

void minmax(int a[], int len, int *max, int *min)
{
    int i;
    printf("minmax sizeof(a) = %lu\n", sizeof(a));
    *max = *min = a[0];
    for (i = 1; i < len; i++)
    {
        if (a[i] < *min)
        {
            *min = a[i];
        }
        if (a[i] > *max)
        {
            *max = a[i];
        }
    }
}