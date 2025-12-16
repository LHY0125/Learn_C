// 简单逻辑表达式求值：支持 true/false 与 not/and/or，带错误检测
// 规则：
// - 仅包含单词 true, false, not, and, or 与空格；全部小写
// - 优先级：not > and > or；同级从左到右（左结合）
// - 输入为一行，输出为 true / false；如果语法或词法错误，输出 error

#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef enum { TK_TRUE, TK_FALSE, TK_AND, TK_OR, TK_NOT } Tok;

// 读取一行到缓冲区，并去除尾部换行符
static int read_line(char *buf, size_t sz) {
    if (!fgets(buf, (int)sz, stdin)) return 0;
    size_t n = strlen(buf);
    while (n && (buf[n-1] == '\n' || buf[n-1] == '\r')) buf[--n] = '\0';
    return 1;
}

// 词法：按字母分组，提取单词，映射到令牌；出错返回 -1
static int tokenize(const char *s, Tok *out, int maxn) {
    int nt = 0;
    size_t i = 0, n = strlen(s);
    while (i < n) {
        while (i < n && isspace((unsigned char)s[i])) ++i;
        if (i >= n) break;
        if (!isalpha((unsigned char)s[i])) return -1;  // 非法字符
        size_t j = i;
        while (j < n && isalpha((unsigned char)s[j])) ++j;
        size_t wlen = j - i;
        if (wlen == 4 && strncmp(s + i, "true", 4) == 0) {
            if (nt >= maxn) return -1;
            out[nt++] = TK_TRUE;
        } else if (wlen == 5 && strncmp(s + i, "false", 5) == 0) {
            if (nt >= maxn) return -1;
            out[nt++] = TK_FALSE;
        } else if (wlen == 3 && strncmp(s + i, "and", 3) == 0) {
            if (nt >= maxn) return -1;
            out[nt++] = TK_AND;
        } else if (wlen == 2 && strncmp(s + i, "or", 2) == 0) {
            if (nt >= maxn) return -1;
            out[nt++] = TK_OR;
        } else if (wlen == 3 && strncmp(s + i, "not", 3) == 0) {
            if (nt >= maxn) return -1;
            out[nt++] = TK_NOT;
        } else {
            return -1; // 未知单词
        }
        i = j;
    }
    return nt;
}

// 递归下降（迭代实现）语法：
// unary := { not }* ( true | false )
// and   := unary { and unary }*
// or    := and   { or and }*

static int parse_unary(const Tok *toks, int nt, int *idx, int *ok) {
    int neg = 0;
    while (*idx < nt && toks[*idx] == TK_NOT) { ++neg; ++*idx; }
    if (*idx >= nt) { *ok = 0; return 0; }
    int val;
    if (toks[*idx] == TK_TRUE) { val = 1; }
    else if (toks[*idx] == TK_FALSE) { val = 0; }
    else { *ok = 0; return 0; }
    ++*idx;
    if (neg & 1) val = !val;
    return val;
}

static int parse_and(const Tok *toks, int nt, int *idx, int *ok) {
    int lhs = parse_unary(toks, nt, idx, ok);
    if (!*ok) return 0;
    while (*idx < nt && toks[*idx] == TK_AND) {
        ++*idx;
        int rhs = parse_unary(toks, nt, idx, ok);
        if (!*ok) return 0;
        lhs = (lhs && rhs);
    }
    return lhs;
}

static int parse_or(const Tok *toks, int nt, int *idx, int *ok) {
    int lhs = parse_and(toks, nt, idx, ok);
    if (!*ok) return 0;
    while (*idx < nt && toks[*idx] == TK_OR) {
        ++*idx;
        int rhs = parse_and(toks, nt, idx, ok);
        if (!*ok) return 0;
        lhs = (lhs || rhs);
    }
    return lhs;
}

int main(void) {
    char line[512];
    if (!read_line(line, sizeof(line))) return 0;

    Tok toks[300];
    int nt = tokenize(line, toks, 300);
    if (nt <= 0) { printf("error\n"); return 0; }

    int idx = 0, ok = 1;
    int result = parse_or(toks, nt, &idx, &ok);
    if (!ok || idx != nt) { printf("error\n"); return 0; }

    printf(result ? "true\n" : "false\n");
    return 0;
}