#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

// !字符串数组
/*
	1.字符串数组
	  char* *a
		a是一个指针，指向另一个指针，那个指针指向一个字符(串）
	  char a[][]
	2.程序参数
	  int main(int argc, char const *argv[])
	  argv[0]是命令本身
	  当使用Unix的符号链接时，反映符号链接的名字
*/

int main(int argc, char const *argv[])
{
	int i;
	for (i = 0; i < argc; i++)
	{
		printf("%d:%s\n", i, argv[i]);
	}

	return 0;
}