#include <stdio.h>
#include <stdlib.h>

typedef long long LL;

static LL *low, *up; // max-heap(low), min-heap(up)
static int szLow, szUp;
static LL *qarr; static int qh, qt;

static LL *delKeys; static unsigned char *delUsed; static int DEL_CAP;

static unsigned int h64(LL x){ unsigned long long u = (unsigned long long)x; u ^= u >> 33; u *= 0xff51afd7ed558ccdULL; u ^= u >> 33; u *= 0xc4ceb9fe1a85aa39ULL; u ^= u >> 33; return (unsigned int)u; }

static void delInit(void){ DEL_CAP = 1<<20; delKeys = (LL*)malloc((size_t)DEL_CAP * sizeof(LL)); delUsed = (unsigned char*)malloc((size_t)DEL_CAP); for (int i=0;i<DEL_CAP;++i) delUsed[i]=0; }
static void delClear(void){ for (int i=0;i<DEL_CAP;++i) delUsed[i]=0; }
static void delMark(LL x){ unsigned int m = DEL_CAP-1; unsigned int h = h64(x) & m; while (delUsed[h] && delKeys[h]!=x){ h=(h+1)&m; } delKeys[h]=x; delUsed[h]=1; }
static int delHas(LL x){ unsigned int m = DEL_CAP-1; unsigned int h = h64(x) & m; while (delUsed[h]){ if (delKeys[h]==x) return 1; h=(h+1)&m; } return 0; }

static void maxPush(LL *a, int *n, LL v){ int i=*n; a[i]=v; (*n)++; while (i>0){ int p=(i-1)/2; if (a[p] >= a[i]) break; LL t=a[p]; a[p]=a[i]; a[i]=t; i=p; } }
static LL maxTop(LL *a, int n){ return n? a[0] : 0; }
static void maxPop(LL *a, int *n){ int s=*n; if (s==0) return; a[0]=a[s-1]; (*n)--; s=*n; int i=0; while (1){ int l=2*i+1, r=2*i+2, b=i; if (l<s && a[l]>a[b]) b=l; if (r<s && a[r]>a[b]) b=r; if (b==i) break; LL t=a[i]; a[i]=a[b]; a[b]=t; i=b; } }

static void minPush(LL *a, int *n, LL v){ int i=*n; a[i]=v; (*n)++; while (i>0){ int p=(i-1)/2; if (a[p] <= a[i]) break; LL t=a[p]; a[p]=a[i]; a[i]=t; i=p; } }
static LL minTop(LL *a, int n){ return n? a[0] : 0; }
static void minPop(LL *a, int *n){ int s=*n; if (s==0) return; a[0]=a[s-1]; (*n)--; s=*n; int i=0; while (1){ int l=2*i+1, r=2*i+2, b=i; if (l<s && a[l]<a[b]) b=l; if (r<s && a[r]<a[b]) b=r; if (b==i) break; LL t=a[i]; a[i]=a[b]; a[b]=t; i=b; } }

static void pruneLow(void){ while (szLow>0){ LL v = maxTop(low, szLow); if (!delHas(v)) break; maxPop(low, &szLow); }
}
static void pruneUp(void){ while (szUp>0){ LL v = minTop(up, szUp); if (!delHas(v)) break; minPop(up, &szUp); }
}

static int mcount(void){ return szLow + szUp; }
static int targetK(void){ int m = mcount(); return m/2 + 1; }

static void rebalance(void)
{
    pruneLow(); pruneUp();
    int k = targetK();
    while (szLow > 0 && szLow > k){ LL v = maxTop(low, szLow); maxPop(low, &szLow); minPush(up, &szUp, v); pruneLow(); }
    while (szUp > 0 && szLow < k){ LL v = minTop(up, szUp); minPop(up, &szUp); maxPush(low, &szLow, v); pruneUp(); }
}

int main(void)
{
    delInit();
    int n; int cas=1; while (scanf("%d", &n)==1)
    {
        int cap = n + 5;
        low = (LL*)malloc((size_t)cap * sizeof(LL));
        up  = (LL*)malloc((size_t)cap * sizeof(LL));
        qarr= (LL*)malloc((size_t)cap * sizeof(LL));
        szLow=szUp=0; qh=0; qt=0;
        delClear();
        printf("Case #%d:\n", cas++);
        for (int i=0;i<n;++i)
        {
            char op[16];
            if (scanf("%15s", op)!=1) return 0;
            if (op[0]=='i')
            {
                LL x; scanf("%lld", &x);
                qarr[qt++]=x;
                pruneLow();
                if (szLow==0){ maxPush(low, &szLow, x); }
                else{
                    LL med = maxTop(low, szLow);
                    if (x <= med) maxPush(low, &szLow, x);
                    else minPush(up, &szUp, x);
                }
                rebalance();
            }
            else if (op[0]=='o')
            {
                LL v = qarr[qh++];
                pruneLow();
                LL med = szLow? maxTop(low, szLow) : (LL)0;
                delMark(v);
                if (szLow>0 && v <= med) { szLow--; }
                else { szUp--; }
                rebalance();
            }
            else
            {
                pruneLow();
                LL med = maxTop(low, szLow);
                printf("%lld\n", med);
            }
        }
        free(low); free(up); free(qarr);
    }
    free(delKeys); free(delUsed);
    return 0;
}