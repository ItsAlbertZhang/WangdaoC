//
//  _6&7_mydate.c
//  6_CalcDate
//
//  Created by 雨轩 on 2021/12/30.
//

#include <stdio.h>

const int leap[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int common[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int isleap(int year) {
    int ret = 0;
    if(year % 100 == 0) {
        if(year % 400 == 0) {
            ret = 1;
        }
    } else if(year % 4 == 0) {
        ret = 1;
    }
    return ret;
}

int leapcntto1(int year) {
    int ret = (year - 1) / 4;
    ret -= year / 100;
    ret += year / 400;
    return ret;
}


