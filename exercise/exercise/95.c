#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#endif

typedef unsigned long long ull;

static int maxV = 500;
static int BITS = 1024;
static int WORDS = 16;

static void or_words(ull *dst, const ull *src){
    for (int i = 0; i < WORDS; ++i) dst[i] |= src[i];
}

static void copy_words(ull *dst, const ull *src){
    for (int i = 0; i < WORDS; ++i) dst[i] = src[i];
}

int main(void){
#ifdef _WIN32
    system("chcp 65001 > nul");
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif
    int n; if (scanf("%d", &n) != 1) return 0;
    int *a = (int*)malloc((size_t)n * sizeof(int));
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    ull **leaf = (ull**)malloc((size_t)(maxV + 2) * sizeof(ull*));
    ull **bit = (ull**)malloc((size_t)(maxV + 2) * sizeof(ull*));
    for (int i = 0; i <= maxV + 1; ++i){ leaf[i] = (ull*)calloc((size_t)WORDS, sizeof(ull)); bit[i] = (ull*)calloc((size_t)WORDS, sizeof(ull)); }
    ull *acc = (ull*)calloc((size_t)WORDS, sizeof(ull));
    ull *tmp = (ull*)calloc((size_t)WORDS, sizeof(ull));
    ull *delta = (ull*)calloc((size_t)WORDS, sizeof(ull));
    for (int idx = 0; idx < n; ++idx){
        int v = a[idx]; if (v < 1) v = 1; if (v > maxV) v = maxV;
        for (int i = 0; i < WORDS; ++i) acc[i] = 0ULL;
        int k = v - 1;
        while (k > 0){ or_words(acc, bit[k]); k -= (k & -k); }
        acc[0] |= 1ULL;
        for (int i = 0; i < WORDS; ++i) tmp[i] = 0ULL;
        for (int w = 0; w < WORDS; ++w){
            ull x = acc[w];
            while (x){
                int t = __builtin_ctzll(x);
                int pos = (w<<6) + t;
                int np = pos ^ v;
                int nw = np >> 6, off = np & 63;
                tmp[nw] |= (1ULL << off);
                x &= (x - 1);
            }
        }
        int changed = 0;
        for (int i = 0; i < WORDS; ++i){ ull d = tmp[i] & ~leaf[v][i]; delta[i] = d; if (d) changed = 1; }
        if (changed){
            for (int i = 0; i < WORDS; ++i) leaf[v][i] |= delta[i];
            int p = v;
            while (p <= maxV){
                for (int i = 0; i < WORDS; ++i) bit[p][i] |= delta[i];
                p += (p & -p);
            }
        }
    }
    for (int i = 0; i < WORDS; ++i) acc[i] = 0ULL;
    int k = maxV;
    while (k > 0){ or_words(acc, bit[k]); k -= (k & -k); }
    acc[0] |= 1ULL;
    int cnt = 0;
    for (int w = 0; w < WORDS; ++w){ ull x = acc[w]; while (x){ x &= (x - 1); ++cnt; } }
    printf("%d\n", cnt);
    int first = 1;
    for (int i = 0; i < BITS; ++i){ int w = i >> 6, off = i & 63; if ((acc[w] >> off) & 1ULL){ if (!first) putchar(' '); first = 0; printf("%d", i); } }
    putchar('\n');
    free(delta); free(tmp); free(acc);
    for (int i = 0; i <= maxV + 1; ++i){ free(bit[i]); free(leaf[i]); }
    free(bit); free(leaf); free(a);
    return 0;
}