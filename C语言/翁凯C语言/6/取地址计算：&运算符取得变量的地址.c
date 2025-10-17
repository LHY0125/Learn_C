#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

// !运算符
/*
    scanf("%d", &i);里的&
    获得变量的地址,它的操作数必须是变量
    int i; printf("%x"，&i);
    地址的大小是否与int相同取决于编译器
    int i; printf("%p", &i);
*/

int main()
{
    // 变量的地址
    int a = 10;
    int b = 20;
    printf("&a = %p\n", &a);
    printf("&b = %p\n", &b);

    // &操作符的sizeof
    int x;
    printf("sizeof(&x) = %zu\n", sizeof(&x)); // 32位系统输出4，64位系统输出8

    // 数组的地址
    int arr[3] = {1, 2, 3};
    printf("arr地址  = %p\n", (void *)arr); // 0x7ffee3a45680
    printf("&arr[0] = %p\n", &arr[0]);      // 0x7ffee3a45680
    printf("&arr    = %p\n", &arr);         // 0x7ffee3a45680（值相同但类型不同）

    // 数组单元的地址
    printf("&arr[0] = %p\n", &arr[0]); // 0x7ffee3a45680
    printf("&arr[1] = %p\n", &arr[1]); // 0x7ffee3a45684（相差4字节）
    printf("&arr[2] = %p\n", &arr[2]); // 0x7ffee3a45688（继续相差4字节）

    return 0;
}