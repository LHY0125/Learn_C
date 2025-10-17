#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

// !
/*
	1.字符串常量
	  char*s = "Hello, world!";
	  s是一个指针，初始化为指向一个字符串常量
	  由于这个常量所在的地方，所以实际上s是const char*s，但是由于历史的原因，编译器接受不带const的写法
	  但是试图对s所指的字符串做写入会导致严重的后果
	  如果需要修改字符串，应该用数组:
	  char s[] = "Hello, world!";
	2.指针还是数组?
	  char *str ="Hello"
	  char word[]="Hello"
	  数组：这个字符串在这里
	  作为本地变量空间自动被回收
	  指针：这个字符串不知道在哪里
	  处理参数
	  动态分配空间
	3.char*是字符串？
	  字符串可以表达为char*的形式
	  char*不一定是字符串
	  本意是指向字符的指针，可能指向的是字符的数组（就像int*一样）
	  只有它所指的字符数组有结尾的0，才能说它所指的是字符串
*/

int main(void)
{
	/* 1.字符串的定义 */
	char *s="Hello World!";
	char *s2 = "Hello World!";
	char s3[] = "Hello World!";
	s[0] = 'B';

	printf("s =%p\n", s );
	printf("s2=%p\n", s2);
	printf("s3=%p\n", s3);
	s3[0] = 'B';
	printf("Here!s3[0]=%c\n", s3[0]);
	printf("Here!s[0]=%c\n", s[0]);

	return 0;
}