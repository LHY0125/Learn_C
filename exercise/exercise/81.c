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
    ll sum = 0, mx = 0;
    for (int i = 0; i < n; ++i){
        ll x; scanf("%lld", &x);
        sum += x;
        if (x > mx) mx = x;
    }
    ll g = (sum + (ll)(n - 2)) / (ll)(n - 1);
    if (g < mx) g = mx;
    printf("%lld\n", g);
    return 0;
}