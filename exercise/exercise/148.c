#include <stdio.h>
#include <stdlib.h>

typedef struct { long long x, y; } P;

static int cmpx(const void *a, const void *b){ const P *pa=a, *pb=b; if (pa->x<pb->x) return -1; if (pa->x>pb->x) return 1; return 0; }

static int ok(P *p, int n, long long W, long long D)
{
    int *qmax = (int *)malloc((size_t)n * sizeof(int));
    int *qmin = (int *)malloc((size_t)n * sizeof(int));
    int hmax=0,tmax=0,hmin=0,tmin=0;
    int l=0;
    for (int r=0;r<n;++r)
    {
        while (tmax>hmax && p[qmax[tmax-1]].y<=p[r].y) --tmax;
        qmax[tmax++]=r;
        while (tmin>hmin && p[qmin[tmin-1]].y>=p[r].y) --tmin;
        qmin[tmin++]=r;
        while (p[r].x - p[l].x > W)
        {
            if (hmax<tmax && qmax[hmax]==l) ++hmax;
            if (hmin<tmin && qmin[hmin]==l) ++hmin;
            ++l;
        }
        if (tmax>hmax && tmin>hmin)
        {
            long long mx = p[qmax[hmax]].y;
            long long mn = p[qmin[hmin]].y;
            if (mx - mn >= D) { free(qmax); free(qmin); return 1; }
        }
    }
    free(qmax); free(qmin); return 0;
}

int main(void)
{
    int N; long long D;
    if (scanf("%d %lld", &N, &D) != 2) return 0;
    P *p = (P *)malloc((size_t)N * sizeof(P));
    for (int i=0;i<N;++i) scanf("%lld %lld", &p[i].x, &p[i].y);
    qsort(p, N, sizeof(P), cmpx);
    long long L=0, R=0;
    if (N>0) R = p[N-1].x - p[0].x;
    long long ans=-1;
    long long lo=L, hi=R;
    while (lo<=hi)
    {
        long long mid = lo + ((hi - lo) >> 1);
        if (ok(p, N, mid, D)) { ans = mid; hi = mid - 1; }
        else lo = mid + 1;
    }
    printf("%lld\n", ans);
    free(p);
    return 0;
}