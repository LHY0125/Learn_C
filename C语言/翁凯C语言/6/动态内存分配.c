#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

// !��̬�ڴ����
/*
	1.��������
	  �����������ʱ,�ȸ����������Ȼ�������룬Ҫ��¼ÿ������
	  C99�����ñ��������鶨��Ĵ�С��C99֮ǰ��?
	  int *a = (int*)malloc(n*sizeof(int));
	2.malloc
	  #include <stdlib.h>
	  void* malloc(size_t size);
	  ��malloc����Ŀռ�Ĵ�С�����ֽ�Ϊ��λ��
	  ���صĽ����void*����Ҫ����ת��Ϊ�Լ���Ҫ������
	  (int*)malloc(n*sizeof(int))
	  float *pf;
	  pf=(float *)malloc(5*sizeof(float));
	3.calloc
	  #include <stdlib.h>
	  void* calloc(size_t n, size_t size);
	  ����n��Ԫ�أ�ÿ��Ԫ�صĴ�С��size�ֽ�
	  calloc�������Ŀռ��ʼ��Ϊ0
	  malloc�����ʼ��
	  int *pi;
	  pi=(int *)calloc(5,sizeof(int));
	4.free()
	  ����������Ŀռ仹����ϵͳ��
	  ������Ŀռ�,���ն�Ӧ��Ҫ��
	  ������ģ����綼��Ҫ����
	  ֻ�ܻ��������Ŀռ���׵�ַ
	  void free(void *p);
*/

int main(void)
{
	/* 1.malloc */
	int number;
	int *a;
	int i;
	printf("���������ݸ�����");
	scanf("%d", &number);

	// int a[number];
	// ����ɱ�����
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
	printf("%d100MB�Ŀռ�\n", cnt);

	/* 3. */
	/*void *p;
	int cnt = 0;*/
	cnt = 0;
	p = malloc(100 * 1024 * 1024);
	p++;
	free(p);

	return 0;
}