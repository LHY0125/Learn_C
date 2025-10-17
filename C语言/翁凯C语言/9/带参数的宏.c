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

// !带参数的宏
/*
    1.函数的宏
      #define cube(x) ((x)*(x)*(x))
      宏可以带参数
    2.带参数的宏的原则
      一切都要括号
      整个值要括号
      参数出现的每个地方都要括号
      #define RADTODEG(x) ((x) * 57.29578)

      可以带多个参数
      #define MIN(a,b) ((a)>(b)?(b):(a))
      也可以组合(嵌套）使用其他宏
    3.在大型程序的代码中使用非常普遍
      可以非常复杂，如“产生”函数
      在#和##这两个运算符的帮助下
      存在中西方文化差异
      部分宏会被inline函数替代
*/

#define cube(x) ((x)*(x)*(x))

int main()
{
    // 设置控制台编码为UTF-8
#ifdef _WIN32
    system("chcp 65001 > nul"); // 设置控制台编码为UTF-8
    SetConsoleOutputCP(65001);  // 设置控制台输出编码
    SetConsoleCP(65001);        // 设置控制台输入编码
#endif

    printf("cube(5) = %d\n", cube(5));

    return 0;
}