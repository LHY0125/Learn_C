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

// !返回指针的函数
/*
    1.*返回指针的函数
      返回本地变量的地址是危险的
      返回全局变量或静态本地变量的地址是安全的
      返回在函数内malloc的内存是安全的，但是容易造成问题
      最好的做法是返回传入的指针
    2.tips
      不要使用全局变量来在函数间传递参数和结果
      尽量避免使用全局变量
      丰田汽车的案子
      *使用全局变量和静态本地变量的函数是线程不安全的
*/

int *f(void);
void g(void);

int main()
{
    // 设置控制台编码为UTF-8
#ifdef _WIN32
    system("chcp 65001 > nul"); // 设置控制台编码为UTF-8
    SetConsoleOutputCP(65001);  // 设置控制台输出编码
    SetConsoleCP(65001);        // 设置控制台输入编码
#endif

    int *p=f();
    printf("*p = %d\n", *p);
    g();
    printf("*p = %d\n", *p);

    return 0;
}

int *f(void)
{
    int i=12;
    return &i;
}

void g(void)
{
    int k = 14;
    printf("k = %d\n", k);
}