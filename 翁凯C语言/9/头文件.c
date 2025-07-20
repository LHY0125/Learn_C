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

// !头文件
/*
    1.头文件
      把函数原型放到一个头文件（以.h结尾）中，在需要调用这个函数的源代码文件（.c文件）中#include这个头文件，就能让编译器在编译的时候知道函数的原型
    2.#include
      #include是一个编译预处理指令，和宏一样，在编译之前就处理了
      它把那个文件的全部文本内容原封不动地插入到它所在的地方
      所以也不是一定要在.c文件的最前面#include
    3.""还是<>
      #include有两种形式来指出要插入的文件
      ""要求编译器首先在当前目录（.c文件所在的目录) 寻找这个文件，如果没有，到编译器指定的目录去找
      <>让编译器只在指定的目录去找
      编译器自己知道自己的标准库的头文件在哪里
      环境变量和编译器命令行参数也可以指定寻找头文件的目录
    4.#include的误区
      #include不是用来引入库的
      stdio.h里只有print的原型，print的代码在另外的地方，某个.lib(Windows)或.a(Unix)中
      现在的C语言编译器默认会引入所有的标准库
      #include <stdio.h>只是为了让编译器知道printf函数的原型，保证你调用时给出的参数值是正确的类型
    5.头文件
      在使用和定义这个函数的地方都应该#include这个头文件
      一般的做法就是任何.c都有对应的同名的.h，把所有对外公开的函数的原型和全局变量的声明都放进去
    6.不对外公开的函数
      在函数前面加上static就使得它成为只能在所在的编译单元中被使用的函数
      在全局变量前面加上static就使得它成为只能在所在的编译单元中被使用的全局变量
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