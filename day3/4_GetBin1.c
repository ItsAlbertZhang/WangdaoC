//
//  4_GetBin1.c
//  4_GetBin1
//
//  Created by 雨轩 on 2021/12/30.
//

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
