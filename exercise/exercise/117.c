#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#endif

typedef struct
{
    int x, y;
} Pt;

static int manh(Pt a, Pt b)
{
    int dx = a.x - b.x;
    if (dx < 0)
        dx = -dx;
    int dy = a.y - b.y;
    if (dy < 0)
        dy = -dy;
    return dx + dy;
}

static void gen_segment(Pt a, Pt b)
{
    int sx = (b.x > a.x) ? 1 : (b.x < a.x ? -1 : 0);
    int sy = (b.y > a.y) ? 1 : (b.y < a.y ? -1 : 0);
    while (a.x != b.x)
    {
        a.x += sx;
        printf(" (%d,%d)", a.x, a.y);
    }
    while (a.y != b.y)
    {
        a.y += sy;
        printf(" (%d,%d)", a.x, a.y);
    }
}

static int perm_next(int *p, int n)
{
    int i = n - 2;
    while (i >= 0 && p[i] > p[i + 1])
        --i;
    if (i < 0)
        return 0;
    int j = n - 1;
    while (p[j] < p[i])
        --j;
    int t = p[i];
    p[i] = p[j];
    p[j] = t;
    int l = i + 1, r = n - 1;
    while (l < r)
    {
        t = p[l];
        p[l] = p[r];
        p[r] = t;
        ++l;
        --r;
    }
    return 1;
}

static void best_route(Pt S, Pt *grp, int k, int *best_len, int *best_order)
{
    int idx[4];
    for (int i = 0; i < k; ++i)
        idx[i] = i;
    int first = 1;
    do
    {
        int sum = 0;
        Pt cur = S;
        for (int i = 0; i < k; ++i)
        {
            sum += manh(cur, grp[idx[i]]);
            cur = grp[idx[i]];
        }
        if (first || sum < *best_len)
        {
            *best_len = sum;
            for (int i = 0; i < k; ++i)
                best_order[i] = idx[i];
            first = 0;
        }
    } while (perm_next(idx, k));
}

typedef struct
{
    Pt *pts;
    int cnt;
} Bucket;

int main(void)
{
#ifdef _WIN32
    system("chcp 65001 > nul");
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif
    int N;
    if (scanf("%d", &N) != 1)
        return 0;
    Pt *emps = (Pt *)malloc((size_t)N * sizeof(Pt));
    for (int i = 0; i < N; ++i)
        scanf("%d %d", &emps[i].x, &emps[i].y);
    Pt S;
    scanf("%d %d", &S.x, &S.y);
    Pt *eff = (Pt *)malloc((size_t)N * sizeof(Pt));
    int M = 0;
    for (int i = 0; i < N; ++i)
    {
        if (emps[i].x == S.x && emps[i].y == S.y)
            continue;
        eff[M++] = emps[i];
    }
    if (M == 0)
    {
        printf("0\n0\n");
        free(eff);
        free(emps);
        return 0;
    }
    Bucket bkt[8];
    for (int i = 0; i < 8; ++i)
    {
        bkt[i].pts = (Pt *)malloc((size_t)M * sizeof(Pt));
        bkt[i].cnt = 0;
    }
    for (int i = 0; i < M; ++i)
    {
        int dx = eff[i].x - S.x, dy = eff[i].y - S.y;
        int id = 0;
        if (dx > 0 && dy > 0)
            id = 0;
        else if (dx < 0 && dy > 0)
            id = 1;
        else if (dx > 0 && dy < 0)
            id = 2;
        else if (dx < 0 && dy < 0)
            id = 3;
        else if (dx == 0 && dy > 0)
            id = 4;
        else if (dx == 0 && dy < 0)
            id = 5;
        else if (dy == 0 && dx > 0)
            id = 6;
        else
            id = 7;
        bkt[id].pts[bkt[id].cnt++] = eff[i];
    }
    int groups = 0;
    int cap = (M + 3) / 4;
    Pt **grp_pts = (Pt **)malloc((size_t)cap * sizeof(Pt *));
    int *grp_sizes = (int *)malloc((size_t)cap * sizeof(int));
    for (int id = 0; id < 8; ++id)
    {
        int c = bkt[id].cnt;
        if (c == 0)
            continue;
        int *ord = (int *)malloc((size_t)c * sizeof(int));
        for (int i = 0; i < c; ++i)
            ord[i] = i;
        for (int i = 0; i < c; ++i)
        {
            for (int j = i + 1; j < c; ++j)
            {
                if (manh(S, bkt[id].pts[ord[i]]) > manh(S, bkt[id].pts[ord[j]]))
                {
                    int t = ord[i];
                    ord[i] = ord[j];
                    ord[j] = t;
                }
            }
        }
        int i = 0;
        while (i < c)
        {
            int k = c - i;
            if (k > 4)
                k = 4;
            Pt *arr = (Pt *)malloc((size_t)k * sizeof(Pt));
            for (int t = 0; t < k; ++t)
                arr[t] = bkt[id].pts[ord[i + t]];
            grp_pts[groups] = arr;
            grp_sizes[groups] = k;
            ++groups;
            i += k;
        }
        free(ord);
    }
    int *lens = (int *)malloc((size_t)groups * sizeof(int));
    int **order = (int **)malloc((size_t)groups * sizeof(int *));
    for (int g = 0; g < groups; ++g)
    {
        order[g] = (int *)malloc(4 * sizeof(int));
        int bl = 0;
        best_route(S, grp_pts[g], grp_sizes[g], &bl, order[g]);
        lens[g] = bl;
    }
    int total = 0;
    for (int g = 0; g < groups; ++g)
        total += lens[g];
    printf("%d\n", total);
    printf("%d\n", groups);
    for (int g = 0; g < groups; ++g)
    {
        printf("%d", lens[g]);
        for (int i = 0; i < grp_sizes[g]; ++i)
        {
            Pt p = grp_pts[g][i];
            printf("(%d,%d)%s", p.x, p.y, (i + 1 == grp_sizes[g]) ? " " : " ");
        }
        printf(": ");
        Pt cur = S;
        printf("(%d,%d)", cur.x, cur.y);
        for (int i = 0; i < grp_sizes[g]; ++i)
        {
            Pt nxt = grp_pts[g][order[g][i]];
            gen_segment(cur, nxt);
            cur = nxt;
        }
        printf("\n");
    }
    for (int g = 0; g < groups; ++g)
    {
        free(order[g]);
        free(grp_pts[g]);
    }
    free(order);
    free(grp_pts);
    free(grp_sizes);
    free(lens);
    for (int i = 0; i < 8; ++i)
        free(bkt[i].pts);
    free(eff);
    free(emps);
    return 0;
}