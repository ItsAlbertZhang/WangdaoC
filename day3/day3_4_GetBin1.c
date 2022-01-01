//
//  day3_4_GetBin1.c
//  day3_4_GetBin1
//
//  Created by 雨轩 on 2021/12/30.
//

//  4. 统计一个整数对应的二进制数的 1 的个数. 输入一个整数(可正可负), 输出该整数的二进制包含1的个数, "ctl+ z" 结束.

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int num = 0;
    while(scanf("%d", &num) != EOF) {
        int cnt = 0, a = 1;
        for(int i = 0; i < sizeof(int) * 8; i++) {
            if(num & a) {
                cnt++;
            }
            a = a<<1;
        }
        printf("%d\n", cnt);
    }
    return 0;
}

