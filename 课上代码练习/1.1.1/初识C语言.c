#include <stdio.h>

int main()
{
    double a, b, c;
    scanf("%lf %lf", &a, &b);
    c = a / b;
    printf("%.0f/%.0f=%.2f\n", a, b, c);

    return 0;
