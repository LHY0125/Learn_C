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
    int n,m;
    if (scanf("%d %d", &n, &m) != 2) return 0;
    int **a = (int**)malloc((size_t)n * sizeof(int*));
    for (int i = 0; i < n; ++i){
        a[i] = (int*)malloc((size_t)m * sizeof(int));
        for (int j = 0; j < m; ++j) scanf("%d", &a[i][j]);
    }
    ll ans = 0;
    ll *col = (ll*)malloc((size_t)m * sizeof(ll));
    ll *pref = (ll*)malloc(((size_t)m + 1) * sizeof(ll));
    int *st = (int*)malloc(((size_t)m + 1) * sizeof(int));
    for (int top = 0; top < n; ++top){
        for (int c = 0; c < m; ++c) col[c] = 0;
        for (int bottom = top; bottom < n; ++bottom){
            for (int c = 0; c < m; ++c) col[c] += a[bottom][c];
            pref[0] = 0;
            for (int i = 1; i <= m; ++i) pref[i] = pref[i-1] + col[i-1];
            int sz = 0;
            for (int i = 0; i <= m; ++i){
                if (sz == 0 || pref[i] < pref[st[sz-1]]) st[sz++] = i;
            }
            int k = sz - 1;
            for (int j = m; j >= 0 && k >= 0; --j){
                while (k >= 0 && pref[j] > pref[st[k]]){
                    ll width = (ll)j - (ll)st[k];
                    ll height = (ll)bottom - (ll)top + 1;
                    ll area = width * height;
                    if (area > ans) ans = area;
                    --k;
                }
            }
        }
    }
    printf("%lld\n", ans);
    free(st);
    free(pref);
    free(col);
    for (int i = 0; i < n; ++i) free(a[i]);
    free(a);
    return 0;
}