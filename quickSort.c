//
// Created by Administrator on 2020/11/3.
//
#include "commonHead.h"

/*
 * �������� �ڿ����� ��һ�ֲ��ȶ����㷨
 */

void quickSort(int s[], int l, int r) {
    if (l < r) {
        int i = l, j = r;
        // �ó���һ��Ԫ�ر��浽x�� ��һ��λ�ó�Ϊһ����
        int x = s[l];
        while (i < j) {
            // ����������С��x������
            while (i < j && s[j] >= x) {
                // ���� ��ֱ������С�ڵ���x������
                j--;
            }
            if (i < j) {
                // ���Ҳ�С��x��Ԫ�ط��������У��Ҳ����һ����
                // ���Ԫ�غ���
                s[i++] = s[j];
            }
            // ������Ҵ��ڵ���x������
            while (i < j && s[j] < x) {
                // ���� ��ֱ����������x������
                i++;
            }
            if (i < j) {
                // ������ҵ���Ԫ�طŵ��Ҳ���У�������һ����
                // �Ҳ�Ԫ�������ƶ�
                s[j--] = s[i];
            }
        }
        //  ��ʱ i=j ��������x�е������������
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
    //��ʼ��¼
    begin = clock();
    quickSort(arr, 0, MAX);
    end = clock();
    cost = (double) (end - begin) / CLOCKS_PER_SEC;
    printf("��������: %ldԪ��, time cost is: %lf secs\n", MAX, cost);
    printf("=======�����=========\n");
//    printArray(arr, MAX);
    return 0;
}