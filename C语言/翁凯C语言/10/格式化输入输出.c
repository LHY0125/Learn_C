#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#ifdef _WIN32
#include <windows.h>
#include <direct.h>
#endif

// !格式化输入输出
/*
    1.格式化的输入输出
      printf
      %[flags][width][.prec][hlL]type
      scanf
      %[flag]type
    2.printf和scanf的返回值
      读入的项目数
      输出的字符数
      在要求严格的程序中，应该判断每次调用scanf或print的返回值，从而了解程序运行中是否存在问题
*/

int main()
{
    // 设置控制台编码为UTF-8
#ifdef _WIN32
    system("chcp 65001 > nul"); // 设置控制台编码为UTF-8
    SetConsoleOutputCP(65001);  // 设置控制台输出编码
    SetConsoleCP(65001);        // 设置控制台输入编码
#endif

    printf("%+9d\n", 123);
    printf("%+9d\n", -123);
    printf("%-9d\n", 123);

    printf("%+09d\n", 123);
    printf("%+09d\n", -123);

    int n;
    printf("%dty%n\n", 12345, &n);

    return 0;
}