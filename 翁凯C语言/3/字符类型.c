#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
    char c = '1';       // '1'���ַ�����,��������,ע�⣺" "Ҳ���ַ�����
    char d = 1;         // 1����������,�����ַ�����
    printf("%c\n", c);  // %c���ַ����
    printf("%d\n", d);  // %d���������

    char ch;
    scanf("%c", &ch);       // scanf("%c", &c)���ַ�����
    printf("ch=%d\n", ch);  // %d���������
    printf("ch='%c'\n", ch);// %c���ַ����

    // !char��һ���������ͣ����������ֱ����ʾ���ַ���������ASCII�룬Unicode��ȣ�Ҳ����˵��char���Ϳ��Ա�ʾһ���ַ���Ҳ���Ա�ʾһ�������������ʾʲô��ȡ�������ı��뷽ʽ�������printf����%d����%c��

    // ����
    char ch1 = 'a';
    ch1++;
    printf("'%c'\n", ch1);  //���'b'

    return 0;
}
    
