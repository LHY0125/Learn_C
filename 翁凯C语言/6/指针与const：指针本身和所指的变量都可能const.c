#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

// !指针和const
/*
	指针本身和所指的变量都可能const
	1.指针是const：
	  表示一旦得到了某个变量的地址，不能再指向其他变量
	  int *const q= &i;    // q是const
	  *q=26;    // OK
	  q++;      // ERROR
	2.所指是const
	  表示不能通过这个指针去修改那个变量(并不 能使得那个变量成为const）
	  const int *p = &i;
	  *p = 26;  // ERROR! (*p)是 const
	  i=26;     //OK
	  p=&j;     //OK
	3.判断：const在*前边，是表示不能通过这个指针去修改那个变量；const在*后边，是表示一旦得到了某个变量的地址，不能再指向其他变量
*/

// !const数组
/*
	const int a[]= {1,2,3,4,5,6,};
	数组变量已经是const的指针了，这里的const
	表明数组的每个单元都是const int
	所以必须通过初始化进行赋值
*/

// !保护数组值
/*
	因为把数组传入函数时传递的是地址，所以那个函数 内部可以修改数组的值
	为了保护数组不被函数破坏，可以设置参数为const
	int sum(const int a[], int length);
*/

int main(void)
{

	return 0;
}