//
// Created by Administrator on 2020/11/3.
//
#include "commonHead.h"


void insertion_sort(int *array, int len)    //����һ�����뺯��"insertion_sort"
{
    int i = 0, ii = 0, temp = 0;
    for (i = 1; i < len; i++)  //ѭ������
    {
        temp = array[i];  //��tempÿһ�θ�ֵΪnumber[i]
        ii = i - 1;
        while (ii >= 0 && temp < array[ii])   //�����˳�� (temp���)"<"ΪС����">"Ϊ��С ������
        {
            array[ii + 1] = array[ii];    //�����Ԫ����ǰ��
            ii--;
        }
        array[ii + 1] = temp;   //��"number[ii+1]=number[ii];"һ����Ϊ
    }              //������������֮ǰ�Ĵ�,��number[ii]��number[ii+1]����
}


int main66666() {
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
    insertion_sort(arr, MAX);
    end = clock();
    cost = (double) (end - begin) / CLOCKS_PER_SEC;
    printf("��������: %ldԪ��, time cost is: %lf secs\n", MAX, cost);
    printf("=======�����=========\n");
//    printArray(arr, MAX);
    return 0;
}