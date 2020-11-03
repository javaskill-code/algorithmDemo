#include <stdio.h>
#include <stdlib.h>

#include<time.h>
#define MAX_SIZE 10                    //数组大小
#define CYCLE_TIME 10000
clock_t start, stop;
double duration_select, duration_shell;//排序用时

int *Init_Array();                     //随机生成数组并返回
void Select_Sort(int *array);          //将输入的数组进行一次选择排序
void Shell_Sort(int *array);           //将输入的数组进行一次希尔排序
void shellSort(int *a, int len); // 函数声明

int main11(void)
{

    printf("========大家好==========\n");
    int i, len, * a;
    printf("请输入要排的数的个数：");
    scanf("%d",&len);
    a = (int *)malloc(len * sizeof(int)); // 动态定义数组
    printf("请输入要排的数：\n");
    for (i = 0; i < len; i++) { // 数组值的输入
        scanf("%d",&a[i]);
    }
    shellSort(a, len); // 调用希尔排序函数
    printf("希尔升序排列后结果为：\n");
    for (i = 0; i < len; i++) { // 排序后的结果的输出
        printf("%d\t",a[i]);
    }
    printf("\n");

    return 0;
}

void shellSort(int *a, int len)
{
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

