#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

// !�ж��ܱ���֪����Ϊ������������������������
/*  
    ������n���ڵ�������
    1.��x=2
    2.��2x��3x��4xֱ��ax<n�������Ϊ������
    3.��xΪ��һ��û�б����Ϊ�������������ظ�����2��ֱ�����е������Ѿ��������
*/

// !����ĸ�ֵ
/*
    ���鸳ֵ�����ַ�ʽ
    1.�ø�ֵ��ֱ�Ӹ�ֵ
    2.��ѭ����ֵ
    ���磺
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    int b[10];
    for(int i=0;i<10;i++)
    {
        b[i]=a[i];
    }
    ���鲻������������һ�������ֵ
*/

int main()
{
    int minnum,maxnum;
    printf("������һ����(��Ϊ��С����������)��");
    scanf(" %d %d", &minnum, &maxnum);

    int isprime[maxnum];
    int i, x;

    if (maxnum<=0)
    {
        printf("�������");
        return 0;
    }

    for (i = 0; i < maxnum; i++)// ��isprime[i]=1������ѭ����ֵ��Ĭ�����е����������������Ϊ1
    {
        isprime[i] = 1;
    }

    for (x = 2; x < maxnum; x++)
    {
        if (isprime[x]==1)      // isprime[x]�ж��Ƿ�Ϊ����
        {
            /* x�ı����������� */
            for (i = 2; i*x < maxnum; i++)
            {
                isprime[i*x] = 0;
            }
        }
    }

    for (x = 2; x < minnum;x++) // ����minnumС�������Ϊ��������������ӡ
    {
        isprime[x] = 0;
    }

    for (x = 2; x < maxnum; x++)// ��ӡ����
    {
        if (isprime[x] == 1)
        {
            printf("%d������\n", x);
        }
    }

    return 0;
}