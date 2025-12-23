#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#endif

typedef long long ll;

int main(void) {
#ifdef _WIN32
    system("chcp 65001 > nul");
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int *p = (int*)malloc((size_t)n * sizeof(int));
    ll *d = (ll*)malloc((size_t)n * sizeof(ll));
    for (int i = 0; i < n; ++i) scanf("%d", &p[i]);
    for (int i = 0; i < n; ++i) scanf("%lld", &d[i]);
    ll ans = p[n - 1];
    ll s = 0;
    int in = 0;
    int start = 0;
    for (int i = 0; i < n; ++i) {
        s += d[i];
        if (!in && s < 0) { in = 1; start = p[i]; }
        if (in && s >= 0) { ans += 2LL * (p[i] - start); in = 0; }
    }
    printf("%lld\n", ans);
    free(d);
    free(p);
    return 0;
}