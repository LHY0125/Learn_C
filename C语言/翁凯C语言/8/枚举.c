#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

// !枚举
/*
	1.枚举
	  枚举是一种用户定义的数据类型，它用关键字enum 以如下语法来声明:
	  enum 枚举类型名字{名字0，....名字;
	  枚举类型名字通常并不真的使用，要用的是在大括号里的名字，因为它们就是就是常量符号，它们的类型是int，值则依次从0 到n。如：
	  enum colors { red, yellow, green};
	  就创建了三个常量，red的值是0，yellow是1，而green是2。
	  当需要一些可以排列起来的常量值时，定义枚举的意义就是给了这些常量值名字。
	  这样需要遍历所有的枚举量或者需要建立一个用枚举量做下标的数组的时候就很方便了
	2.枚举量
	  声明枚举量的时候可以指定值
	  enum COLOR ( RED=1, YELLOW, GREEN = 5);	// !YELLOW的值是2，GREEN的值是5
	3.枚举只是int
	  即使给枚举类型的变量赋不存在的整数值也没有任何warning或error
	4.枚举
	  虽然枚举类型可以当作类型使用，但是实际上很(bu)少(hao)用
	  如果有意义上排比的名字，用枚举比const int方便
	  枚举比宏（macro）好，因为枚举有int类型
*/

enum COLOR
{
	RED,
	YELLOW,
	GREEN
};

int main(void)
{
	int color = -1;
	char *colorName = NULL;

	printf("输入你喜欢的颜色的代码：");
	scanf("%d", &color);
	switch (color)
	{
		case RED: colorName = "red"; break;
		case YELLOW: colorName = "yellow"; break;
		case GREEN: colorName = "green"; break;
		default: colorName= "unknown"; break;
	}
	printf("你喜欢的颜色是sn", colorName);

	return 0;
}