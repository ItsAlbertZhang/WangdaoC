//
//  day2_6_GetMinAbs.c
//  day2_6_GetMinAbs
//
//  Created by 雨轩 on 2021/12/29.
//

//  6. 给定一个含有n个元素的整型数组, 找出数组中的两个元素 x 和 y 使得 abs(x - y) 值最小.

#include <stdio.h>
#include <stdlib.h>

int Partition(int a[], int low, int high) {
    int temp = a[low];
    while (low < high) {
        while (low < high && a[high] >= temp) {
            high--;
        }
        a[low] = a[high];
        while (low < high && a[low] <= temp) {
            low++;
        }
        a[high] = a[low];
    }
    a[low] = temp;
    return low;
}

void QuickSortCore(int a[], int low, int high) {
    if (low < high) {
        int pivotpos = Partition(a, low, high);
        QuickSortCore(a, low, pivotpos - 1);
        QuickSortCore(a, pivotpos + 1, high);
    }
}

void QuickSort(int a[], int len) {
    QuickSortCore(a, 0, len - 1);
}

void GetMinAbs(int* a, int len, int* x, int* y) {
    int* b = (int*)malloc(sizeof(int) * len);
    for (int i = 0; i < len; i++) {
        b[i] = a[i];
    }
    QuickSort(b, len);
    int* c = (int*)malloc(sizeof(int) * (len - 1));
    for (int i = 0; i < len - 1; i++) {
        c[i] = b[i + 1] - b[i];
    }
    int p = 0, min = c[0];
    for (int i = 0; i < len - 1; i++) {
        if (c[i] < min) {
            min = c[i];
            p = i;
        }
    }
    *x = b[p];
    *y = b[p + 1];
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
        if (len > 1) {
            int x, y;
            GetMinAbs(array, len, &x, &y);
            printf("相距最近的元素是：%d和%d\n\n", x, y);
        }
    }
    return 0;
}
