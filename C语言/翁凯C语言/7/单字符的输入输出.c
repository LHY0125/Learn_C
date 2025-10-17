#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

// !单字符的输入输出
/*
	1.putchar
	  int putchar(int c);
	  向标准输出写一个字符
	  返回写了几个字符，EOF（-1）表示写失败
	2.getchar
	  int getchar(void);
	  从标准输入读入一个字符
	  返回类型是int是为了返回EOF (-1）
	  Windows->Ctrl-Z
	  Unix—>Ctrl-D
	3.

*/

int main(void)
{
	int ch;

	while ((ch=getchar())!=EOF)
	{
		putchar(ch);
	}

	printf("EOF\n");
	
	return 0;
}