#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

// !结构中的结构
/*
	1.结构数组
	  struct date dates[!00];
	  struct date dates[] = {
		  {4,5,2005},
		  {2,4,2005}
		  }
	  * 最外面的大括号表示数组，里面的括号表示结构体
	  * 结构体本质是一种数据类型，数组是这种数据类型的变量
	2.结构中的结构
	  struct dateAndTime {
		  struct date sdate;
		  struct time stime;
	  };
	3.嵌套的结构
	  struct point {
		int x;
		int y;
	  };
	  struct rectangle {
		struct point pt1;
		struct point pt2;
	  };
	  如果有变量
	  struct rectangle r;
	  就可以有:
	  r.pt1.x、 rpt1.y, r.pt2.x 和 rpt2.y
	  如果有变量定义:
	  struct rectang1e r, *rp;
	  rp = &r;
	  那么下面的四种形式是等价的:
	  r.pt1.x
	  rp->pt1.x
	  (rpt1).x
	  (rp->pt1).x
	  但是没有rp->pt1->x(因为pt1不是指针)
*/

struct time
{
	int hour;
	int minute;
	int second;
};

struct time timeUpdate(struct time now);

int main(void)
{
	struct time testTime[5] = {
		{11, 59, 59},
		{12, 0, 0},
		{1, 29, 59},
		{23, 59, 59},
		{19, 12, 27}
	};

	for (int i = 0; i < 5; i++)
	{
		printf("Time is %.2i:%.2i:%.2i\n", 
			testTime[i].hour, testTime[i].minute, testTime[i].second);
		{
			testTime[i] = timeUpdate(testTime[i]);
		}
		printf(" ... one second later it's %.2i:%.2i:%.2i\n", 
			testTime[i].hour, testTime[i].minute, testTime[i].second);
	}

	return 0;
}

struct time timeUpdate(struct time now)
{
	++now.second;

	if (now.second == 60)
	{
		now.second = 0;
		++now.minute;

		if (now.minute == 60)
		{
			now.minute = 0;
			++now.hour;

			if (now.hour == 24)
			{
				now.hour = 0;
			}
		}
	}

	return now;
}