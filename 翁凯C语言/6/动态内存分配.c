#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

// !动态内存分配
/*
	1.输入数据
	  如果输入数据时,先告诉你个数，然后再输入，要记录每个数据
	  C99可以用变量做数组定义的大小，C99之前呢?
	  int *a = (int*)malloc(n*sizeof(int));
	2.malloc
	  #include <stdlib.h>
	  void* malloc(size_t size);
	  向malloc申请的空间的大小是以字节为单位的
	  返回的结果是void*，需要类型转换为自己需要的类型
	  (int*)malloc(n*sizeof(int))
	  float *pf;
	  pf=(float *)malloc(5*sizeof(float));
	3.calloc
	  #include <stdlib.h>
	  void* calloc(size_t n, size_t size);
	  分配n个元素，每个元素的大小是size字节
	  calloc会把申请的空间初始化为0
	  malloc不会初始化
	  int *pi;
	  pi=(int *)calloc(5,sizeof(int));
	4.free()
	  把申请得来的空间还给“系统”
	  申请过的空间,最终都应该要还
	  混出来的，迟早都是要还的
	  只能还申请来的空间的首地址
	  void free(void *p);
*/

int main(void)
{
	/* 1.malloc */
	int number;
	int *a;
	int i;
	printf("请输入数据个数：");
	scanf("%d", &number);

	// int a[number];
	// 定义可变数组
	a = (int *)malloc(number * sizeof(int));
	for (i = 0; i < number; i++)
	{
		scanf("%d", &a[i]);
	}

	for (i = number - 1; i >= 0; i--)
	{
		printf("%d ", a[i]);
	}

	free(a);

	/* 2. */
	void *p;
	int cnt = 0;
	while (p = malloc(100 * 1024 * 1024))
	{
		cnt++;
		free(p);
	}
	printf("%d100MB的空间\n", cnt);

	/* 3. */
	/*void *p;
	int cnt = 0;*/
	cnt = 0;
	p = malloc(100 * 1024 * 1024);
	p++;
	free(p);

	return 0;
}