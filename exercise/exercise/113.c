#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#endif

typedef unsigned long long ull;

int main(void)
{
#ifdef _WIN32
    system("chcp 65001 > nul");
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif
    unsigned long long n;
    if (scanf("%llu", &n) != 1)
        return 0;
    unsigned long long ans = 0ULL;
    for (unsigned long long factor = 1ULL; factor <= n; factor *= 10ULL)
    {
        unsigned long long high = n / (factor * 10ULL);
        unsigned long long low = n % factor;
        unsigned long long cur = (n / factor) % 10ULL;
        unsigned long long term = factor * (high * 45ULL + (cur * (cur - 1ULL)) / 2ULL) + cur * (low + 1ULL);
        ans += term;
    }
    printf("%llu\n", ans);
    return 0;
}