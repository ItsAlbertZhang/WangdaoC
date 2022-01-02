//
//  day5_6_BigNumberAdd.c
//  day5_6_BigNumberAdd
//
//  Created by 雨轩 on 2022/1/2.
//

//  6. 实现两个大数的相加
/*
    使用字符串按位相加即可.
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX_LENGTH 100

void ReverseStr(char *s) {
    char *p = s;
    while(*++p);
    p--;
    while(s < p) {
        *s ^= *p;
        *p ^= *s;
        *s ^= *p;
        s++; p--;
    }
}

char* BigNumberAdd(char *s1, char *s2) {
    char *ret = (char*)malloc(sizeof(char) * MAX_LENGTH);
    char *p = ret;
    ReverseStr(s1);
    ReverseStr(s2);
    int temp = 0;
    while(*s1 && *s2) {
        *p = *s1 + *s2 - '0' + temp;
        temp = 0;
        if(*p > '9') {
            *p -= 10;
            temp = 1;
        }
        s1++;   s2++;   p++;
    }
    while(*s1) {
        *p = *s1 + temp;
        temp = 0;
        if(*p > '9') {
            *p -= 10;
            temp = 1;
        }
        s1++;   p++;
    }
    while(*s2) {
        *p = *s2 + temp;
        temp = 0;
        if(*p > '9') {
            *p -= 10;
            temp = 1;
        }
        s2++;   p++;
    }
    if(temp) {
        *p++ = '0' + temp;
    }
    *p = 0;
    ReverseStr(ret);
    return ret;
}

int main(int argc, const char * argv[]) {
    char s1[MAX_LENGTH], s2[MAX_LENGTH];
    printf("Please input 2 numbers, and use space or \\n to separate them.\n");
    scanf("%s", s1);
    scanf("%s", s2);
    printf("The sum is:\n%s\n", BigNumberAdd(s1, s2));
    return 0;
}
