#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#endif

int main(void){
#ifdef _WIN32
    system("chcp 65001 > nul");
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif
    char ord[32];
    if (scanf("%31s", ord) != 1) return 0;
    char *s = (char*)malloc(100005);
    if (scanf("%100000s", s) != 1){ free(s); return 0; }
    int rank[26];
    for (int i = 0; i < 26; ++i) rank[(int)(ord[i]-'a')] = i;
    int cnt[26];
    for (int i = 0; i < 26; ++i) cnt[i] = 0;
    for (char *p = s; *p; ++p){ cnt[rank[(int)(*p - 'a')]]++; }
    for (int i = 0; i < 26; ++i){
        int c = cnt[i]; char ch = ord[i];
        while (c--) putchar(ch);
    }
    putchar('\n');
    free(s);
    return 0;
}