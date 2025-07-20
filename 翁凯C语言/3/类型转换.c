#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
    //  !自类型转换
    /*  对于printf函数，任何小于int的整型值都会自动转换成int类型
        float会自动转换成double类型
        但是scanf函数不会自动转换类型，要输入short类型，必须输入%hd
    */

    //  !强制类型转换
    /*  要将一个量强制转换成另一个类型，需要使用强制类型转换运算符（通常是较小的类型）
        需要：(type)expression,大的变量赋值给小的变量时，旧的值不会改变
        例如：(int)10.2
              (short)32
        强制类型转换的优先级比四则运算高
    */
    printf("%d\n", (short)32768);   //结果为-32768


    return 0;
}
    
