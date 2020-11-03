#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>
#include <sys/timeb.h>

#define MAX 100000

long getSystemTime() {
    struct timeb tb;
    ftime(&tb);
    return tb.time * 1000;
}

/**
 *  交换函数
 * @param array
 * @param len
 */
void swap(int *a, int *b) {
//    printf("swap\t%d,%d", *a, *b);
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int array[], int len) {

    for (int i = 0; i < MAX - 1; i++) {
        for (int j = 0; j < MAX - 1 - i; j++) {
            if (array[j + 1] > array[j]) {
//                int temp = array[j + 1];
//                array[j + 1] = array[j];
//                array[j] = temp;
                swap(&array[j + 1], &array[j]);
            }
        }
    }
}

/**
 *  打印函数
 * @param arr
 */
//void printArray(int arr[], int length) {
//    for (int i = 0; i < length; ++i) {
//        printf("%d\t", arr[i]);
//    }
//    printf("\n");
//}

int main222222() {
//    int i = 0;
//    int j = 0;
//    int temp;
    printf("================11111111111111============\n");
    int arr[MAX];
    srand((unsigned int) time(NULL));
    for (int i = 0; i < MAX; ++i) {
        arr[i] = rand() % MAX;
    }
    printf("=======排序前=========");
//    printArray(arr, MAX);
//    for (i = 0; i < MAX - 1; i++) {
//        for (j = 0; j < MAX - 1 - i; j++) {
//            if (arr[j + 1] > arr[j]) {
//                temp = arr[j + 1];
//                arr[j + 1] = arr[j];
//                arr[j] = temp;
//            }
//        }
//    }
    long start = getSystemTime();
    bubbleSort(arr, MAX);
    long end = getSystemTime();
    printf("\t冒泡排序%d元素，所需要的时间%ld\n\t", MAX, end - start);
    printf("=======排序后=========");
//    printArray(arr, MAX);
    return 0;
}

