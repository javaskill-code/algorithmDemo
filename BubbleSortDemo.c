//
// Created by Administrator on 2020/11/3.
//

#include<stdio.h>

int main3333333() {
    int i = 0;
    int j = 0;
    int temp;
    int a[10] = {4, 5, 6, 72, 1, 7, 9, 3, 0};
    int len = sizeof(a) / sizeof(a[0]);
    for (i = 0; i < len - 1; i++) {
        for (j = 0; j < len - 1 - i; j++) {
            if (a[j + 1] > a[j]) {
                temp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = temp;
            }
        }
    }
    for (i = 0; i < len; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}