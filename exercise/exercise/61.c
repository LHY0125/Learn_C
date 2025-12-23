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
    int n;
    if (scanf("%d", &n) != 1) return 0;
    char *s = (char*)malloc((size_t)n + 5);
    scanf("%s", s);
    int cntH = 0;
    for (int i = 0; i < n; ++i) if (s[i] == 'H') ++cntH;
    int cntT = n - cntH;
    if (cntH == 0 || cntH == n){ printf("0\n"); free(s); return 0; }

    char *d = (char*)malloc((size_t)2*n + 5);
    for (int i = 0; i < n; ++i){ d[i] = s[i]; d[i+n] = s[i]; }

    int lenH = cntH;
    int t_in = 0;
    for (int i = 0; i < lenH; ++i) if (d[i] == 'T') ++t_in;
    int bestH = t_in;
    for (int i = 1; i < n; ++i){
        if (d[i-1] == 'T') --t_in;
        if (d[i+lenH-1] == 'T') ++t_in;
        if (t_in < bestH) bestH = t_in;
    }

    int lenT = cntT;
    int h_in = 0;
    for (int i = 0; i < lenT; ++i) if (d[i] == 'H') ++h_in;
    int bestT = h_in;
    for (int i = 1; i < n; ++i){
        if (d[i-1] == 'H') --h_in;
        if (d[i+lenT-1] == 'H') ++h_in;
        if (h_in < bestT) bestT = h_in;
    }

    int ans = bestH < bestT ? bestH : bestT;
    printf("%d\n", ans);
    free(d);
    free(s);
    return 0;
}