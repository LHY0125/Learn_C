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

// !二进制文件
/*
	1.二进制文件
	  其实所有的文件最终都是二进制的文本文件无非是用最简单的方式可以读写的文件
	  more、tail
	  cat
	  vi
	  而二进制文件是需要专门的程序来读写的文件文本文件的输入输出是格式化,可能经过转码
	2.文本 vs 二进制
	  Unix喜欢用文本文件来做数据存储和程序配置
	  交互式终端的出现使得人们喜欢用文本和计算机“talk"
	  Unix的shel提供了一些读写文本的小程序
	  Windows喜欢用二进制文件
	  DOS是草根文化，并不继承和熟悉Unix文化
	  PC刚开始的时候能力有限，DOS的能力更有限，二进制更接近底层
	3.文本 vs 二进制
	  文本的优势是方便人类读写,而且跨平台
	  文本的缺点是程序输入输出要经过格式化，开销大
	  二进制的缺点是人类读写困难,而且不跨平台
	  int的大小不一致，大小端的问题.
	  二进制的优点是程序读写快
	4.程序为什么要文件
	  配置Unix用文本，Windows用注册表
	  数据稍微有点量的数据都放数据库了
	  媒体这个只能是二进制的
	  现实是，程序通过第三方库来读写文件，很少直接读写二进制文件了
	5.为什么nitem?
	  因为二进制文件的读写一般都是通过对一个结构变量的操作来进行的
	  于是nitem就是用来说明这次读写几个结构变量！
	6.在文件中定位
	  long ftell(FILE *stream);
	  int fseek(FILE *stream, long offset, int whence);
	  SEEK_SET:从头开始
	  SEEK_CUR:从当前位置开始
	  SEEK_END:从尾开始(倒过来)
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