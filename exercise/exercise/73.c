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
    int *a = (int*)malloc((size_t)n * sizeof(int));
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    int parity = 0;
    for (int i = 0; i < n; ++i){
        for (int j = i + 1; j < n; ++j){
            if (a[i] > a[j]) parity ^= 1;
        }
    }
    int m; scanf("%d", &m);
    for (int q = 0; q < m; ++q){
        int l,r; scanf("%d %d", &l, &r);
        ll len = (ll)r - (ll)l + 1;
        ll pairs = len * (len - 1) / 2;
        if ((pairs & 1LL) != 0) parity ^= 1;
        if (parity) printf("odd\n"); else printf("even\n");
    }
    free(a);
    return 0;
}