#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#endif

typedef long long ll;

static ll gcdll(ll a, ll b){ while (b){ ll t = a % b; a = b; b = t; } return a; }

static int ok(ll V, ll cnt1, ll cnt2, ll x, ll y){
    ll mx = V / x;
    ll my = V / y;
    ll l = x / gcdll(x, y) * y;
    ll mxy = V / l;
    ll a_only = my - mxy;
    ll b_only = mx - mxy;
    ll both = V - mx - my + mxy;
    ll needA = cnt1 - a_only; if (needA < 0) needA = 0;
    ll needB = cnt2 - b_only; if (needB < 0) needB = 0;
    return needA + needB <= both;
}

int main(void){
#ifdef _WIN32
    system("chcp 65001 > nul");
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif
    ll cnt1, cnt2, x, y;
    if (scanf("%lld %lld %lld %lld", &cnt1, &cnt2, &x, &y) != 4) return 0;
    ll lo = 1, hi = 1;
    while (!ok(hi, cnt1, cnt2, x, y)){
        hi <<= 1;
        if (hi <= 0) { hi = (ll)4e18; break; }
    }
    ll ans = hi;
    while (lo <= hi){
        ll mid = lo + ((hi - lo) >> 1);
        if (ok(mid, cnt1, cnt2, x, y)){ ans = mid; hi = mid - 1; }
        else lo = mid + 1;
    }
    printf("%lld\n", ans);
    return 0;
}