#include <stdio.h>
#include <stdlib.h>

#include<time.h>

#define MAX_SIZE 10000                   //�����С
#define CYCLE_TIME 10000
clock_t start, stop;
double duration_select, duration_shell;//������ʱ

int *Init_Array();                     //����������鲢����
void Select_Sort(int *array);          //��������������һ��ѡ������
void Shell_Sort(int *array);           //��������������һ��ϣ������
void shellSort(int *a, int len); // ��������
void quickSort(int s[], int l, int r); // ������������������

int main2354222654532() {
    int time_select = CYCLE_TIME;
    int time_shell = CYCLE_TIME;
    int *array;

    start = clock();                   //��ʱ���
    while (time_select--) {            //ִ��ָ��������ѡ������
        array = Init_Array();
        Select_Sort(array);
    }
    stop = clock();                    //��ʱ�յ�
    //������������ʱ
    duration_select = ((double) (stop - start)) / CLOCKS_PER_SEC;


    start = clock();                   //��ʱ���
    while (time_shell--) {             //ִ��ָ��������ϣ������
        array = Init_Array();
        Shell_Sort(array);
    }
    stop = clock();                    //��ʱ�յ�
    //������������ʱ
    duration_shell = ((double) (stop - start)) / CLOCKS_PER_SEC;


    printf("ѡ���������%dλ����%d�ε���ʱΪ%f,ϣ���������ʱΪ%f��\n",
           MAX_SIZE, CYCLE_TIME, duration_select, duration_shell);

    printf("===========================\n");
    int a[10] = {0};
    int cnt = sizeof(a) / sizeof(a[0]);
    printf("cnt = %d\n", cnt);
//    printf("sizeof(a) = %d\n", sizeof(a));
    array = Init_Array();
//    printf(sizeof(array));
    quickSort(array, 0, MAX_SIZE);


    return 0;

}

int *Init_Array() {  //����������鲢����
    //����һ������ָ�벢Ϊ������ռ�
    int *array;
    array = (int *) malloc(sizeof(int) * MAX_SIZE);
    //��������������ֵ
    srand(time(NULL));
    for (int i = 0; i < MAX_SIZE; i++) {
        array[i] = rand();
    }
    //���������ַ
    return array;
}

void Select_Sort(int *array) {  //��������������һ��ѡ������
    int temp, min;
    for (int i = 0; i < MAX_SIZE - 1; i++) {  //ÿ��ѭ��ȡ�����е���һλ����
        min = i;  //��С����ȸ���i������
        for (int j = i + 1; j < MAX_SIZE; j++) {  //ÿ��ѭ������ȡ��iλ���������
            if (array[j] < array[min]) {  //��iλ�͵�jλ��С�Ļ����С���
                min = j;
            }
        }
        //��iλ����С��ǵ�λ����λ��
        temp = array[i];
        array[i] = array[min];
        array[min] = temp;
    }
}

void Shell_Sort(int *array) {  //��������������һ��ϣ������
    int j, temp, gap; //gapΪ����
    for (gap = MAX_SIZE / 2; gap >= 1; gap /= 2) {  // ������ʼ��Ϊ���鳤�ȵ�һ�룬ÿ�α����󲽳�����
        for (int i = gap; i < MAX_SIZE; i += gap) {  //�Բ���Ϊgap��Ԫ�ؽ��в�������
            temp = array[i];  //��¼array[i]��ֵ
            j = i - gap;  //j��ʼ��Ϊi��ǰһ��Ԫ�أ���i���gap���ȣ�
            while (j >= 0 && array[j] > temp) {//��jС��0��array[i]�ǵ�һλ����array[j]�ȵ�iλС����ѭ��
                array[j + gap] = array[j];  //����array[i]ǰ�ұ�temp��ֵ���Ԫ������ƶ�һλ
                j -= gap;
            }
            array[j + gap] = temp;
        }
    }
}

