//
//  day2_1_PrintMultiplicationTable.c
//  day2_1_PrintMultiplicationTable
//
//  Created by 雨轩 on 2021/12/29.
//

//  1. 打印九九乘法表.

#include <stdio.h>

int main(int argc, const char * argv[]) {
    for (int i = 1; i < 10; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d*%d=%2d\t", i, j, i * j);
        }
        printf("\n");
    }
    return 0;
}
