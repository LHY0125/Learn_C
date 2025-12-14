#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 语法：
// E := T ('|' T)*           // 选择，取较长长度
// T := F+                   // 连接，长度相加
// F := 'a' | '(' E ')'      // 原子：一个 a 或括号组
// 输出化简后（全为 a）的长度

static const char *s;
static int n, pos;

static int parse_E(void);
static int parse_T(void);
static int parse_F(void);

static int parse_E(void)
{
    int best = parse_T();
    while (pos < n && s[pos] == '|') {
        ++pos; // consume '|'
        int t = parse_T();
        if (t > best) best = t;
    }
    return best;
}

static int parse_T(void)
{
    int sum = 0;
    while (pos < n && s[pos] != ')' && s[pos] != '|') {
        sum += parse_F();
    }
    return sum;
}

static int parse_F(void)
{
    if (pos < n && s[pos] == 'a') {
        ++pos;
        return 1;
    }
    if (pos < n && s[pos] == '(') {
        ++pos; // consume '('
        int v = parse_E();
        if (pos < n && s[pos] == ')') ++pos; // consume ')'
        return v;
    }
    // 理论上不会到达（保证输入合法且不含空串），安全返回 0
    return 0;
}

int main(void)
{
    // 读取一行字符串（仅包含 a | ( )），长度不超过 1e5
    static char buf[1000005];
    if (scanf("%1000000s", buf) != 1) return 0;
    s = buf;
    n = (int)strlen(s);
    pos = 0;
    int ans = parse_E();
    printf("%d\n", ans);
    return 0;
}