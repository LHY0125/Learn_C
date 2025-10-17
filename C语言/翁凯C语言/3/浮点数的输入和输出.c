#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
    double ff = 1234.56789;
    printf("科学计数法的输出：ff = %e\n", ff);  //%e是科学计数法的输出
    printf("科学计数法的输出：ff = %E\n", ff);  //%E是科学计数法的输出（底数是大写的）
    printf("普通格式的输出：ff = %f\n", ff);   //%f是普通格式的输出

    double fff = 1E-10;
    printf("科学计数法的输出：ff = %e\n", fff); //%e是科学计数法的输出
    printf("科学计数法的输出：ff = %E\n", fff); //%E是科学计数法的输出（底数是大写的）
    printf("普通格式的输出：ff = %f\n", fff);   //%f是普通格式的输出
    printf("普通格式的输出：ff = %.16f\n", fff);   //%.16f是普通格式的保留16位小数的输出

    return 0;
}