#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

// !指针应用场景
/*
    1.函数返回多个值,某些值不方便直接返回,只能通过指针返回，传入的参数实际上是需要保存带回的结果的变量
    2.函数返回运算的状态，结果通过指针返回。常用的套路是让函数返回特殊的不属于有效范围内的 值来表示出错：-1或0（在文件操作会看到大量的例子）。当任何数值都是有效的可能结果时,就得分开返

*/

void swap(int *pa, int *pb);
void minmax(int c[], int len, int *max, int *min);
int divide(int a, int b, int *result);

int main(void)
{
    /* 1.交换两个变量的值 */
    int a = 5;
    int b = 6;
    
    swap(&a, &b);
    printf("a = %d, b = %d\n", a, b);

    /* 2.返回多个值*/
    int c[] = {1,2,3,4,5,6,7,8,9,12,13,14,16,17,21,23,55};
    int min, max;
    minmax(c, sizeof(c) / sizeof(c[0]), &max, &min);
    printf("max = %d, min = %d\n", max, min);

    /* 3.返回运算的状态 */
    int d=5;
    int e=6;
    int f;
    if (divide(d,e, &f))
    {
        printf("%d/%d = %d\n", d, e, f);
    }

    return 0;
}

void swap(int *pa, int *pb)
{
    int t = *pa;
    *pa = *pb;
    *pb = t;
}

void minmax(int a[], int len, int *max, int *min)
{
    int i;
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

int divide(int a, int b, int *result)
{
    if (b==0)
    {
        return 0;
    }
    else
    {
        *result = a / b;
    }

    return 1;
}