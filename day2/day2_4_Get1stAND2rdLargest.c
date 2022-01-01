//
//  day2_4_Get1stAND2rdLargest.c
//  day2_4_Get1stAND2rdLargest
//
//  Created by 雨轩 on 2021/12/29.
//

//  4. 求数组的最大值和次大值.

#include <stdio.h>
#include <stdlib.h>

void Get1stAND2rdLargest(int* a, int len, int* first, int* second) {
    if (a[0] > a[1]) {
        *first = a[0];
        *second = a[1];
    } else {
        *first = a[1];
        *second = a[0];
    }
    for (int i = 2; i < len; i++) {
        if (a[i] > *second) {
            if (a[i] > *first) {
                *second = *first;
                *first = a[i];
            } else {
                *second = a[i];
            }
        }
    }
}


int main(int argc, const char * argv[]) {
    int len = 0;
    printf("请输入数组长度：");
    scanf("%d", &len);
    int* array = (int*)malloc(sizeof(int) * len);
    printf("请依次输入数组内的元素，以空格或回车隔开：\n");
    for (int i = 0; i < len; i++) {
        scanf("%d", &array[i]);
    }
    int FirstLargest = 0, SecondLargest = 0;
    if (len > 1) {
        Get1stAND2rdLargest(array, len, &FirstLargest, &SecondLargest);
        printf("最大的元素是：%d, 第二大的元素是：%d\n", FirstLargest, SecondLargest);
    } else {
        printf("ERROR!\n");
    }
    return 0;
}
