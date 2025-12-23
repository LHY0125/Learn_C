#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#endif

typedef struct { int to, next; } Edge;

static int *head;
static Edge *edges;
static int ecnt;

static void add_edge(int u, int v){ edges[ecnt].to = v; edges[ecnt].next = head[u]; head[u] = ecnt++; }

static int cmp_desc(const void *a, const void *b){ int x = *(const int*)a, y = *(const int*)b; return y - x; }

static int dfs(int u, int p){
    int cnt = 0;
    for (int e = head[u]; e != -1; e = edges[e].next){ int v = edges[e].to; if (v == p) continue; ++cnt; }
    if (cnt == 0) return 0;
    int *ts = (int*)malloc((size_t)cnt * sizeof(int));
    int k = 0;
    for (int e = head[u]; e != -1; e = edges[e].next){ int v = edges[e].to; if (v == p) continue; ts[k++] = dfs(v, u); }
    qsort(ts, (size_t)cnt, sizeof(int), cmp_desc);
    int best = 0;
    for (int i = 0; i < cnt; ++i){ int t = 1 + i + ts[i]; if (t > best) best = t; }
    free(ts);
    return best;
}

int main(void){
#ifdef _WIN32
    system("chcp 65001 > nul");
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif
    int N; if (scanf("%d", &N) != 1) return 0;
    head = (int*)malloc(((size_t)N + 1) * sizeof(int));
    for (int i = 1; i <= N; ++i) head[i] = -1;
    edges = (Edge*)malloc((size_t)(2 * (N - 1)) * sizeof(Edge));
    ecnt = 0;
    for (int i = 2; i <= N; ++i){ int p; scanf("%d", &p); add_edge(i, p); add_edge(p, i); }
    int *times = (int*)malloc(((size_t)N + 1) * sizeof(int));
    int best = 1 << 30;
    for (int s = 1; s <= N; ++s){ int t = dfs(s, 0) + 1; times[s] = t; if (t < best) best = t; }
    printf("%d\n", best);
    int first = 1;
    for (int s = 1; s <= N; ++s){ if (times[s] == best){ if (!first) putchar(' '); first = 0; printf("%d", s); } }
    putchar('\n');
    free(times); free(edges); free(head);
    return 0;
}