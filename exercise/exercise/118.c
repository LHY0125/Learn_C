#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
#include <windows.h>
#endif

typedef struct { char *name; char *path; } Node;

static char* dupstr(const char* s){ size_t n = strlen(s); char* p = (char*)malloc(n + 1); if (!p) exit(1); memcpy(p, s, n + 1); return p; }

int main(void){
#ifdef _WIN32
    system("chcp 65001 > nul");
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif
    Node *nodes = (Node*)malloc(2000 * sizeof(Node));
    int cap = 2000, cnt = 0;
    int last_idx[2048];
    for (int i = 0; i < 2048; ++i) last_idx[i] = -1;
    char buf[4096];
    while (fgets(buf, sizeof(buf), stdin)){
        size_t len = strlen(buf);
        while (len && (buf[len-1] == '\n' || buf[len-1] == '\r')) buf[--len] = '\0';
        while (len && buf[len-1] == ' ') buf[--len] = '\0';
        if (len == 0) continue;
        if (strcmp(buf, "#") == 0) break;
        size_t i = 0; while (buf[i] == ' ') ++i;
        int level = (int)i;
        const char *name = buf + i;
        if (*name == '\0') continue;
        size_t nlen = strlen(name);
        char *path;
        if (level == 0){
            path = (char*)malloc(1 + nlen + 1);
            path[0] = '/';
            memcpy(path + 1, name, nlen);
            path[1 + nlen] = '\0';
        } else {
            const char *parent_path = nodes[last_idx[level - 1]].path;
            size_t plen = strlen(parent_path);
            path = (char*)malloc(plen + 1 + nlen + 1);
            memcpy(path, parent_path, plen);
            path[plen] = '/';
            memcpy(path + plen + 1, name, nlen);
            path[plen + 1 + nlen] = '\0';
        }
        if (cnt == cap){ cap <<= 1; nodes = (Node*)realloc(nodes, (size_t)cap * sizeof(Node)); }
        nodes[cnt].name = dupstr(name);
        nodes[cnt].path = path;
        last_idx[level] = cnt;
        ++cnt;
    }
    if (!fgets(buf, sizeof(buf), stdin)) return 0;
    size_t len = strlen(buf);
    while (len && (buf[len-1] == '\n' || buf[len-1] == '\r')) buf[--len] = '\0';
    while (len && buf[len-1] == ' ') buf[--len] = '\0';
    size_t j = 0; while (buf[j] == ' ') ++j; const char *q = buf + j;
    int found = 0;
    for (int i = 0; i < cnt; ++i){ if (strcmp(nodes[i].name, q) == 0){ puts(nodes[i].path); found = 1; } }
    if (!found) puts("NULL");
    for (int i = 0; i < cnt; ++i){ free(nodes[i].name); free(nodes[i].path); }
    free(nodes);
    return 0;
}