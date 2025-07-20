#include <stdio.h>

int main()
{
    double a, b,c;
    printf("输入你的体重(kg)和你的身高(cm)\n");
    scanf("%lf %lf",&a,&b);

    b /= 100;
    c=a/(b*b);

    if(c< 18)
    {
        printf("BMI是%.2f,你太轻了\n",c);
    }
    else if (c > 24)
    {
        printf("BMI是%.2f,你有点胖\n",c);
    }
    else if (18 <= c && c <= 24)
    {
        printf("BMI是%.2f,你的体重正常\n",c);
    }

    return 0;
}