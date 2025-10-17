#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
    // !定义并初始化变量
    int a = 0; // 用户输入的第一个整数，作为数列的基础数字
    int n = 0; // 用户输入的第二个整数，表示数列的项数

    // !获取用户输入
    printf("请输入两个整数a和n：");
    scanf("%d %d", &a, &n); // 读取用户输入的两个整数

    int sum = 0;   // 用于存储数列的和
    int b = a;     // 保存a的初始值，用于后续计算
    int count = 1; // 循环计数器，从1开始到n结束

    // !计算数列的和
    while (count <= n) // 循环n次
    {
        sum = sum + a;  // 将当前项a加到总和sum中
        a = a * 10 + b; // 生成下一项：将当前项乘以10再加上初始值b
        count++;        // 计数器递增
    }

    // !输出结果
    printf("数列之和为%d\n", sum);

    return 0;
}