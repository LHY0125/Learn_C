#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

// !结构类型
/*
	1.在函数内/外
	  和本地变量一样，在函数内部声明的结构类型只能在函数内部使用
	  所以通常在函数外部声明结构类型，这样就可以被多个函数所使用了
	2.声明结构的形式
	  struct point{
			int x;
			int y;
	  };
	  struct point pl,p2;
	  pl和p2都是point里面有x和y的值

	  struct{
		  int x;
		  int y;
	  }pl,p2;
	  p1和p2都是一种无名结构,里面有x和y

	  struct point{
		  int x;
		  int y;
	  } pl,p2;
	  pl和p2都是point里面有x和y的值t
	  *对于第一和第三种形式，都声明了结构point。但是第二种形式没有声明point,只是定义了两个变量
	3.结构成员
	  结构和数组有点像
	  数组用口运算符和下标访问其成员
	  a[0]= 10;
	  结构用.运算符和名字访问其成员
	  today.day
	  student.firstName
	  pl.x pl.y
	4.结构运算
	  要访问整个结构，直接用结构变量的名字
	  对于整个结构，可以做赋值、取地址，也可以传递给函数参数
	  pl = (struct point)(5, 10};
	  相当于pl.x=5;pl.y= I0;
	  pl=p2;
	  相当于pl.x= p2.x;pl.y= p2.y;
	5.结构指针
	  和数组不同，结构变量的名字并不是结构变量的地址，必须使用&运算符
	  struct date *pDate = &today;
*/

struct data
{
	int month;
	int day;
	int year;
};

int main(void)
{
	struct data today;
	today = (struct data){07,31,2014};

	struct data day;
	day = today;
	day.year = 2015;

	printf("Today's date is %i-%i-%i.\n", today.year, today.month, today.day);
	printf("This month is %i-%i-%i.\n", day.year, day.month, day.day);

	return 0;
}