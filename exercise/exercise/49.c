#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#ifdef _WIN32
#include <windows.h>
#endif

typedef struct { double l, r; } Seg;

static int cmp_seg(const void *a, const void *b) {
    const Seg *x = (const Seg*)a, *y = (const Seg*)b;
    if (x->r < y->r) return -1;
    if (x->r > y->r) return 1;
    if (x->l < y->l) return -1;
    if (x->l > y->l) return 1;
    return 0;
}

int main(void) {
#ifdef _WIN32
    system("chcp 65001 > nul");
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif
    int n, r;
    while (scanf("%d %d", &n, &r) == 2) {
        if (n == 0 && r == 0) break;
        Seg *a = (Seg*)malloc((size_t)n * sizeof(Seg));
        int ok = r >= 0;
        for (int i = 0; i < n; ++i) {
            int x, y;
            scanf("%d %d", &x, &y);
            double yy = (double)y;
            double rr = (double)r;
            if (!ok || yy > rr || yy < -rr) { ok = 0; continue; }
            double t = rr*rr - yy*yy;
            if (t < 0) { ok = 0; continue; }
            double dx = sqrt(t);
            a[i].l = (double)x - dx;
            a[i].r = (double)x + dx;
        }
        if (!ok) {
            printf("-1\n");
            free(a);
            continue;
        }
        qsort(a, (size_t)n, sizeof(Seg), cmp_seg);
        const double eps = 1e-12;
        double p = -1e300;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i].l > p + eps) { ++ans; p = a[i].r; }
        }
        printf("%d\n", ans);
        free(a);
    }
    return 0;
}