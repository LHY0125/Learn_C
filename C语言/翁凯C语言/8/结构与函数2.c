#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

// !结构与函数
/*
	1.结构作为函数参数
	  int numberofDays(struct date d)
	  整个结构可以作为参数的值传入函数
	  这时候是在函数内新建一个结构变量，并复制调用者的结构的值
	  也可以返回一个结构
	  这与数组完全不同
	2.输入结构没
	  高接的方式可以一次scanf 如果我们打算写一个函数来读入结构
	  那么些一个函数，专门用来读入结构
	  但是读入的结构如何送回来呢?
	  记住C在函数调用时是传值的
	  所以函数中的p与main中的y是不同的
	  在函数读入了p的数值之后，没有任何东西回到main，所以y还是{0,0}
	  前的方案，把一个结构传入了函数，然后在函数中操作，但是没有返回回去
	  问题在于传入函数的是外面那个结构的克隆体，而不是指针
	  传入结构和传入数组是不同的
	  在这个输入函数中，完全可以创建一个临时的结构变量，然后把这个结构返回给调用者
	  void main()
	  {
		  struct point y = (0,0};
		  y= inputPoint();
		  output(y):
	  }
	  struct point inputPoint()
	  {
		  struct point temp;
		  scanf("%d", &temp.x);
		  scanf("%d",&temp.y);
		  return temp;
	  }
	3.
	  struct date
	  {
		  int month;
		  int day;
		  int year;
	  } myday;
	  struct date *p = &myday;
	  (*p).month = 12;
	  p->month = 12;
	4.
*/

struct point
{
	int x;
	int y;
};

struct point *getStruct(struct point *);
void output(struct point);
void print(const struct point *p);

int main(void)
{
	struct point y = {0, 0};
	getStruct(&y);
	output(y);
	output(*getStruct(&y));
	printf(getStruct(&y));

	return 0;
}

struct point *getStruct(struct point *p)
{
	scanf("%d", &p->x);
	scanf("%d", &p->y);
	printf("%d %d\n", p->x, p->y);
	return p;
}

void output(struct point p)
{
	printf("%d %d\n", p.x, p.y);
}

void print(const struct point *p)
{
	printf("%d %d\n", p->x, p->y);
}