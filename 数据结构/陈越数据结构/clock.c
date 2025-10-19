#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#ifdef _WIN32
#include <windows.h>
#include <direct.h>
#endif

// clock_t 是一个无符号整数类型，用于表示时钟 ticks 的数量。
clock_t start, stop;

// 记录程序运行时间
double duration;

// 示例函数：计算1到1000000的和
void MyFunction()
{
    long long sum = 0;
    for (int i = 1; i <= 1000000; i++)
    {
        sum += i;
    }
    printf("计算结果：1到1000000的和为 %lld\n", sum);
}

int main()
{
    // 设置控制台编码为UTF-8,防止中文乱码
#ifdef _WIN32
    system("chcp 65001 > nul"); // 设置控制台编码为UTF-8
    SetConsoleOutputCP(65001);  // 设置控制台输出编码
    SetConsoleCP(65001);        // 设置控制台输入编码
    _mkdir("records");
#endif

    // 记录程序开始时间
    start = clock();
    // 要测试的代码
    MyFunction();
    // 记录程序结束时间
    stop = clock();
    // 计算程序运行时间
    duration = ((double)(stop - start)) / CLOCKS_PER_SEC;
    printf("程序运行时间为：%f 秒\n", duration);

    return 0;
}