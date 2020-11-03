#include "commonHead.h"

void selectSort(int *array, int len) {
    printf("============ѡ������ִ��============\n");
    int i, j;
    // ������СԪ�ص�λ��
    int minIndex = 0;
    // �����len-1 ��ѭ��
    for (int i = 0; i < len - 1; ++i) {
        minIndex = i;
        // �ڲ��� len-1-i ��ѭ��
        for (int j = i + 1; j < len; ++j) {
            // �Ƚϴ�С
            if (array[minIndex] > array[j]) {
                // �ҵ���СԪ�ص�λ��
                minIndex = j;
            }
        }
        /**
         *  ��������Ԫ�ص�ֵ��ÿһ�����ֻ����һ��
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
    //��ʼ��¼
    begin = clock();
    selectSort(arr, MAX);
    end = clock();
    cost = (double) (end - begin) / CLOCKS_PER_SEC;
    printf("ѡ������: %ldԪ��, time cost is: %lf secs\n", MAX, cost);
    printf("=======�����=========\n");
    printArray(arr, MAX);
    return 0;
}

