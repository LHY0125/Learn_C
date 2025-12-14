#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#endif

// 图的边的表示
typedef struct
{
    int u, v;
    int w;
} Edge;

// 边的比较函数，用于排序
static int cmp_edge(const void *a, const void *b)
{
    int wa = ((const Edge *)a)->w;
    int wb = ((const Edge *)b)->w;
    return (wa > wb) - (wa < wb);
}

// 并查集的查找函数
static int find(int *parent, int x)
{
    if (parent[x] == x)
    {
        return x;
    }
    return parent[x] = find(parent, parent[x]);
}

// 并查集的合并函数
static void unite(int *parent, int *sz, int a, int b)
{
    if (sz[a] < sz[b])
    {
        int t = a;
        a = b;
        b = t;
    }
    parent[b] = a;
    sz[a] += sz[b];
}

int main(void)
{
#ifdef _WIN32
    system("chcp 65001 > nul");
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif

    // 读取图的边数和节点数
    int n, m;
    if (scanf("%d %d", &n, &m) != 2)
    {
        printf("输入错误\n");
        return 0;
    }

    // 读取图的边
    Edge *e = (Edge *)malloc((size_t)m * sizeof(Edge));
    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        e[i].u = u;
        e[i].v = v;
        e[i].w = w;
    }

    // 初始化并查集
    int *parent = (int *)malloc((size_t)(n + 1) * sizeof(int));
    int *sz = (int *)malloc((size_t)(n + 1) * sizeof(int));
    for (int i = 1; i <= n; ++i)
    {
        parent[i] = i;
        sz[i] = 1;
    }

    // 对边按权重排序
    qsort(e, (size_t)m, sizeof(Edge), cmp_edge);

    // 最小生成树的计算
    long long ans = 0;
    int cnt = 0;
    for (int i = 0; i < m && cnt < n - 1; ++i)
    {
        // 跳过无效的边
        int u = e[i].u, v = e[i].v;
        if (u < 1 || u > n || v < 1 || v > n)
        {
            continue;
        }
        // 检查是否形成环
        int ru = find(parent, u), rv = find(parent, v);
        if (ru != rv)
        {
            ans += e[i].w;
            unite(parent, sz, ru, rv);
            ++cnt;
        }
    }

    // 检查是否所有节点都在最小生成树中
    if (cnt == n - 1)
    {
        printf("%lld\n", ans);
    }
    else
    {
        printf("impossible\n");
    }

    free(sz);
    free(parent);
    free(e);
    return 0;
}