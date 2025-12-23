#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#endif

typedef struct { int to, next; } Edge;

int main(void){
#ifdef _WIN32
    system("chcp 65001 > nul");
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif
    int n; if (scanf("%d", &n) != 1) return 0;
    int m = n - 1;
    int *head = (int*)malloc(((size_t)n + 1) * sizeof(int));
    for (int i = 1; i <= n; ++i) head[i] = -1;
    Edge *edges = (Edge*)malloc((size_t)(2 * m) * sizeof(Edge));
    int ecnt = 0;
    for (int i = 0; i < m; ++i){ int x, y; scanf("%d %d", &x, &y); edges[ecnt] = (Edge){ y, head[x] }; head[x] = ecnt++; edges[ecnt] = (Edge){ x, head[y] }; head[y] = ecnt++; }
    int *parent = (int*)malloc(((size_t)n + 1) * sizeof(int));
    int *iter = (int*)malloc(((size_t)n + 1) * sizeof(int));
    char *vis = (char*)calloc((size_t)n + 1, 1);
    int *order = (int*)malloc((size_t)n * sizeof(int));
    int *stk = (int*)malloc((size_t)n * sizeof(int));
    int top = -1, ord = 0;
    parent[1] = 0; iter[1] = head[1]; vis[1] = 1; stk[++top] = 1;
    while (top >= 0){
        int u = stk[top];
        int e = iter[u];
        if (e != -1){
            iter[u] = edges[e].next;
            int v = edges[e].to;
            if (v == parent[u]) continue;
            if (!vis[v]){ vis[v] = 1; parent[v] = u; iter[v] = head[v]; stk[++top] = v; }
        } else {
            order[ord++] = u; --top;
        }
    }
    int *dp0 = (int*)calloc((size_t)n + 1, sizeof(int));
    int *dp1 = (int*)malloc(((size_t)n + 1) * sizeof(int));
    const int NEG = -1000000000;
    for (int i = 1; i <= n; ++i) dp1[i] = NEG;
    for (int t = 0; t < ord; ++t){
        int u = order[t];
        int base = 0;
        for (int e = head[u]; e != -1; e = edges[e].next){ int v = edges[e].to; if (v == parent[u]) continue; int mv = dp0[v] > dp1[v] ? dp0[v] : dp1[v]; base += mv; }
        dp0[u] = base;
        int best = NEG;
        for (int e = head[u]; e != -1; e = edges[e].next){ int v = edges[e].to; if (v == parent[u]) continue; int mv = dp0[v] > dp1[v] ? dp0[v] : dp1[v]; int cand = base - mv + dp0[v] + 1; if (cand > best) best = cand; }
        dp1[u] = best;
    }
    int ans = dp0[1] > dp1[1] ? dp0[1] : dp1[1];
    printf("%d\n", ans);
    free(dp1); free(dp0); free(stk); free(order); free(vis); free(iter); free(parent); free(edges); free(head);
    return 0;
}