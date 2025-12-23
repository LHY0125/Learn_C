#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#endif

typedef struct { int val; int nxt; } Node;

static Node *heap;
static int hsz;

static void swap(Node *a, Node *b){ Node t=*a; *a=*b; *b=t; }
static int cmp(Node a, Node b){ return a.nxt > b.nxt; }
static void heap_push(Node x){
    int i = hsz++;
    heap[i] = x;
    while (i > 0) {
        int p = (i - 1) >> 1;
        if (cmp(heap[i], heap[p])) { swap(&heap[i], &heap[p]); i = p; } else break;
    }
}
static Node heap_top(){ return heap[0]; }
static void heap_pop(){
    heap[0] = heap[--hsz];
    int i = 0;
    for (;;) {
        int l = i * 2 + 1, r = l + 1, m = i;
        if (l < hsz && cmp(heap[l], heap[m])) m = l;
        if (r < hsz && cmp(heap[r], heap[m])) m = r;
        if (m == i) break;
        swap(&heap[i], &heap[m]); i = m;
    }
}

int main(void){
#ifdef _WIN32
    system("chcp 65001 > nul");
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif
    int N,m,p;
    while (scanf("%d %d %d", &N, &m, &p) == 3) {
        int *seq = (int*)malloc((size_t)p * sizeof(int));
        for (int i = 0; i < p; ++i) scanf("%d", &seq[i]);
        int INF = p + 1;
        int *nxt = (int*)malloc((size_t)p * sizeof(int));
        int *last = (int*)malloc(((size_t)m + 1) * sizeof(int));
        for (int i = 1; i <= m; ++i) last[i] = INF;
        for (int i = p - 1; i >= 0; --i) { int v = seq[i]; nxt[i] = last[v]; last[v] = i; }
        int *in = (int*)calloc((size_t)m + 1, sizeof(int));
        int *cur = (int*)malloc(((size_t)m + 1) * sizeof(int));
        for (int i = 1; i <= m; ++i) cur[i] = -1;
        heap = (Node*)malloc((size_t)p * sizeof(Node));
        hsz = 0;
        int cnt = 0;
        int miss = 0;
        for (int i = 0; i < p; ++i) {
            int v = seq[i];
            if (in[v]) {
                cur[v] = nxt[i];
                Node x = { v, nxt[i] };
                heap_push(x);
            } else {
                ++miss;
                if (cnt < N) {
                    in[v] = 1; cur[v] = nxt[i]; ++cnt; Node x = { v, nxt[i] }; heap_push(x);
                } else {
                    for (;;) {
                        if (hsz == 0) break;
                        Node t = heap_top();
                        if (!in[t.val] || cur[t.val] != t.nxt) { heap_pop(); continue; }
                        in[t.val] = 0; cur[t.val] = -1; heap_pop(); break;
                    }
                    in[v] = 1; cur[v] = nxt[i]; Node x = { v, nxt[i] }; heap_push(x);
                }
            }
        }
        printf("%d\n", miss);
        free(heap);
        free(cur);
        free(in);
        free(last);
        free(nxt);
        free(seq);
    }
    return 0;
}