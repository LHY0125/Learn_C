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
*/

struct data
{
	int month;
	int day;
	int year;
};

bool isLeap(struct data d);
int numberOfDays(struct data d);

int main(void)
{
	struct data today, tomorrow;

	printf("Enter today's date (mm dd yyyy): ");
	scanf("%i %i %i", &today.month, &today.day, &today.year);

	if (today.day != numberOfDays(today))
	{
		tomorrow.day = today.day + 1;
		tomorrow.month = today.month;
		tomorrow.year = today.year;
	}
	else if (today.month == 12)
	{
		tomorrow.day = 1;
		tomorrow.month = 1;
		tomorrow.year = today.year + 1;
	}
	else
	{
		tomorrow.day = 1;
		tomorrow.month = today.month + 1;
		tomorrow.year = today.year;
	}

	printf("Tomorrow's date is %i-%i-%i.\n", tomorrow.month, tomorrow.day, tomorrow.year);

	return 0;
}

bool isLeap(struct data d)
{
	bool leap = false;

	if ((d.year % 4 == 0 && d.year % 100 != 0) || d.year % 400 == 0)
	{
		leap = true;
	}

	return leap;
}

int numberOfDays(struct data d)
{
	int days;
	const int daysPerMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	if (d.month == 2 && isLeap(d))
	{
		days = 29;
	}
	else
	{
		days = daysPerMonth[d.month - 1];
	}

	return days;
}