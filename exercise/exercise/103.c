#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
#include <windows.h>
#endif

typedef unsigned long long ull;

static char* dupstr(const char* s){ size_t len = strlen(s); char* p = (char*)malloc(len + 1); memcpy(p, s, len + 1); return p; }

typedef struct {
    char **keys;
    int *cnt;
    unsigned char *used;
    size_t cap;
} MapC;

static ull fnv1a(const char *s){ ull h = 1469598103934665603ULL; while (*s){ h ^= (unsigned char)(*s++); h *= 1099511628211ULL; } return h; }

static void map_init(MapC *m, size_t n){ size_t c = 1; while (c < (n << 1)) c <<= 1; m->cap = c; m->keys = (char**)calloc(c, sizeof(char*)); m->cnt = (int*)calloc(c, sizeof(int)); m->used = (unsigned char*)calloc(c, 1); }

static void map_inc(MapC *m, const char *k){ size_t mask = m->cap - 1; size_t i = (size_t)(fnv1a(k) & mask); for (;;){ if (!m->used[i]){ m->used[i] = 1; m->keys[i] = dupstr(k); m->cnt[i] = 1; return; } if (strcmp(m->keys[i], k) == 0){ ++m->cnt[i]; return; } i = (i + 1) & mask; } }

static int map_get_cnt(MapC *m, const char *k){ size_t mask = m->cap - 1; size_t i = (size_t)(fnv1a(k) & mask); for (;;){ if (!m->used[i]) return 0; if (strcmp(m->keys[i], k) == 0) return m->cnt[i]; i = (i + 1) & mask; } }

static void map_free(MapC *m){ for (size_t i = 0; i < m->cap; ++i){ if (m->used[i]) free(m->keys[i]); } free(m->used); free(m->cnt); free(m->keys); }

int main(void){
#ifdef _WIN32
    system("chcp 65001 > nul");
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif
    int N; if (scanf("%d", &N) != 1) return 0;
    MapC mp; map_init(&mp, (size_t)(N > 0 ? N : 1));
    char **tks = (char**)malloc((size_t)N * sizeof(char*));
    char buf[4096];
    for (int i = 0; i < N; ++i){ if (scanf("%4095s", buf) != 1){ N = i; break; } tks[i] = dupstr(buf); map_inc(&mp, tks[i]); }
    int minc = 0x7fffffff; for (size_t i = 0; i < mp.cap; ++i){ if (mp.used[i]){ if (mp.cnt[i] < minc) minc = mp.cnt[i]; } }
    int first = 1;
    for (int i = 0; i < N; ++i){ int c = map_get_cnt(&mp, tks[i]); if (c != minc){ if (!first) putchar(' '); first = 0; fputs(tks[i], stdout); } }
    putchar('\n');
    for (int i = 0; i < N; ++i) free(tks[i]);
    free(tks);
    map_free(&mp);
    return 0;
}