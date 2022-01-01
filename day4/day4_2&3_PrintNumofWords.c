//
//  day4_2&3_PrintNumofWordsc
//  day4_2&3_PrintNumofWords
//
//  Created by 雨轩 on 2021/12/31.
//

//  2&3. 输入一行字符串(单词和若干空格), 输出该行单词(每个单词一行), 并输出该行单词的个数.

#include <stdio.h>
#define MAX_LENGTH 100


int main(int argc, const char * argv[]) {
    char s[MAX_LENGTH];
    printf("Please input.\n");
    char *c = s;
    while((*c++ = getchar()) != '\n');
    *--c = 0;
    char *p = s;
    int isspace = 1, cnt = 0;
    while(*p) {
        if(*p != ' ') {
            if(isspace) {
                cnt++;
                isspace = 0;
                printf("\n");
            }
            printf("%c", *p);
        } else {
            isspace = 1;
        }
        p++;
    }
    printf("\n\n%d\n", cnt);
    return 0;
}
