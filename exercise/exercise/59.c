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
    ll sum = 0;
    for (int i = 0; i < n; ++i) sum += a[i];
    if ((sum & 1LL) != 0){ printf("0\n"); free(a); return 0; }
    ll target = sum / 2;
    ll pref = 0;
    long long ans = 0;
    for (int i = 0; i < n - 1; ++i){
        pref += a[i];
        if (pref == target) ++ans;
    }
    printf("%lld\n", ans);
    free(a);
    return 0;
}