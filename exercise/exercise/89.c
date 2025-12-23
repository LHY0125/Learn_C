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
    int n; ll MOD;
    if (scanf("%d %lld", &n, &MOD) != 2) return 0;
    int *f = (int*)malloc(((size_t)n + 3) * sizeof(int));
    long long *diff = (long long*)calloc(((size_t)n + 5), sizeof(long long));
    long long pref = 0;
    long long Dcur = 0;
    for (int x = 1; x <= n; ++x){
        Dcur += diff[x];
        Dcur %= MOD;
        if (Dcur < 0) Dcur += MOD;
        if (x == 1) f[x] = 1 % (int)MOD; else f[x] = (int)((pref + Dcur) % MOD);
        pref += f[x];
        pref %= MOD;
        int maxz = n / x;
        for (int z = 2; z <= maxz; ++z){
            int l = x * z;
            int r = l + z - 1;
            if (r > n) r = n;
            diff[l] += f[x];
            diff[r + 1] -= f[x];
        }
    }
    printf("%d\n", (int)(f[n] % (int)MOD));
    free(diff);
    free(f);
    return 0;
}