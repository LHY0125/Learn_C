#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#endif

typedef long long ll;

int main(void){
#ifdef _WIN32
    system("chcp 65001 > nul");
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif
    int n;
    if (scanf("%d", &n) != 1) return 0;
    ll *a = (ll*)malloc((size_t)n * sizeof(ll));
    for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);
    ll sumabs = 0;
    for (int i = 0; i + 1 < n; ++i){
        ll d = a[i+1] - a[i];
        if (d < 0) d = -d;
        sumabs += d;
    }
    ll enddiff = a[n-1] - a[0];
    if (enddiff < 0) enddiff = -enddiff;
    ll ans = (sumabs + enddiff) / 2;
    printf("%lld\n", ans);
    free(a);
    return 0;
}