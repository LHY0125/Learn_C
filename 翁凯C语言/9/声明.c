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

// !声明
/*
    1.变量的声明
      int i;是变量的定义
      extern int i;是变量的声明
    2.声明和定义
      声明是不产生代码的东西
      函数原型
      变量声明
      结构声明
      宏声明
      枚举声明
      类型声明
      inline函数定义
      是产生代码的东西
    3.头文件
      只有声明可以被放在头文件中
      是规则不是法律
      否则会造成一个项目中多个编译单元里有重名的实体
      *某些编译器允许几个编译单元中存在同名的函数，或者用weak修饰符来强调这种存在
    4.重复声明
      同一个编译单元里,同名的结构不能被重复声明
      如果你的头文件里有结构的声明，很难这个头文件不会在一个编译单元里被#include多次
      所以需要“标准头文件结构”
    5.标准头文件结构
      #ifndef __LIST_HEAD__
      #define __LIST_HEAD__

      #include "node.h" 
      typedef struct _list { 
          Node* head;
          Node* tail;
      } List; 

      #endif 
      运用条件编译和宏，保证这个头文件在一个编译单元中只会被#include一次
      #pragma once也能起到相同的作用，但是不是所有的编译器都支持
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