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

// !全局变量
/*
	1.定义在函数外面的变量是全局变量
	2.全局变量具有全局的生存期和作用域
	  它们与任何函数都无关
	  在任何函数内部都可以使用它们
	3.全局变量初始化
	  没有做初始化的全局变量会得到0值
	  指针会得到NULL值
	  只能用编译时刻已知的值来初始化全局变量
	  它们的初始化发生在main函数之前
	4.被隐藏的全局变量
	  如果函数内部存在与全局变量同名的变量，则全局变量被隐藏
*/

int f(void);

int gALL = 12;

int main()
{
	// 设置控制台编码为UTF-8
#ifdef _WIN32
	system("chcp 65001 > nul"); // 设置控制台编码为UTF-8
	SetConsoleOutputCP(65001);	// 设置控制台输出编码
	SetConsoleCP(65001);		// 设置控制台输入编码
#endif

	printf("in %s gALL = %d\n", __func__, gALL);
	f();
	printf("in %s gALL = %d\n", __func__, gALL);

	return 0;
}

int f(void)
{
	printf("in %s gALL = %d\n", __func__, gALL);
	gALL+=2;
	printf("in %s gALL = %d\n", __func__, gALL);

	return 0;
}