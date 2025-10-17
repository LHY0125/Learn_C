#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

// !数组的集成初始化
/*
    例如：int a[10]={1,2,3,4,5,6,7,8,9,10};
    直接用大括号给出数组的所有元素值的初始值
    不需要给出数组的长度（大小），编译器会自动计算
*/

// !集成初始化的定位
/*
    用[n]在初始化数据中给出定位
    没有定位的数据接在前面的位置后面
    其他位置的值补零 也可以不给出数组大小，让编译器算
    特别适合初始数据稀疏的数组
    例如：int a[10]={[1]=1,4, [5]=6};他的数组为{0,1,4,0,0,6,0,0,0,0}
*/

// !数组的大小
/*
    sizeof(a)给出数组a所占据的内容的大小，单位是字节
    sizeof(a)/sizeof(a[0])给出数组a的大小
*/

// !数组的赋值
/*
    数组赋值有两种方式
    1.用赋值号直接赋值
    2.用循环赋值
    例如：
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    int b[10];
    for(int i=0;i<10;i++)
    {
        b[i]=a[i];
    }
    数组不能用来赋另外一个数组的值
*/

// !例题
/*
    找出key在数组a中的位置
    @param key 要寻找的数字
    @param a 要寻找的数组
    @param length 数组a的长度
    @return 如果找到，返回其在a中的位置；如果找不到则返回-1
*/

int search(int x, int a[], int len);

int main()
{
    int a[] = {2, 4, 6, 7, 1, 3, 5, 9, 11, 13, 23, 14, 32}; //{[1]=2,4, [5]=6};
    {
        int i;
        printf("%lu\n", sizeof(a));
        printf("%lu\n", sizeof(a[0]));                      // sizeof(a[0])是数组中每个元素的大小,结果为4

        for (i = 0; i < sizeof(a) / sizeof(a[0]); i++)      // 相除得到了数组的单元个数，即sizeof(a)/sizeof(a[0])是数组的大小
        {
            printf("%d\t", a[i]);
        }
        printf("\n");
    }

    int x;
    int location;
    printf("请输入要查找的数字：");
    scanf("%d", &x);
    location = search(x,a,sizeof(a)/sizeof(a[0]));
    if (location!=-1)
    {
        printf("%d在%d个位置上\n", x, location);
    }
    else
    {
        printf("%d在数组中不存在\n", x);
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