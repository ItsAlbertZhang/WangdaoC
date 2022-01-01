//
//  day5_3_DelLetter.c
//  day5_3_DelLetter
//
//  Created by 雨轩 on 2022/1/1.
//

//  3.删除字符串中指定的字符.
/*
    和上题一样的思路,快慢针可解.
    时间复杂度为O(n).
 */

#include <stdio.h>
#define MAX_LENGTH 100

char* DelLetter(char *s, char c) {
    char *p1 = s, *p2 = s;
    while(*p2) {
        if(*p2 != c) {
            *p1 = *p2;
            p1++;
        }
        p2++;
    }
    *p1 = 0;
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
    printf("Please input. Press Enter key to end, or press control D to exit.\n");
    while(mygets(s)) {
        printf("Please input the letter you want to delete.\n");
        char c = getchar();
        //use mygets function so that the compiler does not generate warnings.
        printf("%s\n", DelLetter(s, c));
        printf("\nPlease input. Press Enter key to end, or press control D to exit.\n");
    }
}
