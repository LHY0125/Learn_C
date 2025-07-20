#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

// !指针函数
/*
	一个函数不仅可以返回整型、字符型等值，也可在C语言中，以返回指针类型的值，返回指针类型值的函数就称为指针函数。
	1.定义指针函数的形式如下:
	  类型标识符 *函数名(形参表)
	  {
		  函数体
	  }
	2.指针函数的调用与普通函数的调用相同，只要注意其返口值是一个指针。
	
	* int (*p)()是一个变量声明，表示p是一个指向函数入口地址的指针变量(函数指针)，该函数的返回值是整型数据，“(*p)”两边的括号不能少
	* int *p()则是函数声明，表示p是一个指针函数，其返回值是一个指向整型数据的指针，“*p”两边没有括号。作为函数声明，在括号内最好写入形式参数，这样便于与变量声明区别。
*/

// !指针函数：返回指向整数的指针
int *max(int *a, int *b)
{
	if (*a > *b)
		return a;
	else
		return b;
}

int main()
{
	int x, y;
	printf("Enter two integers: ");
	scanf("%d %d", &x, &y);
	
	// 调用指针函数
	int *result = max(&x, &y);
	printf("The larger number is %d\n", *result);

	return 0;
}