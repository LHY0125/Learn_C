#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

// !指针数组
/*
	* 指针数组是一个数组，其每个元素都是指针变量（存储内存地址）。它的本质是 “存储指针的数组”，核心作用是批量管理多个指针，适用于需要集中操作多个地址的场景（如字符串集合、动态内存块管理等）
	1.类型* 数组名[数组长度];  // !类型* 表示数组元素是该类型的指针
	  在 C 语言中，字符串本质是char*指针（指向字符数组的首地址）。因此，指针数组是存储多个字符串的高效方式（仅存储字符串的地址，而非复制整个字符串内容）
	2.本质是数组，元素是指针。
	  存储多个独立指针（如多个变量地址）。
	3.指针数组通过集中存储多个指针，实现了对多数据的高效管理，尤其在处理字符串集合、动态内存块或需要批量操作指针的场景中，能显著提升内存 利用率和代码灵活性。
	4.
      int a = 10, b = 20, c = 30;
	  int *ptr_arr[3]; // 声明一个包含3个int指针的数组

  	  ptr_arr[0] = &a; // 存储a的地址
	  ptr_arr[1] = &b; // 存储b的地址
	  ptr_arr[2] = &c; // 存储c的地址
*/

int main()
{
	// 基本类型指针数组
	int num1 = 5, num2 = 10;
	int *num_ptrs[2] = {&num1, &num2};
	printf("Numbers: ");
	for (int i = 0; i < 2; i++)
	{
		printf("%d ", *num_ptrs[i]); // 输出：5 10
	}
	printf("\n");

	// 字符串指针数组
	char *fruits[] = {"Apple", "Banana", "Cherry"};
	printf("Fruits: ");
	for (int i = 0; i < 3; i++)
	{
		printf("%s ", fruits[i]); // 输出：Apple Banana Cherry
	}
	printf("\n");

	// 二维数组行指针数组
	int table[3][2] = {{1, 2}, {3, 4}, {5, 6}};
	int *row_ptrs[3] = {table[0], table[1], table[2]};
	printf("Table:\n");
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			printf("%d ", row_ptrs[i][j]); // 输出每行元素
		}
		printf("\n");
	}
	// 输出：
	// 1 2
	// 3 4
	// 5 6

	return 0;
}