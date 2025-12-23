#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
#include <windows.h>
#endif

static const int P = 61;

static int C[61][61];
static int pow2_small[400];

static int pow2_mod(unsigned long long e)
{
    unsigned long long b = 2ULL;
    unsigned long long r = 1ULL;
    while (e)
    {
        if (e & 1ULL)
            r = (r * b) % P;
        b = (b * b) % P;
        e >>= 1ULL;
    }
    return (int)r;
}

static int sum_prefix_mod61(unsigned long long k, long long t)
{
    if (t < 0)
        return 0;
    if ((unsigned long long)t >= k)
        return pow2_mod(k);
    int Kdig[16], Tdig[16];
    int L = 0;
    unsigned long long kk = k;
    while (kk)
    {
        Kdig[L++] = (int)(kk % P);
        kk /= P;
    }
    if (L == 0)
    {
        Kdig[L++] = 0;
    }
    unsigned long long tt = (unsigned long long)t;
    int Lt = 0;
    while (tt)
    {
        Tdig[Lt++] = (int)(tt % P);
        tt /= P;
    }
    while (Lt < L)
    {
        Tdig[Lt++] = 0;
    }
    int Krev[16], Trev[16];
    for (int i = 0; i < L; ++i)
    {
        Krev[i] = Kdig[L - 1 - i];
        Trev[i] = Tdig[L - 1 - i];
    }
    int suffix_sum_digits[17];
    suffix_sum_digits[L] = 0;
    for (int i = L - 1; i >= 0; --i)
        suffix_sum_digits[i] = suffix_sum_digits[i + 1] + Krev[i];
    int res = 0;
    for (int i = 0; i < L; ++i)
    {
        int limit = Trev[i];
        int nd = Krev[i];
        int up = (limit < nd) ? limit : nd;
        for (int w = 0; w < up; ++w)
        {
            int cv = C[nd][w];
            if (!cv)
                continue;
            int tail = suffix_sum_digits[i + 1];
            int add = (int)((cv * (long long)pow2_small[tail]) % P);
            res += add;
            if (res >= P)
                res -= P;
        }
        if (up >= 0)
        {
            int w = up;
            int cv = C[nd][w];
            if (!cv)
            {
                return res;
            }
            if (w < limit)
            {
                int tail = suffix_sum_digits[i + 1];
                int add = (int)((cv * (long long)pow2_small[tail]) % P);
                res += add;
                if (res >= P)
                    res -= P;
                return res;
            }
        }
    }
    res += 1;
    if (res >= P)
        res -= P;
    return res;
}

static inline char map_char(int x)
{
    if (x <= 9)
        return (char)('0' + x);
    if (x <= 35)
        return (char)('A' + (x - 10));
    return (char)('a' + (x - 36));
}

static int read_int_fast()
{
    int c = getchar();
    while (c != EOF && (c <= ' '))
        c = getchar();
    if (c == EOF)
        return -1;
    int x = 0;
    while (c > ' ')
    {
        x = x * 10 + (c - '0');
        c = getchar();
    }
    return x;
}

int main(void)
{
#ifdef _WIN32
    system("chcp 65001 > nul");
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif
    for (int n = 0; n <= 60; ++n)
    {
        C[n][0] = 1 % P;
        for (int r = 1; r <= n; ++r)
        {
            int v = (C[n - 1][r - 1] + C[n - 1][r]) % P;
            C[n][r] = v;
        }
    }
    pow2_small[0] = 1 % P;
    for (int i = 1; i < 400; ++i)
    {
        pow2_small[i] = (pow2_small[i - 1] * 2) % P;
    }
    int Q = read_int_fast();
    unsigned char *A = (unsigned char *)malloc((size_t)Q + 5);
    int head = 0, tail = 0;
    long long cnt0 = 0, cnt1 = 0, cntq = 0;
    int last = 0;
    int outputs = 0;
    for (int qi = 0; qi < Q; ++qi)
    {
        int x = read_int_fast();
        x ^= (last & 3);
        if (x == 0)
        {
            A[tail++] = 0;
            ++cnt0;
        }
        else if (x == 1)
        {
            A[tail++] = 1;
            ++cnt1;
        }
        else if (x == 2)
        {
            A[tail++] = 2;
            ++cntq;
        }
        else
        {
            unsigned char v = A[head++];
            if (v == 0)
                --cnt0;
            else if (v == 1)
                --cnt1;
            else
                --cntq;
        }
        int L = tail - head;
        if ((L & 1) == 1)
        {
            long long ones = cnt1;
            long long k = cntq;
            long long T = (L + 1) / 2;
            long long need = T - ones;
            int ans;
            if (need <= 0)
            {
                ans = pow2_mod((unsigned long long)k);
            }
            else if (need > k)
            {
                ans = 0;
            }
            else
            {
                unsigned long long K = (unsigned long long)k;
                unsigned long long sum0 = sum_prefix_mod61(K, (long long)(need - 1));
                int twoK = pow2_mod(K);
                ans = twoK - (int)sum0;
                if (ans < 0)
                    ans += P;
            }
            char ch = map_char(ans);
            putchar(ch);
            putchar('\n');
            last = ans;
            ++outputs;
        }
    }
    free(A);
    return 0;
}