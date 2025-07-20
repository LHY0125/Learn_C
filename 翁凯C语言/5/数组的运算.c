#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

// !����ļ��ɳ�ʼ��
/*
    ���磺int a[10]={1,2,3,4,5,6,7,8,9,10};
    ֱ���ô����Ÿ������������Ԫ��ֵ�ĳ�ʼֵ
    ����Ҫ��������ĳ��ȣ���С�������������Զ�����
*/

// !���ɳ�ʼ���Ķ�λ
/*
    ��[n]�ڳ�ʼ�������и�����λ
    û�ж�λ�����ݽ���ǰ���λ�ú���
    ����λ�õ�ֵ���� Ҳ���Բ����������С���ñ�������
    �ر��ʺϳ�ʼ����ϡ�������
    ���磺int a[10]={[1]=1,4, [5]=6};��������Ϊ{0,1,4,0,0,6,0,0,0,0}
*/

// !����Ĵ�С
/*
    sizeof(a)��������a��ռ�ݵ����ݵĴ�С����λ���ֽ�
    sizeof(a)/sizeof(a[0])��������a�Ĵ�С
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

// !����
/*
    �ҳ�key������a�е�λ��
    @param key ҪѰ�ҵ�����
    @param a ҪѰ�ҵ�����
    @param length ����a�ĳ���
    @return ����ҵ�����������a�е�λ�ã�����Ҳ����򷵻�-1
*/

int search(int x, int a[], int len);

int main()
{
    int a[] = {2, 4, 6, 7, 1, 3, 5, 9, 11, 13, 23, 14, 32}; //{[1]=2,4, [5]=6};
    {
        int i;
        printf("%lu\n", sizeof(a));
        printf("%lu\n", sizeof(a[0]));                      // sizeof(a[0])��������ÿ��Ԫ�صĴ�С,���Ϊ4

        for (i = 0; i < sizeof(a) / sizeof(a[0]); i++)      // ����õ�������ĵ�Ԫ��������sizeof(a)/sizeof(a[0])������Ĵ�С
        {
            printf("%d\t", a[i]);
        }
        printf("\n");
    }

    int x;
    int location;
    printf("������Ҫ���ҵ����֣�");
    scanf("%d", &x);
    location = search(x,a,sizeof(a)/sizeof(a[0]));
    if (location!=-1)
    {
        printf("%d��%d��λ����\n", x, location);
    }
    else
    {
        printf("%d�������в�����\n", x);
    }

    return 0;
}

int search(int x, int a[], int len)
{
    int ret = -1;
    
    if (len==0)
    {
        return -1;
    }

    for (int i=0;i<len;i++)
    {
        if (x==a[i])
        {
            ret = i;
            break;
        }
    }
    return ret;
}