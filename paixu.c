#include <stdio.h>
#include <stdlib.h>

#include<time.h>

#define MAX_SIZE 10000                   //数组大小
#define CYCLE_TIME 10000
clock_t start, stop;
double duration_select, duration_shell;//排序用时

int *Init_Array();                     //随机生成数组并返回
void Select_Sort(int *array);          //将输入的数组进行一次选择排序
void Shell_Sort(int *array);           //将输入的数组进行一次希尔排序
void shellSort(int *a, int len); // 函数声明
void quickSort(int s[], int l, int r); // 函数声明，快速排序

int main2354222654532() {
    int time_select = CYCLE_TIME;
    int time_shell = CYCLE_TIME;
    int *array;

    start = clock();                   //计时起点
    while (time_select--) {            //执行指定次数的选择排序
        array = Init_Array();
        Select_Sort(array);
    }
    stop = clock();                    //计时终点
    //计算排序总用时
    duration_select = ((double) (stop - start)) / CLOCKS_PER_SEC;


    start = clock();                   //计时起点
    while (time_shell--) {             //执行指定次数的希尔排序
        array = Init_Array();
        Shell_Sort(array);
    }
    stop = clock();                    //计时终点
    //计算排序总用时
    duration_shell = ((double) (stop - start)) / CLOCKS_PER_SEC;


    printf("选择排序随机%d位数组%d次的用时为%f,希尔排序的用时为%f。\n",
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

int *Init_Array() {  //随机生成数组并返回
    //定义一个数组指针并为其申请空间
    int *array;
    array = (int *) malloc(sizeof(int) * MAX_SIZE);
    //用随机函数随机赋值
    srand(time(NULL));
    for (int i = 0; i < MAX_SIZE; i++) {
        array[i] = rand();
    }
    //返回数组地址
    return array;
}

void Select_Sort(int *array) {  //将输入的数组进行一次选择排序
    int temp, min;
    for (int i = 0; i < MAX_SIZE - 1; i++) {  //每次循环取数组中的下一位数字
        min = i;  //最小标记先给第i个数字
        for (int j = i + 1; j < MAX_SIZE; j++) {  //每次循环依次取第i位后面的数字
            if (array[j] < array[min]) {  //第i位和第j位较小的获得最小标记
                min = j;
            }
        }
        //第i位和最小标记的位交换位置
        temp = array[i];
        array[i] = array[min];
        array[min] = temp;
    }
}

void Shell_Sort(int *array) {  //将输入的数组进行一次希尔排序
    int j, temp, gap; //gap为步长
    for (gap = MAX_SIZE / 2; gap >= 1; gap /= 2) {  // 步长初始化为数组长度的一半，每次遍历后步长减半
        for (int i = gap; i < MAX_SIZE; i += gap) {  //对步长为gap的元素进行插入排序
            temp = array[i];  //记录array[i]的值
            j = i - gap;  //j初始化为i的前一个元素（与i相差gap长度）
            while (j >= 0 && array[j] > temp) {//当j小于0即array[i]是第一位或者array[j]比第i位小跳出循环
                array[j + gap] = array[j];  //将在array[i]前且比temp的值大的元素向后移动一位
                j -= gap;
            }
            array[j + gap] = temp;
        }
    }
}

