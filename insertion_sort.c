//
// Created by Administrator on 2020/11/3.
//
#include "commonHead.h"


void insertion_sort(int *array, int len)    //定义一个插入函数"insertion_sort"
{
    int i = 0, ii = 0, temp = 0;
    for (i = 1; i < len; i++)  //循环遍历
    {
        temp = array[i];  //将temp每一次赋值为number[i]
        ii = i - 1;
        while (ii >= 0 && temp < array[ii])   //这里改顺序 (temp后的)"<"为小到大，">"为大到小 ！！！
        {
            array[ii + 1] = array[ii];    //将大的元素往前放
            ii--;
        }
        array[ii + 1] = temp;   //与"number[ii+1]=number[ii];"一起意为
    }              //如果插入的数比之前的大,将number[ii]与number[ii+1]互换
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
    //开始记录
    begin = clock();
    insertion_sort(arr, MAX);
    end = clock();
    cost = (double) (end - begin) / CLOCKS_PER_SEC;
    printf("插入排序: %ld元素, time cost is: %lf secs\n", MAX, cost);
    printf("=======排序后=========\n");
//    printArray(arr, MAX);
    return 0;
}