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
    char **vals;
    unsigned char *used;
    size_t cap;
} Map;

static ull fnv1a(const char *s){
    ull h = 1469598103934665603ULL;
    while (*s){ h ^= (unsigned char)(*s++); h *= 1099511628211ULL; }
    return h;
}

static void map_init(Map *m, size_t n){ size_t c = 1; while (c < (n << 1)) c <<= 1; m->cap = c; m->keys = (char**)calloc(c, sizeof(char*)); m->vals = (char**)calloc(c, sizeof(char*)); m->used = (unsigned char*)calloc(c, 1); }

static void map_put(Map *m, const char *k, const char *v){ size_t mask = m->cap - 1; size_t i = (size_t)(fnv1a(k) & mask); for (;;){ if (!m->used[i]){ m->used[i] = 1; m->keys[i] = dupstr(k); m->vals[i] = dupstr(v); return; } if (strcmp(m->keys[i], k) == 0){ free(m->vals[i]); m->vals[i] = dupstr(v); return; } i = (i + 1) & mask; } }

static const char* map_get(Map *m, const char *k){ size_t mask = m->cap - 1; size_t i = (size_t)(fnv1a(k) & mask); for (;;){ if (!m->used[i]) return NULL; if (strcmp(m->keys[i], k) == 0) return m->vals[i]; i = (i + 1) & mask; } }

static void map_free(Map *m){ for (size_t i = 0; i < m->cap; ++i){ if (m->used[i]){ free(m->keys[i]); free(m->vals[i]); } } free(m->used); free(m->keys); free(m->vals); }

int main(void){
#ifdef _WIN32
    system("chcp 65001 > nul");
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif
    int M; if (scanf("%d", &M) != 1) return 0;
    Map mp; map_init(&mp, (size_t)(M > 0 ? M : 1));
    char s1[4096], s2[4096];
    for (int i = 0; i < M; ++i){ if (scanf("%4095s %4095s", s1, s2) != 2) return 0; map_put(&mp, s1, s2); }
    int L; if (scanf("%d", &L) != 1){ map_free(&mp); return 0; }
    int ch; do { ch = getchar(); } while (ch != '\n' && ch != EOF);
    char *line = NULL; size_t bufcap = 0; ssize_t linelen;
    for (int li = 0; li < L; ++li){
        size_t len = 0; bufcap = 4096; line = (char*)malloc(bufcap);
        int c;
        while ((c = getchar()) != EOF && c != '\n'){
            if (len + 1 >= bufcap){ bufcap <<= 1; line = (char*)realloc(line, bufcap); }
            line[len++] = (char)c;
        }
        line[len] = '\0';
        char *out = (char*)malloc(len * 2 + 16);
        size_t outlen = 0;
        const char *p = line;
        while (*p){
            while (*p && (*p == ' ' || *p == '\t' || *p == '\r')) ++p;
            if (!*p) break;
            const char *q = p;
            while (*q && *q != ' ' && *q != '\t' && *q != '\r') ++q;
            size_t toklen = (size_t)(q - p);
            char *tok = (char*)malloc(toklen + 1);
            memcpy(tok, p, toklen); tok[toklen] = '\0';
            const char *rep = map_get(&mp, tok);
            const char *emit = rep ? rep : tok;
            size_t emitlen = strlen(emit);
            if (outlen) out[outlen++] = ' ';
            if (outlen + emitlen + 1 >= bufcap){ size_t need = outlen + emitlen + 1; size_t nc = bufcap; while (nc < need) nc <<= 1; out = (char*)realloc(out, nc); bufcap = nc; }
            memcpy(out + outlen, emit, emitlen); outlen += emitlen; out[outlen] = '\0';
            free(tok);
            p = q;
        }
        printf("%s\n", out);
        free(out);
        free(line);
        if (c == EOF) break;
    }
    map_free(&mp);
    return 0;
}