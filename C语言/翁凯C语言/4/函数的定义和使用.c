#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

/*
    函数定义:函数是一段代码的封装，可以重复使用
    函数的声明:告诉编译器函数的名字，函数的参数，返回值类型
    函数的调用:使用函数名调用函数，并传入参数
*/

void num_sum(int begin, int end)
/*
    函数的头void num_sum(int begin, int end)
    void是返回值类型
    num_sum是函数名
    int是参数类型
    begin，end是参数名
*/
{
    // 函数体，即函数要执行的代码
    int sum = 0; 
    for (int i = begin; i <= end; i++)      
    {
        sum += i;
    }
    printf("%d到%d的和为%d\n", begin, end, sum);
}

int main()
{
    num_sum(1, 10);
    num_sum(20, 30);
    num_sum(35, 45);

    return 0;
}