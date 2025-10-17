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

// !静态本地变量
/*
    1.静态本地变量
      在本地变量定义时加上static修饰符就成为静态本地变量
      当函数离开的时候，静态本地变量会继续存在并保持其值
      静态本地变量的初始化只会在第一次进入这个函数时做，以后进入函数时会保持上次离开时的值
    2.静态本地变量与全局变量的区别
      静态本地变量实际上是特殊的全局变量
      它们位于相同的内存区域
      静态本地变量具有全局的生存期，函数内的局部作用域
      static在这里的意思是局部作用域(本地可访问)
*/

int f(void);

int gALL = 12;

int main()
{
    // 设置控制台编码为UTF-8
#ifdef _WIN32
    system("chcp 65001 > nul"); // 设置控制台编码为UTF-8
    SetConsoleOutputCP(65001);  // 设置控制台输出编码
    SetConsoleCP(65001);        // 设置控制台输入编码
#endif

    f();

    return 0;
}

int f(void)
{
    int k = 0;
    static int gall = 1;
    printf("&gALL=%p\n", &gALL);
    printf("&gall=%p\n", &gall);
    printf("&k   =%p\n", &k);

    printf("in %s gall = %d\n", __func__, gall);
    gall += 2;
    printf("agn in %s gall = %d\n", __func__, gall);

    return 0;
}