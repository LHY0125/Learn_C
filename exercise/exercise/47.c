#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#endif

int main(void)
{
#ifdef _WIN32
    system("chcp 65001 > nul");
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif
    int T;
    if (scanf("%d", &T) != 1) return 0;
    while (T--)
    {
        long long n;
        if (scanf("%lld", &n) != 1) return 0;
        long long ans;
        if ((n & 1LL) == 0)
        {
            if (n == 2) ans = -1;
            else ans = n / 4;
        }
        else
        {
            if (n < 9 || n == 11) ans = -1;
            else ans = (n - 9) / 4 + 1;
        }
        printf("%lld\n", ans);
    }
    return 0;
}