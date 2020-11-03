//
// Created by Administrator on 2020/11/3.
//
#include "commonHead.h"

/**
 *  ϣ��������ǲ�������ķ���
 * @param a
 * @param len
 */
void shellSortDemo(int *a, int len) {
    int i, j, k, tmp, gap;  // gap Ϊ����
    for (gap = len / 2; gap > 0; gap /= 2) {  // ������ʼ��Ϊ���鳤�ȵ�һ�룬ÿ�α����󲽳�����,
        for (i = 0; i < gap; ++i) { // ���� i Ϊÿ�η���ĵ�һ��Ԫ���±�
            for (j = i + gap; j < len; j += gap) { //�Բ���Ϊgap��Ԫ�ؽ���ֱ�����򣬵�gapΪ1ʱ������ֱ������
                tmp = a[j];  // ����a[i]��ֵ
                k = j - gap;  // j��ʼ��Ϊi��ǰһ��Ԫ�أ���i���gap���ȣ�
                while (k >= 0 && a[k] > tmp) {
                    a[k + gap] = a[k]; // ����a[i]ǰ�ұ�tmp��ֵ���Ԫ������ƶ�һλ
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
    //��ʼ��¼
    begin = clock();
    shellSortDemo(arr, MAX);
    end = clock();
    cost = (double) (end - begin) / CLOCKS_PER_SEC;
    printf("ϣ������: %ldԪ��, time cost is: %lf secs\n", MAX, cost);
    printf("=======�����=========\n");
//    printArray(arr, MAX);
    return 0;
}