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

// !大程序
/*
    1.多个.c文件
      main()里的代码太长了适合分成几个函数
      一个源代码文件太长了适合分成几个文件
      两个独立的源代码文件不能编译形成可执行的程序
    2.项目
      在Dev C++中新建一个项目，然后把几个源代码文件加入进去
      对于项目,Dev C++的编译会把一个项目中所有的源代码文件都编译后，链接起来
      有的IDE有分开的编译和构建两个按钮，前者是对单个源代码文件编译，后者是对整个项目做链接
    3.编译单元
      一个.c文件是一个编译单元编译器每次编译只处理一个编译单元
*/

int main()
{
    // 设置控制台编码为UTF-8
#ifdef _WIN32
    system("chcp 65001 > nul"); // 设置控制台编码为UTF-8
    SetConsoleOutputCP(65001);  // 设置控制台输出编码
    SetConsoleCP(65001);        // 设置控制台输入编码
#endif

    

    return 0;
}