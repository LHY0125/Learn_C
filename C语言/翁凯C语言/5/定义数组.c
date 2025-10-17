#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

// !定义数组
/*
    <类型> 变量名字[元素数量]，例如int number[100],double number[100]
    元素数量必须是整数
    例如：a[10]
    每个单元都是一个变量，每个变量都是一个int类型的变量，可以出现在赋值语句的左边或右边
    如a[2] = a[1]+6
    
*/

void f();

int main()
{
    f();

    return 0;
}

void f()
{
    int a[10];
    a[10] = 0;  // !数组越界,因为数组大小为10，从a[0]到a[9]，所以a[10]是越界的
}