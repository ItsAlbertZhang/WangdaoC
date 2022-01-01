//
//  day5_2_SpaceTo%020.c
//  day5_2_SpaceTo%020
//
//  Created by 雨轩 on 2022/1/1.
//

//  2. 将字符串中的空格替换成"%020".
/*
    考虑快慢针解法.快慢针从字符串首开始遍历.
    当遇到空格时快针走四步,慢针走一步.其他情况下快慢针均走一步.
    慢针走至字符串结尾时,快慢针同时向前回退,当慢针遇到空格时快针回退并依次填入%020.
    当快慢针重合时说明前面已无空格.此时可以结束并返回.
    时间复杂度为O(n).
 */

#include <stdio.h>
#define MAX_LENGTH 100

char* SpaceTo020(char *s) {
    char *p1 = s, *p2 = s;
    while(*p1) {
        if(*p1 == ' ') {
            p2 += 3;
        }
        p1++; p2++;
    }
    *p2 = 0;
    p1--; p2--;
    while(p1 != p2) {
        if(*p1 != ' ') {
            *p2 = *p1;
            p2--; p1--;
        } else {
            p2 -= 3;
            p2[0] = '%';
            p2[1] = p2[3] = '0';
            p2[2] = '2';
            p2--; p1--;
        }
    }
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
    while(mygets(s)) {
        //use mygets function so that the compiler does not generate warnings.
        printf("%s\n", SpaceTo020(s));
    }
}
