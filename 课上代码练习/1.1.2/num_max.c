#include <stdio.h>

int max(int a, int b);

int main()
{
    int a, b,c;
    scanf("%d %d", &a, &b);

    c = max(a, b);

    printf("%d和%d的最大数是%d", a, b, c);

    return 0;
}

int max(int a, int b)
{
    int c = a;
    
    if (a<b)
    {
        c = b;
    }
    return c;
}