#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

// !ö��
/*
	1.ö��
	  ö����һ���û�������������ͣ����ùؼ���enum �������﷨������:
	  enum ö����������{����0��....����;
	  ö����������ͨ���������ʹ�ã�Ҫ�õ����ڴ�����������֣���Ϊ���Ǿ��Ǿ��ǳ������ţ����ǵ�������int��ֵ�����δ�0 ��n���磺
	  enum colors { red, yellow, green};
	  �ʹ���������������red��ֵ��0��yellow��1����green��2��
	  ����ҪһЩ�������������ĳ���ֵʱ������ö�ٵ�������Ǹ�����Щ����ֵ���֡�
	  ������Ҫ�������е�ö����������Ҫ����һ����ö�������±�������ʱ��ͺܷ�����
	2.ö����
	  ����ö������ʱ�����ָ��ֵ
	  enum COLOR ( RED=1, YELLOW, GREEN = 5);	// !YELLOW��ֵ��2��GREEN��ֵ��5
	3.ö��ֻ��int
	  ��ʹ��ö�����͵ı����������ڵ�����ֵҲû���κ�warning��error
	4.ö��
	  ��Ȼö�����Ϳ��Ե�������ʹ�ã�����ʵ���Ϻ�(bu)��(hao)��
	  ������������űȵ����֣���ö�ٱ�const int����
	  ö�ٱȺ꣨macro���ã���Ϊö����int����
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

	printf("������ϲ������ɫ�Ĵ��룺");
	scanf("%d", &color);
	switch (color)
	{
		case RED: colorName = "red"; break;
		case YELLOW: colorName = "yellow"; break;
		case GREEN: colorName = "green"; break;
		default: colorName= "unknown"; break;
	}
	printf("��ϲ������ɫ��sn", colorName);

	return 0;
}