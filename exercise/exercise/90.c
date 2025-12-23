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
    int m;
    if (scanf("%d", &m) != 1) return 0;
    while (m--){
        int n; if (scanf("%d", &n) != 1) return 0;
        int *h = (int*)malloc((size_t)n * sizeof(int));
        for (int i = 0; i < n; ++i) scanf("%d", &h[i]);
        int *len = (int*)malloc((size_t)n * sizeof(int));
        ll *cnt = (ll*)malloc((size_t)n * sizeof(ll));
        int best = 0; ll ways = 0;
        for (int i = 0; i < n; ++i){ len[i] = 1; cnt[i] = 1; }
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < i; ++j){
                if (h[j] <= h[i]){
                    if (len[j] + 1 > len[i]){ len[i] = len[j] + 1; cnt[i] = cnt[j]; }
                    else if (len[j] + 1 == len[i]){ cnt[i] += cnt[j]; }
                }
            }
            if (len[i] > best){ best = len[i]; ways = cnt[i]; }
            else if (len[i] == best){ ways += cnt[i]; }
        }
        printf("%d %lld\n", best, ways);
        free(cnt); free(len); free(h);
    }
    return 0;
}