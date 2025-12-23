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
    int n; if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n - 1; ++i){ int x, y; scanf("%d %d", &x, &y); }
    if ((n & 1) == 1) puts("YES"); else puts("NO");
    return 0;
}