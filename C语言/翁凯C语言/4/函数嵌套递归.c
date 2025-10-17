#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

int jiecheng(int n);

int main()
{
    int n;
    printf("请输入一个整数：");
    scanf("%d", &n);
    printf("%d\n", jiecheng(n));
    
    return 0;
}

int jiecheng(int n)
{
    int sum = 1;
    if (n == 1)
        return sum;
    else
        sum = n * jiecheng(n-1);
}