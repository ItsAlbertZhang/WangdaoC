//
//  day5_5_DelRepSpace.c
//  day5_5_DelRepSpace
//
//  Created by 雨轩 on 2022/1/2.
//

//  5. 将字符串中的连续空格替换为一个空格.
/*
    和第2,3题一样的思路,快慢针可解.
    时间复杂度为O(n).
 */

#include <stdio.h>
#define MAX_LENGTH 100

char* DelRepSpace(char* s) {
    char *p1 = s, *p2 = s + 1;
    while(*p2) {
        if(*p2 != ' ' || *p1 != ' ') {
            *++p1 = *p2++;
        } else {
            p2++;
        }
    }
    *++p1 = 0;
    return s;
}

char* mygets(char* str) {
    rewind(stdin);
    char *ret = str;
    int cnt = -1;
    while((void)(cnt++), (*str = getchar()) != EOF && *str++ != '\n');
    *--str = 0;
    if(cnt) return ret;
    return NULL;
}

int main(int argc, const char * argv[]) {
    char s[MAX_LENGTH];
    printf("Please input.\n");
    mygets(s);
    //use mygets function so that the compiler does not generate warnings.
    printf("%s\n", DelRepSpace(s));
    return 0;
}
