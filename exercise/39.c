#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;
    int *a = (int*)malloc((size_t)(n + 1) * sizeof(int));
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    int *cnt = (int*)calloc((size_t)(m + 1), sizeof(int));
    int covered = 0;
    int l = 1;
    int best_l = 1, best_r = n;
    int best_len = n;
    for (int r = 1; r <= n; ++r) {
        int c = a[r];
        if (cnt[c] == 0) ++covered;
        ++cnt[c];
        if (covered == m) {
            while (cnt[a[l]] > 1) { --cnt[a[l]]; ++l; }
            int len = r - l + 1;
            if (len < best_len || (len == best_len && l < best_l)) {
                best_len = len; best_l = l; best_r = r;
            }
        }
    }
    printf("%d %d\n", best_l, best_r);
    free(cnt);
    free(a);
    return 0;
}