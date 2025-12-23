#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

static uint64_t getv(FILE *f, int idx)
{
    uint64_t v;
    long off = (long)idx * (long)sizeof(uint64_t);
    fseek(f, off, SEEK_SET);
    fread(&v, sizeof(uint64_t), 1, f);
    return v;
}

int main(void)
{
    int n; if (scanf("%d", &n) != 1) return 0;
    FILE *f = tmpfile();
    if (!f) return 0;
    for (int i = 0; i < n; ++i)
    {
        unsigned long long x; scanf("%llu", &x);
        fwrite(&x, sizeof(uint64_t), 1, f);
    }
    int *st = (int *)malloc((size_t)n * sizeof(int));
    int top = 0;
    long long ans = 0;
    size_t B = 1 << 20;
    uint64_t *buf = (uint64_t *)malloc(B * sizeof(uint64_t));
    long long pos = (long long)n - 1;
    while (pos >= 0)
    {
        size_t take = (pos + 1 < (long long)B) ? (size_t)(pos + 1) : B;
        long long start = pos - (long long)take + 1;
        long off = (long)(start * (long long)sizeof(uint64_t));
        fseek(f, off, SEEK_SET);
        fread(buf, sizeof(uint64_t), take, f);
        for (long long p = (long long)take - 1; p >= 0; --p)
        {
            int i = (int)(start + p);
            uint64_t h = buf[p];
            while (top > 0)
            {
                uint64_t t = getv(f, st[top - 1]);
                if (t < h) --top; else break;
            }
            if (top > 0) ans += (long long)(st[top - 1] - i - 1);
            else ans += (long long)(n - 1 - i);
            st[top++] = i;
        }
        pos = start - 1;
    }
    printf("%lld\n", ans);
    free(st); free(buf); fclose(f);
    return 0;
}