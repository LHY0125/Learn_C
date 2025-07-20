#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
    // !浮点数的范围
    printf("%f\n", 12.0/0.0);   //12/0是没有定义的，即只有浮点数有无穷大和无穷小
    printf("%f\n", -12.0/0.0);
    printf("%f\n", 0.0/0.0);
    //inf是无穷大，nan是无穷小

    // !浮点数的精度
    float a, b, c;
    a = 1.345f;     //带小数点的默认是double类型，所以要加f来指定是float类型
    b = 1.123f;
    c = a + b;
    if (c== 2.468)
    {
        printf("c = 2.468\n");
    }
    else
    {
        printf("不相等！ c=%.10f,或%f\n", c, c);
    }

    return 0;
}