//
//  day5_7_GetBig1AndBig2.c
//  day5_7_GetBig1AndBig2
//
//  Created by 雨轩 on 2022/1/2.
//

//  7. 求一个字符串数组的最大值和次大值.(函数声明已给出)
/*
    三指针遍历即可.
 */

#include <stdio.h>
#define MAX_LENGTH 100

//void big(char *arr, int size, char** big1, char** big2) {
void big(char *arr, char** big1, char** big2) {
    char *p1 = arr, *p2 = arr, *p = arr;
//    for(int i = 0; i < size; i++) {
    while(*++p) {
        if(*p > *p1) {
            p2 = p1;
            p1 = p;
        } else if(*p > *p2) {
            p2 = p;
        }
    }
    *big1 = p1;
    *big2 = p2;
}

int main(int argc, const char * argv[]) {
    char s[MAX_LENGTH];
    printf("Please input a string.\n");
    scanf("%s", s);
    char *big1, *big2;
//    big(s, size, &big1, &big2);
    big(s, &big1, &big2);
    printf("The first biggest is %c, and the second biggest is %c.\n", *big1, *big2);
    return 0;
}
