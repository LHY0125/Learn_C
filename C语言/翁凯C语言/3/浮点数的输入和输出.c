#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
    double ff = 1234.56789;
    printf("��ѧ�������������ff = %e\n", ff);  //%e�ǿ�ѧ�����������
    printf("��ѧ�������������ff = %E\n", ff);  //%E�ǿ�ѧ������������������Ǵ�д�ģ�
    printf("��ͨ��ʽ�������ff = %f\n", ff);   //%f����ͨ��ʽ�����

    double fff = 1E-10;
    printf("��ѧ�������������ff = %e\n", fff); //%e�ǿ�ѧ�����������
    printf("��ѧ�������������ff = %E\n", fff); //%E�ǿ�ѧ������������������Ǵ�д�ģ�
    printf("��ͨ��ʽ�������ff = %f\n", fff);   //%f����ͨ��ʽ�����
    printf("��ͨ��ʽ�������ff = %.16f\n", fff);   //%.16f����ͨ��ʽ�ı���16λС�������

    return 0;
}