//
//  day5_4_DelRepElem.c
//  day5_4_DelRepElem
//
//  Created by 雨轩 on 2022/1/1.
//

//  4.删除数组中重复的元素.
/*
    考虑数组有序的情况(题中给出的示例亦为有序).依旧使用快慢针思想解决本题,时间复杂度为o(n).
    下面考虑数组无序的情况.
    在数组无序的情况下,暴力解法的时间复杂度为O(n^2)。要想降低时间复杂度,可以采用以下方案:
    1)先排序,将问题化为数组有序情况.该方案的时间复杂度为O(log2n),空间复杂度为O(1).
    2)使用非比较的方案进行处理,这种方案的复杂度受数据范围或元素个数影响.
        当元素数据范围较小时,采用位图存储后按位或的方案进行处理.
        该方案的时间复杂度为O(n),空间复杂度为O(max-min).
        当元素数量较少时,采用哈希表存储的方案进行处理.
        该方案对于单个元素最优时间复杂度为O(1),最差时间复杂度为O(n).
        考虑到n个元素,其时间复杂度在O(n)到O(n^2)之间,平均时间复杂度为O(n).
        空间复杂度则为O(1).
    这里先给出数组有序情况下的解法,无序的解法后续再补.
 */

#include <stdio.h>
#include <stdlib.h>

int* DelRepElemInIncrementalOrderedArr(int *arr, int len, int *retlen) {
    int max = arr[0];
    *retlen = 0;
    for(int i = 0; i < len; i++) {
        if(arr[i] > max) {
            (*retlen)++;  max = arr[i];
        }
    }
    int *ret = (int*)malloc(sizeof(int) * *retlen);
    ret[0] = arr[0];
    int p = 1;
    for(int i = 0; i < len; i++) {
        if(arr[i] > ret[p - 1]) {
            ret[p++] = arr[i];
        }
    }
    return ret;
}

int main(int argc, const char * argv[]) {
    int len = 0;
    printf("Please input the length of array.\n");
    scanf("%d", &len);
    int arr[len];
    printf("Please input every elements, and use space or \\n to separate them.\n");
    for(int i = 0; i < len; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Before:\n");
    for(int i = 0; i < len; i++) {
        printf("%6d", arr[i]);
    }
    printf("\n");
    int reslen = 0;
    int *res = DelRepElemInIncrementalOrderedArr(arr, len, &reslen);
    printf("Result:\n");
    for(int i = 0; i < reslen; i++) {
        printf("%6d", res[i]);
    }
    printf("\n");
    return 0;
}
