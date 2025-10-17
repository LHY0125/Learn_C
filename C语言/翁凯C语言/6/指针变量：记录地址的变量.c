#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

// !指针变量
/*
    变量的值是内存的地址
    普通变量的值是实际的值
    指针变量的值是具有实际值的变量的地址
*/

// !访问那个地址上的变量*
/*
    *p: p指向的变量的值*是一个单目运算符，用来访问指针的值所表示的地址上的变量
    可以做右值也可以做左值
    int k= *p;
    *p=k+1;
*/

void f(int *p);
void f2(int k);

int main(void)
{
    int i = 6;
    printf("i = %d\n", i);
    printf("&i = %p\n", &i);    // %p打印i地址
    f(&i);
    f2(i);

    return 0;
}

void f(int *p)
{
    printf("p = %p\n", p);      // %p打印p地址
    printf("*p = %d\n", *p);    // %d打印p指向的变量的值
    *p = 26;                    // 修改p指向的变量的值
}

void f2(int k)
{
    printf("k = %d\n", k);
}
