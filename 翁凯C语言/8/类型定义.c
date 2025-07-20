#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

// !类型定义
/*
	1.自定义数据类型(typedef)
	  C语言提供了一个叫做typedef的功能来声明一个已有的数据类型的新名字。比如:
	  typedef int Length;
	  使得Length 成为int类型的别名。
	  这样，Length这个名字就可以代替int出现在变量定义和参数声明的地方了：
	  Length a, b, len;
	  Length numbers[10];
	2.Typedef
	  声明新的类型的名字
	  新的名字是某种类型的别名
	  改善了程序的可读性
	  typedef long int64_t;		//! 重载已有的类型名字新名字的含义更清晰具有可移植性
	  typedef struct ADate {
		  int month;
		  int day;
		  int year;
		  };Date;				//! Data->struct ADate,简化了复杂的名字
	  int64_t i = 100000000000;
	  Date d = [9, 1, 2005];
	3.typedef int Length; // Length就等价于int类型
	  typedef char* Strings[IO]; // Strings是10个字符串的数组的类型
	  typedef struct node{  
	  	  int data; 
		  struct node *next; 
	  }aNode;
	 或
	  typedef struct node aNode;//这样用aNode就可以代替
	  struct node
*/

int main(void)
{
	

	return 0;
}