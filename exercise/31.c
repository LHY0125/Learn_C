// 可随机访问的“栈”，支持按下标 O(1) 访问与快 I/O
// 操作：
// 1 x：压入整数 x
// 2：输出栈顶元素
// 3 i：输出第 i 个元素（从 0 开始）
// 4：弹出栈顶元素
// 约束：操作数最多 5,000,000；执行 3 时保证 i 有效

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 快读整数
static inline int read_int(void) {
    int c = getchar();
    while (c != EOF && (c == ' ' || c == '\n' || c == '\t' || c == '\r')) c = getchar();
    int sign = 1;
    if (c == '-') { sign = -1; c = getchar(); }
    int x = 0;
    while (c >= '0' && c <= '9') { x = x * 10 + (c - '0'); c = getchar(); }
    return sign * x;
}

// 快速输出整数并换行
static inline void write_int_ln(int x) {
    char buf[32];
    char *p = buf + sizeof(buf);
    *(--p) = '\n';
    unsigned int ux;
    if (x < 0) {
        ux = (unsigned int)(-(long long)x);
    } else {
        ux = (unsigned int)x;
    }
    do {
        *(--p) = (char)('0' + (ux % 10));
        ux /= 10;
    } while (ux);
    if (x < 0) *(--p) = '-';
    fwrite(p, 1, (size_t)(buf + sizeof(buf) - p), stdout);
}

typedef struct {
    int *a;
    size_t len;
    size_t cap;
} RAStack;

static inline void ras_init(RAStack *s) {
    s->len = 0;
    s->cap = 1024; // 初始容量
    s->a = (int*)malloc(s->cap * sizeof(int));
    if (!s->a) {
        // 若内存紧张，回退到较小容量以继续运行
        s->cap = 16;
        s->a = (int*)malloc(s->cap * sizeof(int));
        if (!s->a) exit(1);
    }
}

static inline void ras_reserve(RAStack *s, size_t need) {
    if (need <= s->cap) return;
    size_t new_cap = s->cap;
    while (new_cap < need) {
        // 约 1.5 倍扩容，以便在超大输入时节省内存
        new_cap = new_cap + (new_cap >> 1);
        if (new_cap < s->cap + 1) new_cap = s->cap + 1; // 避免停滞
    }
    int *na = (int*)realloc(s->a, new_cap * sizeof(int));
    if (!na) {
        // 若 1.5 倍失败则尝试翻倍
        new_cap = s->cap * 2;
        na = (int*)realloc(s->a, new_cap * sizeof(int));
        if (!na) exit(1);
    }
    s->a = na;
    s->cap = new_cap;
}

static inline void ras_push(RAStack *s, int x) {
    if (s->len == s->cap) ras_reserve(s, s->len + 1);
    s->a[s->len++] = x;
}

static inline int ras_top(const RAStack *s) {
    return s->a[s->len - 1];
}

static inline int ras_get(const RAStack *s, size_t i) {
    return s->a[i]; // 从底部 0 开始计数
}

static inline void ras_pop(RAStack *s) {
    --s->len;
}

int main(void) {
    RAStack st;
    ras_init(&st);

    int n = read_int();
    for (int k = 0; k < n; ++k) {
        int op = read_int();
        if (op == 1) {
            int x = read_int();
            ras_push(&st, x);
        } else if (op == 2) {
            write_int_ln(ras_top(&st));
        } else if (op == 3) {
            int i = read_int();
            write_int_ln(ras_get(&st, (size_t)i));
        } else if (op == 4) {
            ras_pop(&st);
        }
    }

    free(st.a);
    return 0;
}