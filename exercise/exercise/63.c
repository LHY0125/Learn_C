#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#endif

typedef long long ll;

int main(void)
{
#ifdef _WIN32
    system("chcp 65001 > nul");
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif

    ll A, B, C, D;
    if (scanf("%lld %lld %lld %lld", &A, &B, &C, &D) != 4)
        return 0;
    ll lenX = B - A + 1;
    ll ans = 0;
    for (ll z = C; z <= D; ++z)
    {
        ll L = z - C;
        ll R = z - B;
        ll s1l = L, s1r = R < A - 1 ? R : A - 1;
        if (s1l <= s1r)
            ans += (s1r - s1l + 1) * lenX;
        ll s2l = L > A ? L : A;
        ll s2r = R < B - 1 ? R : B - 1;
        if (s2l <= s2r)
        {
            ll cnt = s2r - s2l + 1;
            ll sumk = (s2l + s2r) * cnt / 2;
            ans += cnt * B - sumk;
        }
    }
    printf("%lld\n", ans);
    return 0;
}