//
//  3_IncrementalConversion.c
//  3_IncrementalConversion
//
//  Created by 雨轩 on 2021/12/30.
//

#include <stdio.h>
#include <stdlib.h>
#define MAX_LENGTH 100

int str2num(char *s, int len, int inc) {
    int num = 0, t = 0;
    for(int i = 0; i < len; i++) {
        num *= inc;
        if(s[i] >= '0' && s[i] <= '9') {
            t = s[i] - '0';
        } else if(s[i] >= 'a' && s[i] <= 'f') {
            t = s[i] - 'a' + 10;
        } else if(s[i] >= 'A' && s[i] <= 'F') {
            t = s[i] - 'A' + 10;
        }
        num += t;
    }
    return num;
}

char* num2str(int num, int inc) {
    int a[MAX_LENGTH];
    int len = 0;
    for(int i = 0; num > 0; i++, num /= inc) {
        a[i] = num % inc;
        len++;
    }
    char *ret = (char*)malloc(sizeof(char) * MAX_LENGTH);
    for(int i = 0; i < len; i++) {
        ret[i] = a[len - i - 1];
        if(ret[i] < 10) {
            ret[i] += '0';
        } else {
            ret[i] += 'A' - 10;
        }
    }
    ret[len] = '\0';
    return ret;
}

void IncrementalConversion(char *s, int len, int ori, int tar) {
    int num = str2num(s, len, ori);
    printf("%s\n", num2str(num, tar));
}

int main(int argc, const char * argv[]) {
    char s[MAX_LENGTH];
    char temp = 0;
    int len = 0;
    printf("请输入任意进制的数字.\n");
    for(; len < MAX_LENGTH; len++) {
        scanf("%c", &temp);
        if((temp >= '0' && temp <= '9')||(temp >= 'a' && temp <= 'f')||(temp >= 'A' && temp <= 'F')) {
            s[len] = temp;
        } else {
            break;
        }
    }
    int ori = 10, tar = 10;
    printf("请依次输入原进制与目标进制,中间用空格或回车隔开.\n");
    scanf("%d %d", &ori, &tar);
    IncrementalConversion(s, len, ori, tar);
    return 0;
}
