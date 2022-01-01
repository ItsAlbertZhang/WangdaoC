//
//  day3_1_Lowercase2Uppercase.c
//  day3_1_Lowercase2Uppercase
//
//  Created by 雨轩 on 2021/12/30.
//

//  1. 从键盘上输入字符, 将小写字母转换成大写字母. 输入 "ctl + z" 结束.

#include <stdio.h>

int main(int argc, const char * argv[]) {
    char c = 'a';
    while ((void)(rewind(stdin)), scanf("%c", &c) != EOF) {
        printf("%c\n", c - 32);
    }
    return 0;
}

