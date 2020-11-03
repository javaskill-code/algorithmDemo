#include "commonHead.h"

void selectSort(int *array, int len) {
    printf("============选择排序执行============\n");
    int i, j;
    // 保存最小元素的位置
    int minIndex = 0;
    // 外层做len-1 次循环
    for (int i = 0; i < len - 1; ++i) {
        minIndex = i;
        // 内层做 len-1-i 次循环
        for (int j = i + 1; j < len; ++j) {
            // 比较大小
            if (array[minIndex] > array[j]) {
                // 找到最小元素的位置
                minIndex = j;
            }
        }
        /**
         *  交换两个元素的值，每一趟最多只交换一次
         *
         */
        if (minIndex != i) {
            int temp = array[i];
            array[i] = array[minIndex];
            array[minIndex] = temp;
        }
    }
}

int main12345() {
    printf("================11111111111111============\n");
    int arr[MAX];
    srand((unsigned int) time(NULL));
    for (int i = 0; i < MAX; ++i) {
        arr[i] = rand() % MAX;
    }
    clock_t begin, end;
    double cost;
    printArray(arr, MAX);
    //开始记录
    begin = clock();
    selectSort(arr, MAX);
    end = clock();
    cost = (double) (end - begin) / CLOCKS_PER_SEC;
    printf("选择排序: %ld元素, time cost is: %lf secs\n", MAX, cost);
    printf("=======排序后=========\n");
    printArray(arr, MAX);
    return 0;
}

