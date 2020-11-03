//
// Created by Administrator on 2020/11/3.
//
#include "commonHead.h"

/**
 *  希尔排序就是插入排序的分组
 * @param a
 * @param len
 */
void shellSortDemo(int *a, int len) {
    int i, j, k, tmp, gap;  // gap 为步长
    for (gap = len / 2; gap > 0; gap /= 2) {  // 步长初始化为数组长度的一半，每次遍历后步长减半,
        for (i = 0; i < gap; ++i) { // 变量 i 为每次分组的第一个元素下标
            for (j = i + gap; j < len; j += gap) { //对步长为gap的元素进行直插排序，当gap为1时，就是直插排序
                tmp = a[j];  // 备份a[i]的值
                k = j - gap;  // j初始化为i的前一个元素（与i相差gap长度）
                while (k >= 0 && a[k] > tmp) {
                    a[k + gap] = a[k]; // 将在a[i]前且比tmp的值大的元素向后移动一位
                    k -= gap;
                }
                a[k + gap] = tmp;
            }
        }
    }
}


int mainshellSort() {
    printf("================11111111111111============\n");
    int arr[MAX];
    srand((unsigned int) time(NULL));
    for (int i = 0; i < MAX; ++i) {
        arr[i] = rand() % MAX;
    }
    clock_t begin, end;
    double cost;
//    printArray(arr, MAX);
    //开始记录
    begin = clock();
    shellSortDemo(arr, MAX);
    end = clock();
    cost = (double) (end - begin) / CLOCKS_PER_SEC;
    printf("希尔排序: %ld元素, time cost is: %lf secs\n", MAX, cost);
    printf("=======排序后=========\n");
//    printArray(arr, MAX);
    return 0;
}