#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

// !�ṹ����
/*
	1.�ں�����/��
	  �ͱ��ر���һ�����ں����ڲ������Ľṹ����ֻ���ں����ڲ�ʹ��
	  ����ͨ���ں����ⲿ�����ṹ���ͣ������Ϳ��Ա����������ʹ����
	2.�����ṹ����ʽ
	  struct point{
			int x;
			int y;
	  };
	  struct point pl,p2;
	  pl��p2����point������x��y��ֵ

	  struct{
		  int x;
		  int y;
	  }pl,p2;
	  p1��p2����һ�������ṹ,������x��y

	  struct point{
		  int x;
		  int y;
	  } pl,p2;
	  pl��p2����point������x��y��ֵt
	  *���ڵ�һ�͵�������ʽ���������˽ṹpoint�����ǵڶ�����ʽû������point,ֻ�Ƕ�������������
	3.�ṹ��Ա
	  �ṹ�������е���
	  �����ÿ���������±�������Ա
	  a[0]= 10;
	  �ṹ��.����������ַ������Ա
	  today.day
	  student.firstName
	  pl.x pl.y
	4.�ṹ����
	  Ҫ���������ṹ��ֱ���ýṹ����������
	  ���������ṹ����������ֵ��ȡ��ַ��Ҳ���Դ��ݸ���������
	  pl = (struct point)(5, 10};
	  �൱��pl.x=5;pl.y= I0;
	  pl=p2;
	  �൱��pl.x= p2.x;pl.y= p2.y;
	5.�ṹָ��
	  �����鲻ͬ���ṹ���������ֲ����ǽṹ�����ĵ�ַ������ʹ��&�����
	  struct date *pDate = &today;
*/

struct data
{
	int month;
	int day;
	int year;
};

int main(void)
{
	struct data today;
	today = (struct data){07,31,2014};

	struct data day;
	day = today;
	day.year = 2015;

	printf("Today's date is %i-%i-%i.\n", today.year, today.month, today.day);
	printf("This month is %i-%i-%i.\n", day.year, day.month, day.day);

	return 0;
}