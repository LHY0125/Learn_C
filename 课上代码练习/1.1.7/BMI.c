#include <stdio.h>

int main()
{
    double a, b,c;
    printf("�����������(kg)��������(cm)\n");
    scanf("%lf %lf",&a,&b);

    b /= 100;
    c=a/(b*b);

    if(c< 18)
    {
        printf("BMI��%.2f,��̫����\n",c);
    }
    else if (c > 24)
    {
        printf("BMI��%.2f,���е���\n",c);
    }
    else if (18 <= c && c <= 24)
    {
        printf("BMI��%.2f,�����������\n",c);
    }

    return 0;
}