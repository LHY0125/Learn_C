// 算术表达式求值：支持 + - * / ^ 和小括号
// 规则：
// - 运算符优先级：括号 > 一元± > ^（右结合）> * /（左结合）> + -（左结合）
// - 输入为一行表达式，可能包含多余括号与空格
// - 输出为结果，按四舍五入取整

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// 手写整数乘方（支持负指数）：右结合的 ^ 使用该实现
static inline long double powi_ld(long double base, long long exp) {
    if (exp == 0) return 1.0L;
    int neg = 0;
    if (exp < 0) { neg = 1; exp = -exp; }
    long double res = 1.0L, a = base;
    while (exp) {
        if (exp & 1LL) res *= a;
        a *= a;
        exp >>= 1LL;
    }
    if (neg) {
        // 避免 1/0 产生异常（表达式一般不会出现该情况）
        if (res == 0.0L) return 0.0L; // 约定返回 0，防止 RE
        return 1.0L / res;
    }
    return res;
}

// 手写四舍五入为 long long，避免依赖 llround
static inline long long roundll(long double x) {
    return (x >= 0.0L) ? (long long)(x + 0.5L) : (long long)(x - 0.5L);
}

// 操作符优先级
static inline int prec(char op) {
    switch (op) {
        case '~': return 4; // 一元负号
        case '^': return 3; // 乘方，右结合
        case '*': case '/': return 2; // 乘除
        case '+': case '-': return 1; // 加减
        default: return 0;
    }
}

// 应用一个操作符到栈顶操作数
static inline void apply_top(long double *vals, int *vtop, char *ops, int *otop) {
    char op = ops[--(*otop)];
    if (op == '~') {
        long double a = vals[--(*vtop)];
        vals[(*vtop)++] = -a;
        return;
    }
    long double b = vals[--(*vtop)];
    long double a = vals[--(*vtop)];
    long double r;
    switch (op) {
        case '+': r = a + b; break;
        case '-': r = a - b; break;
        case '*': r = a * b; break;
        case '/':
            // 防御除零导致的 RE：约定返回 0（题目数据通常不会出现此情况）
            if (b == 0.0L) r = 0.0L; else r = a / b; 
            break;
        case '^': {
            long long be = roundll(b); // 指数按近似整数处理
            r = powi_ld(a, be);
            break;
        }
        default: r = 0.0; break;
    }
    vals[(*vtop)++] = r;
}

int main(void) {
    // 读取整行表达式
    char *line = NULL;
    size_t cap = 0;
    {
        size_t bufcap = 1024; // 表达式长度 ≤ 30，这里足够
        line = (char*)malloc(bufcap);
        if (!line) return 1;
        if (!fgets(line, (int)bufcap, stdin)) return 0;
        size_t len = strlen(line);
        while (len && (line[len-1] == '\n' || line[len-1] == '\r')) line[--len] = '\0';
        cap = len + 1;
    }

    size_t L = strlen(line);
    // 栈容量按输入长度分配
    long double *vals = (long double*)malloc((L + 1) * sizeof(long double));
    char *ops = (char*)malloc(L + 1);
    if (!vals || !ops) return 1;
    int vtop = 0, otop = 0;

    int expect_unary = 1; // 是否期待一元运算符（开头或在'('或二元运算符之后）

    for (size_t i = 0; i < L;) {
        char c = line[i];
        if (isspace((unsigned char)c)) { ++i; continue; }
        if (c >= '0' && c <= '9') {
            // 解析数字（整数）
            long long x = 0;
            while (i < L && line[i] >= '0' && line[i] <= '9') {
                x = x * 10 + (line[i] - '0');
                ++i;
            }
            vals[vtop++] = (long double)x;
            expect_unary = 0;
        } else if (c == '(') {
            ops[otop++] = c;
            ++i;
            expect_unary = 1;
        } else if (c == ')') {
            while (otop > 0 && ops[otop - 1] != '(') {
                apply_top(vals, &vtop, ops, &otop);
            }
            if (otop > 0 && ops[otop - 1] == '(') --otop; // 弹出左括号
            ++i;
            expect_unary = 0;
        } else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
            // 处理一元 ±
            if (expect_unary && (c == '+' || c == '-')) {
                if (c == '-') {
                    // 一元负号入栈（最高优先级）
                    ops[otop++] = '~';
                }
                // 一元 '+' 不产生效果，直接跳过
                ++i;
                expect_unary = 1; // 仍可能继续接 '(' 或 数字
                continue;
            }

            // 处理二元运算符的结合与优先级
            int p = prec(c);
            int right_assoc = (c == '^');
            while (otop > 0 && ops[otop - 1] != '(') {
                int pt = prec(ops[otop - 1]);
                if ((right_assoc && pt > p) || (!right_assoc && pt >= p)) {
                    apply_top(vals, &vtop, ops, &otop);
                } else break;
            }
            ops[otop++] = c;
            ++i;
            expect_unary = 1;
        } else {
            // 其他字符（若存在）：跳过
            ++i;
        }
    }

    // 清空剩余操作符
    while (otop > 0) {
        apply_top(vals, &vtop, ops, &otop);
    }

    // 四舍五入输出整数
    if (vtop > 0) {
        long double res = vals[vtop - 1];
        long long rounded = roundll(res);
        printf("%lld\n", rounded);
    }

    free(vals);
    free(ops);
    free(line);
    return 0;
}