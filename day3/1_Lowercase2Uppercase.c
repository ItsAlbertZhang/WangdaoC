//
//  1_Lowercase2Uppercase.c
//  1_Lowercase2Uppercase
//
//  Created by 雨轩 on 2021/12/30.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    char c = 'a';
    while ((void)(rewind(stdin)), scanf("%c", &c) != EOF) {
        printf("%c\n", c - 32);
    }
    return 0;
}
