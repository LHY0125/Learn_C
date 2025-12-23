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
    int n; if (scanf("%d", &n) != 1) return 0;
    ll *a = (ll*)malloc((size_t)n * sizeof(ll));
    for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);
    ll best = a[0];
    ll cur = a[0];
    for (int i = 1; i < n; ++i){
        if (cur < 0) cur = a[i]; else cur += a[i];
        if (cur > best) best = cur;
    }
    printf("%lld\n", best);
    free(a);
    return 0;
}