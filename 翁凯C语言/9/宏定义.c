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

// !宏定义
/*
    1.译预处理指令
      #开头的是编译预处理指令
      它们不是C语言的成分，但是C语言程序离不开它们
      #define用来定义一个宏
    2.#define
      #define <名字> <值>
      注意没有结尾的分号，因为不是C的语句
      名字必须是一个单词，值可以是各种东西
      在C语言的编译器开始编译之前，编译预处理程序(cpp)会把程序中的名字换成值
      完全的文本替换
      gcc --save-temps
    3.宏
      如果一个宏的值中有其他的宏的名字，也是会被替换的
      如果一个宏的值超过一行，最后一行之前的行末需要加\
      宏的值后面出现的注释不会被当作宏的值的一部分
    4.没有值的宏
      #define_DEBUG
      这类宏是用于条件编译的，后面有其他的编译预处理指令来检查这个宏是否已经被定义过了
    5.预定义的宏
      __LINE__  //当前行号
      __FILE__  //当前文件名
      __DATE__  //当前日期
      __TIME__  //当前时间  
      __STDC__  //如果编译器遵循ANSI C，其值为1
*/

#define PI 3.1415926

int main()
{
    // 设置控制台编码为UTF-8
#ifdef _WIN32
    system("chcp 65001 > nul"); // 设置控制台编码为UTF-8
    SetConsoleOutputCP(65001);  // 设置控制台输出编码
    SetConsoleCP(65001);        // 设置控制台输入编码
#endif

    printf("%f\n", 2*PI*3.0);

    return 0;
}