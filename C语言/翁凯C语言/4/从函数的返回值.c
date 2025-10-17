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

以下是该函数的文档注释:

/**
 * @brief 计算从begin到end之间所有整数的和
 * @param begin 起始数(包含)
 * @param end 结束数(包含) 
 * @return 返回区间内所有整数的累加和
 * @note begin必须小于等于end
 */
int num_sum(int begin, int end)
/*
    函数的头void num_sum(int begin, int end)
    int是返回值类型，int需要返回一个值，但void不需要返回值
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
    return sum; // 函数的返回值用return返回
}

int main()
{
    printf("%d\n", num_sum(1, 10));
    printf("%d\n", num_sum(20, 30));
    printf("%d\n", num_sum(35, 45));

    return 0;
}