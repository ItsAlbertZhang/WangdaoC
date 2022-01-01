//
//  day5_1_SeparateLetter&Number.c
//  day5_1_SeparateLetter&Number
//
//  Created by 雨轩 on 2022/1/1.
//

//  1. 将包含字符数字的字符串分开, 使得分开后的字符串前一部分是数字后一部分是字母. 例如"h1ell2o3" -> "123hello".
/*
    考虑使用归并排序算法的思想解决.
    将数字全部视为(如0),字母全部视为一个较大值(如1).在保证排序算法的稳定性的前提下,对数组进行排序即可.
    此解法时间复杂度为O(log2n),空间复杂度为O(n).
    此外,还可以用选择排序的思想解决该问题.此时时间复杂度变为O(n^2),空间复杂度变为O(1).
*/

#include <stdio.h>
#define MAX_LENGTH 100

int isNumber(char c) {
    return c >= '0' && c <= '9';
}

void MergeLAN(char *a, int len) {
    //Merge Letter And Number
    char c[len];
    for(int i = 0; i < len; i++) {
        c[i] = a[i];
    }
    int i = 0, j = 0, k = (len + 1) / 2;
    while(j < (len + 1) / 2 && k < len) {
        if(isNumber(c[j]) || !isNumber(c[k])) {
            a[i++] = c[j++];
        } else {
            a[i++] = c[k++];
        }
    }
    while(j < (len + 1) / 2)  a[i++] = c[j++];
    while(k < len)      a[i++] = c[k++];
}

void MergeSortLAN(char *a, int low, int high) {
    //Merge Sort Letter And Number recursively
    if(low < high) {
        int mid = (low + high) / 2;
        MergeSortLAN(a, low, mid);
        MergeSortLAN(a, mid + 1, high);
        MergeLAN(a + low, high - low + 1);
    }
}

char* SeparateLetterAndNumber(char *s) {
    int len = -1;
    while(s[++len]);
    MergeSortLAN(s, 0, --len);
    return s;
}

int main(int argc, const char * argv[]) {
    char s[MAX_LENGTH];
    while(scanf("%s", s) != EOF) {
        printf("%s\n", SeparateLetterAndNumber(s));
    }
}
