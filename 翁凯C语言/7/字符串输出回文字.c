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

int main()
{
	char str[100];
	printf("请输入一个字符串：");
	scanf("%s", str);

	int len=strlen(str);	// !strlen()函数返回字符串的长度，不包括'\0'字符
	int is_huiwenzi = 1;

	for (int i = 0; i < len / 2;i++)
	{
		if (str[i]!=str[len-i-1])
		{
			is_huiwenzi = 0;
		}
	}
	if (is_huiwenzi)
	{
		printf("是回文字\n");
	}
	else
	{
		printf("不是回文字\n");
	}

	return 0;
}