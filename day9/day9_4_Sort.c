//
//  day9_4_Sort.c
//  day9_4_Sort
//
//  Created by 雨轩 on 2022/1/6.
//

//  完成冒泡排序，选择排序，插入排序，快速排序
//  手写一遍，加深印象

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SWAP(a,b) {int tmp; tmp = a; a = b; b = tmp;}

const int len = 100;

void BubbleSort(int *arr, int len) {
    for(int i = 0; i < len; i++) {
        for(int j = i + 1; j < len; j++) {
            if(arr[j] < arr[i]) {
                SWAP(arr[j], arr[i]);
            }
        }
    }
}

void SelectSort(int *arr, int len) {
    for(int i = 0; i < len; i++) {
        int temp = i;
        for(int j = i + 1; j < len; j++) {
            if(arr[j] < arr[temp]) {
                temp = j;
            }
        }
        SWAP(arr[i], arr[temp]);
    }
}

void print(int *arr, int len) {
    for(int i = 0; i < len; i++) {
        if(0 == i % 10) {
            printf("\n");
        }
        printf("%6d", arr[i]);
    }
    printf("\n");
}

void Insert(int *arr, int len, int data, int location) {
    for (; len > location; len--) {
        arr[len] = arr[len - 1];
    }
    arr[location] = data;
}

int SearchBin(int *arr, int len, int data) {
    int low = 0, high = len - 1;
    int mid = (low + high) / 2;
    while(low <= high) {    //二分法查找data应插入位置
        mid = (low + high) / 2;
        if(arr[mid] > data) {
            high = mid - 1;
        } else {    //当a[mid]==data时应当使low指针上移,以保证算法稳定性
            low = mid + 1;
        }
    }
    return low; //data应当插入到low与high之间
}

void InsertSort(int *arr, int len) {
    for(int i = 0; i < len; i++) {
        Insert(arr, i, arr[i], SearchBin(arr, i, arr[i]));
    }
}

int Partition(int *arr, int low, int high) {
    int i, k;
    for (i = low, k = low; i < high; i++) {
        if (arr[i] < arr[high]) {
            SWAP(arr[i], arr[k]);
            k++;
        }
    }
    SWAP(arr[k], arr[high]);
    return k;
}

void QuickSortCore(int *arr, int low, int high) {
    int pivot;
    if (low < high)
    {
        pivot = Partition(arr, low, high);
        QuickSortCore(arr, low, pivot - 1);
        QuickSortCore(arr, pivot + 1, high);
    }
}

void QuickSort(int *arr, int len) {
    QuickSortCore(arr, 0, len - 1);
}



int main(int argc, const char * argv[]) {
    int i;
    int *arr = (int*)malloc(len * sizeof(int));
    srand((unsigned int)time(NULL));
    for (i = 0; i < len; i++)
    {
        arr[i] = rand() % 10000;
    }
    print(arr, len);
//    BubbleSort(arr, len);
//    SelectSort(arr, len);
//    InsertSort(arr, len);
    QuickSort(arr, len);
    print(arr, len);
    return 0;
}
