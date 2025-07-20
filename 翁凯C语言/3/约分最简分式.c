#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int gcd(int x, int y) // 求最大公约数
{
    int c;
    while (y > 0)
    {
        c = x % y;
        x = y;
        y = c;
    }
    return x;
}

int main()
{
    int m;
    int n;
    printf("请输入分式m/n:");
    scanf("%d/%d", &m, &n);

    int a, b;
    int num_gcd = gcd(m, n);
    a = m / num_gcd;
    b = n / num_gcd;
    printf("%d/%d的化简分式是%d/%d\n", m, n, a, b);

    return 0;
}