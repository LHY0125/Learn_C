#include <stdio.h>

int insert(int size, int arr[], int pos, int val) {
    for (int i = size; i > pos; i--) {
        arr[i] = arr[i - 1]; // 元素后移
    }
    arr[pos] = val; // 插入新元素

    return size + 1; // 返回新的数组大小
}

int main() {
    int arr[100] = {1, 2, 3, 4, 5}; // 定义一个初始数组
    int size = 5; // 数组的当前元素个数

    int insertPos = 2; // 要设置值的位置
    int newValue = 99; // 要插入的新值

    // 调用插入函数
    size = insert(size, arr, insertPos, newValue);
 
    // 输出插入后的数组
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
 
    return 0;
}