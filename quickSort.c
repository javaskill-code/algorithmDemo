//
// Created by Administrator on 2020/11/3.
//
#include "commonHead.h"

/*
 * 快速排序 挖坑填数 是一种不稳定的算法
 */

void quickSort(int s[], int l, int r) {
    if (l < r) {
        int i = l, j = r;
        // 拿出第一个元素保存到x中 第一个位置成为一个坑
        int x = s[l];
        while (i < j) {
            // 从右向左找小于x的数字
            while (i < j && s[j] >= x) {
                // 左移 ，直到遇到小于等于x的数字
                j--;
            }
            if (i < j) {
                // 将右侧小于x的元素放入左侧坑中，右侧出现一个坑
                // 左侧元素后移
                s[i++] = s[j];
            }
            // 从左侧找大于等于x的数字
            while (i < j && s[j] < x) {
                // 右移 ，直到遇到大于x的数字
                i++;
            }
            if (i < j) {
                // 将左侧找到的元素放到右侧坑中，左侧出现一个坑
                // 右侧元素向左移动
                s[j--] = s[i];
            }
        }
        //  此时 i=j 将保存在x中的数字填入坑中
        s[i] = x;
        quickSort(s, l, i - 1);
        quickSort(s, i + 1, r);
    }
}

int main() {
    printf("================quickSortTest============\n");
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
    quickSort(arr, 0, MAX);
    end = clock();
    cost = (double) (end - begin) / CLOCKS_PER_SEC;
    printf("快速排序: %ld元素, time cost is: %lf secs\n", MAX, cost);
    printf("=======排序后=========\n");
//    printArray(arr, MAX);
    return 0;
}