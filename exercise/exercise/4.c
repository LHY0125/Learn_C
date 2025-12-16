#include <stdio.h>

// 递归实现
long long f_recursive(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return n + f_recursive(n - 1);
}

// 数学公式实现（更高效）
long long f_formula(long long n)
{
    return n * (n + 1) / 2;
}

int main()
{
    int T;
    scanf("%d", &T);

    while (T--)
    {
        long long n;
        scanf("%lld", &n);

        // 由于n可能很大（<10^9），使用数学公式更安全
        printf("%lld\n", f_formula(n));
    }

    return 0;
}