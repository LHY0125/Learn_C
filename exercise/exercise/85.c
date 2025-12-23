#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#endif

typedef unsigned long long ull;

int main(void){
#ifdef _WIN32
    system("chcp 65001 > nul");
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif
    int m,n;
    if (scanf("%d %d", &m, &n) != 2) return 0;
    int S = m * (n - 1);
    if (S <= 0){ printf("1\n"); return 0; }
    ull a = 1, b = 1;
    for (int i = 2; i <= S; ++i){ ull c = a + b; a = b; b = c; }
    printf("%llu\n", b);
    return 0;
}