//
//  day4_1_MyStr.c
//  day4_1_MyStr
//
//  Created by 雨轩 on 2021/12/31.
//

//  1. 实现 mystrcpy(); mystrcmp(); mystrcat(); mystrlen();

#include <stdio.h>
#define MAX_LENGTH 100

size_t mystrlen(const char *str) {
    int cnt = -1;
    while(cnt++, *str++);
    return cnt * sizeof(char);
}

int mystrcmp(const char *str1, const char *str2) {
    int ret = 0;
    while(*str1 * *str2 * !(ret = *str1++ - *str2++));
    return ret;
}

char* mystrcpy(char *to, const char *from) {
    char *ret = to;
    while(*to++ = *from++);
    return ret;
}

char* mystrcat(char *str1, const char *str2) {
    char *ret = str1;
    while(*str1++);
    str1--;
    while((*str1++ = *str2++));
    return ret;
}

int main(int argc, const char * argv[]) {
    char s1[MAX_LENGTH], s2[MAX_LENGTH];
    printf("please input s1:\n");
    scanf("%s", s1);
    printf("please input s2:\n");
    scanf("%s", s2);
    int uic = 0;
    printf("please input a number:\n");
    printf("Input 0 to input s1 and s2 again.\n");
    printf("Input 1 to get the length of s1.\n");
    printf("Input 2 to get the difference between s1 and s2.\n");
    printf("Input 3 to copy s1 to s2.\n");
    printf("Input 4 to copy s2 at the end of s1.\n");
    printf("Input 5 to print s1 and s2.\n");
    printf("use control D to exit.\n");
    while(scanf("%d", &uic) != EOF) {
        switch (uic) {
            case 0:
                printf("please input s1:\n");
                scanf("%s", s1);
                printf("please input s2:\n");
                scanf("%s", s2);
                break;
            case 1:
                printf("The len of s1 is %lu.\n", mystrlen(s1) / sizeof(char));
                break;
            case 2:
                printf("The dif of s1 and s2 is %d.\n", mystrcmp(s1, s2));
                break;
            case 3:
                mystrcpy(s2, s1);
                printf("s1 = %s\n", s1);
                printf("s2 = %s\n", s2);
                break;
            case 4:
                mystrcat(s1, s2);
                printf("s1 = %s\n", s1);
                printf("s2 = %s\n", s2);
                break;
            case 5:
                printf("s1 = %s\n", s1);
                printf("s2 = %s\n", s2);
                break;
            default:
                break;
        }
        printf("\n");
    }
    return 0;
}
