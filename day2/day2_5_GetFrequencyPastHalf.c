//
//  day2_5_GetFrequencyPastHalf.c
//  day2_5_GetFrequencyPastHalf
//
//  Created by 雨轩 on 2021/12/29.
//

//  5. 给定一个 n 个整型元素的数组 a , 其中有一个元素出现次数超过 n / 2, 求这个元素.

#include <stdio.h>
#include <stdlib.h>

int GetFrequencyPastHalf(int* a, int len) {
    int cnt = 1, num = a[0];
    for (int i = 1; i < len; i++) {
        if (a[i] == num) {
            cnt++;
        } else {
            cnt--;
            if (cnt < 0) {
                cnt = 1;
                num = a[i];
            }
        }
    }
    return num;
}

int main(int argc, const char * argv[]) {
    while (1) {
        int len = 0;
        printf("请输入数组长度：");
        scanf("%d", &len);
        if (len < 0) {
            break;
        }
        int* array = (int*)malloc(sizeof(int) * len);
        printf("请依次输入数组内的元素，以空格或回车隔开：\n");
        for (int i = 0; i < len; i++) {
            scanf("%d", &array[i]);
        }
        if (len > 2) {
            int res = GetFrequencyPastHalf(array, len);
            printf("出现频率大于1/2的元素是：%d\n\n", res);
        }
    }
    return 0;
}
