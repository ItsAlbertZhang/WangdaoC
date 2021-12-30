//
//  8_GetRepeated.c
//  8_GetRepeated
//
//  Created by 雨轩 on 2021/12/29.
//

#include <stdio.h>
#define NUM 233

int GetRepeated(int* a, int len) {
    int sum = 0, sumof1000 = 0;
    for (int i = 0; i < len; i++) {
        sum += a[i];
    }
    for (int i = 1; i <= 1000; i++) {
        sumof1000 += i;
    }
    return sum - sumof1000;
}

int main(int argc, const char * argv[]) {
    int a[1001];
    int cnt = 0;
    for (int i = 0; i < 1001; i++) {
        a[i] = i - cnt + 1;
        if (a[i] == NUM && cnt == 0) {
            cnt++;
        }
    }
    int res = GetRepeated(a, 1001);
    printf("这个重复的数是：%d\n", res);
    return 0;
}
