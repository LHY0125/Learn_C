#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#ifdef _WIN32
#include <windows.h>
#include <direct.h>
#endif

// !文件输入输出
/*
    1.FILE
      FILE* fopen(const char * restrict path, const char* restrict mode);
      int fclose(FILE *stream);
      fscanf(FILE*....)
      fprintf(FILE*....)
    2.打开文件的标准代码
      FILE*fp = fopen("file","r");
      if(fp){
          fscanf(fp....);
          fclose(fp);
      }else{
          printf("打开文件失败");
      }
*/

int main()
{
    // 设置控制台编码为UTF-8
#ifdef _WIN32
    system("chcp 65001 > nul"); // 设置控制台编码为UTF-8
    SetConsoleOutputCP(65001);  // 设置控制台输出编码
    SetConsoleCP(65001);        // 设置控制台输入编码
#endif

    FILE *fp = fopen("test.txt", "r");
    if (fp)
    {
        int num;
        fscanf(fp,"%d", &num);
        printf("%d\n", num);
        fclose(fp);
    }
    else
    {
        printf("打开文件失败\n");
    }

    return 0;
}