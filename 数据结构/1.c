#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#include <direct.h>
#endif

// 计算斐波那契第n项（公式法）
long long fib_binet(int n)
{
    const double phi = (1 + sqrt(5)) / 2; // 黄金分割比
    const double sqrt5 = sqrt(5);         // 根号5
    double value = pow(phi, n) / sqrt5;   // 核心计算项
    return llround(value);                // 四舍五入取整（避免小数误差）
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

    // 计算第47项及后续3项（47~50项）
    for (int n = 47; n <= 50; n++)
    {
        long long result = fib_binet(n);
        printf("第%d项: %lld\n", n, result);
    }
    return 0;
}