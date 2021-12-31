//
//  4_ReverseStr.c
//  4_ReverseStr
//
//  Created by 雨轩 on 2021/12/31.
//

#include <stdio.h>
#define MAX_LENGTH 100

void reverse(char *beg, char *end) {
    while(beg < end) {
        *beg ^= *end;
        *end ^= *beg;
        *beg ^= *end;
        beg++; end--;
    }
}

int main(int argc, const char * argv[]) {
    char s[MAX_LENGTH];
    printf("Please input.\n");
    char *c = s;
    while((*c++ = getchar()) != '\n');
    *--c = 0;
    //reverse all
    char *p = s;
    while(*p++);
    p -= 2;
    reverse(s, p);
    //reverse every word
    char *beg, *end = s - 1;
    do {
        beg = end;
        while((*++beg == ' ') && *beg);
        end = beg - 1;
        while((*++end != ' ') && *end);
        end--;
        reverse(beg, end);
    } while(*beg);
    printf("%s\n", s);
    return 0;
}
