#include <stdio.h>

int main()
{ 
    int sign = 1;
    int n;
    printf("«Î ‰»În: ");
    scanf("%d", &n);
    double deno = 2.0, sum = 1.0, term;

    while (deno <= n)
    {    
        sign = -sign;
        term = sign / deno;
        sum = sum + term;
        deno = deno + 1;
    }
    printf("%f\n", sum);

    return 0;
}