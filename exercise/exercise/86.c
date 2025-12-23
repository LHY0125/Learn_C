#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
#include <windows.h>
#endif

typedef struct { int nxt[26]; int end; } Node;

int main(void){
#ifdef _WIN32
    system("chcp 65001 > nul");
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif
    char buf[1024];
    Node *tr = (Node*)malloc((size_t)1 * sizeof(Node));
    int cap = 1, sz = 1;
    for (int i = 0; i < 26; ++i) tr[0].nxt[i] = -1; tr[0].end = 0;
    while (scanf("%1023s", buf) == 1){
        if (buf[0] == '.' && buf[1] == '\0') break;
        int u = 0;
        for (int k = 0; buf[k]; ++k){
            int c = buf[k] - 'A';
            if (c < 0 || c >= 26) { u = -1; break; }
            int v = tr[u].nxt[c];
            if (v == -1){
                if (sz == cap){ cap = cap * 2 + 4; tr = (Node*)realloc(tr, (size_t)cap * sizeof(Node)); }
                v = sz++;
                for (int i = 0; i < 26; ++i) tr[v].nxt[i] = -1; tr[v].end = 0;
                tr[u].nxt[c] = v;
            }
            u = v;
        }
        if (u >= 0) tr[u].end = 1;
    }
    size_t S_cap = 200005;
    char *S = (char*)malloc(S_cap);
    size_t S_len = 0;
    while (scanf("%1023s", buf) == 1){
        size_t L = strlen(buf);
        if (S_len + L + 1 > S_cap){
            while (S_len + L + 1 > S_cap) S_cap = S_cap * 2 + 8;
            S = (char*)realloc(S, S_cap);
        }
        memcpy(S + S_len, buf, L);
        S_len += L;
    }
    S[S_len] = '\0';
    int n = (int)S_len;
    char *dp = (char*)malloc((size_t)n + 1);
    for (int i = 0; i <= n; ++i) dp[i] = 0;
    dp[0] = 1;
    int ans = 0;
    for (int i = 0; i < n; ++i){
        if (!dp[i]) continue;
        int u = 0;
        for (int step = 1; step <= 10; ++step){
            int j = i + step;
            if (j > n) break;
            int c = S[j-1] - 'A';
            if (c < 0 || c >= 26) break;
            int v = tr[u].nxt[c];
            if (v == -1) break;
            u = v;
            if (tr[u].end){ dp[j] = 1; if (j > ans) ans = j; }
        }
    }
    printf("%d\n", ans);
    free(dp);
    free(S);
    free(tr);
    return 0;
}