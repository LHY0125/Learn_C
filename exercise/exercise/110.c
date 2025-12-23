#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
#include <windows.h>
#endif

typedef unsigned int u32;

static u32 press[25];

static void init_masks(void){
    for (int r = 0; r < 5; ++r){
        for (int c = 0; c < 5; ++c){
            int p = r * 5 + c;
            u32 m = 0U;
            m |= (1U << p);
            if (r > 0) m |= (1U << (p - 5));
            if (r < 4) m |= (1U << (p + 5));
            if (c > 0) m |= (1U << (p - 1));
            if (c < 4) m |= (1U << (p + 1));
            press[p] = m;
        }
    }
}

typedef struct { u32 key; unsigned char used; unsigned char val; } Entry;

static Entry *map;
static size_t cap;

static void map_init(size_t need){ size_t c = 1; while (c < need) c <<= 1; cap = c; map = (Entry*)calloc(cap, sizeof(Entry)); }

static void map_put(u32 key, unsigned char v){ size_t mask = cap - 1; size_t i = (size_t)(key & mask); for (;;){ if (!map[i].used){ map[i].used = 1; map[i].key = key; map[i].val = v; return; } if (map[i].key == key){ if (v < map[i].val) map[i].val = v; return; } i = (i + 1) & mask; } }

static int map_get(u32 key){ size_t mask = cap - 1; size_t i = (size_t)(key & mask); for (;;){ if (!map[i].used) return -1; if (map[i].key == key) return (int)map[i].val; i = (i + 1) & mask; } }

static int popcnt(u32 x){ return __builtin_popcount(x); }

int main(void){
#ifdef _WIN32
    system("chcp 65001 > nul");
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif
    init_masks();
    int T; if (scanf("%d", &T) != 1) return 0;
    u32 ones = 0x1FFFFFFU;
    int leftN = 12, rightN = 13;
    int leftIdx[12]; for (int i = 0; i < 12; ++i) leftIdx[i] = i;
    int rightIdx[13]; for (int i = 0; i < 13; ++i) rightIdx[i] = 12 + i;
    while (T--){
        u32 B = 0U;
        for (int r = 0; r < 5; ++r){
            for (int c = 0; c < 5; ++c){
                int v; scanf("%d", &v);
                if (v) B |= (1U << (r * 5 + c));
            }
        }
        u32 D = ones ^ B;
        size_t need = 16384;
        map_init(need);
        for (u32 s = 0; s < (1U << leftN); ++s){ int w = popcnt(s); if (w > 6) continue; u32 m = 0U; for (int i = 0; i < leftN; ++i){ if ((s >> i) & 1U) m ^= press[leftIdx[i]]; } map_put(m, (unsigned char)w); }
        int best = 7;
        for (u32 t = 0; t < (1U << rightN); ++t){ int wr = popcnt(t); if (wr > 6) continue; u32 mr = 0U; for (int i = 0; i < rightN; ++i){ if ((t >> i) & 1U) mr ^= press[rightIdx[i]]; } u32 needL = D ^ mr; int wl = map_get(needL); if (wl >= 0){ int s = wl + wr; if (s < best) best = s; } }
        if (best <= 6) printf("%d\n", best); else printf("-1\n");
    }
    return 0;
}