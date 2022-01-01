//
//  day3_7_Calender.c
//  day3_7_Calender
//
//  Created by 雨轩 on 2021/12/30.
//

//  7. 输入一个年份, 打印该年份的日历.

#include <stdio.h>
#include "day3_6&7_mydate.h"

void printline(int cnt) {
    for(int i = 0; i < cnt; i++) {
        printf("=");
    }
}

void print4space(int cnt) {
    for(int i = 0; i < cnt; i++) {
        printf("    ");
    }
}

void printbeg(void) {
    printf("[ ");
}

void printend(void) {
    printf(" ]\n");
}

int tonewyear(date d) {
    int day = d.day;
    int disleap = isleap(d.year);
    for(int i = d.month - 1; i > 0; i--) {
        if(disleap) {
            day += leap[i];
        } else {
            day += common[i];
        }
    }
    return day;
}

int distance(date a, date b) {
    int daya = tonewyear(a);
    int dayb = tonewyear(b);
    int leapcnt = leapcntto1(b.year) - leapcntto1(a.year);
    int day = (b.year - a.year) * 365 + leapcnt;
    day = day - daya + dayb;
    return day;
}

int getweek(int year, int month, int day) {
    //公元1949年10月1日星期六
    date a, d;
    d.year = year; d.month = month; d.day = day;
    a.year = 1949; a.month = 10; a.day = 1;
    int week = (distance(a, d) + 6) % 7;
    return week;
}

void printparag(int year, int parag) {
    int lowmon = parag, highmon = parag + 6;
    //每段第一行
    printbeg();
    printf(" %2d  SUN MON TUE WED THU FRI SAT", lowmon);
    print4space(1);
    printf(" %2d  SUN MON TUE WED THU FRI SAT", highmon);
    printend();
    //正文
    int lowday = 1, highday = 1;
    int lowweek = getweek(year, lowmon, lowday);
    int highweek = getweek(year, highmon, highday);
    int lowdaymax = common[lowmon], highdaymax = common[highmon];
    if(lowmon == 2) {
        if(isleap(year)) {
            lowdaymax = 29;
        }
    }
    //初始化回退
    while(lowweek != 0) {
        lowweek--;  lowday--;
    }
    while(highweek != 0) {
        highweek--; highday--;
    }
    //开始输出,6行
    for(int i = 0; i < 6; i++) {
        printbeg();
        print4space(1);
        while(lowweek != 7) {
            if(lowday > 0 && lowday <= lowdaymax) {
                printf("%4d", lowday);
            } else {
                print4space(1);
            }
            lowday++;   lowweek++;
        }
        lowweek = 0;
        print4space(2);
        while(highweek != 7) {
            if(highday > 0 && highday <= highdaymax) {
                printf("%4d", highday);
            } else {
                print4space(1);
            }
            highday++;   highweek++;
        }
        highweek = 0;
        printend();
    }
}

void Calender(int year) {
    //17*4+4 = 72列
    //标题25列,(72-4-25)/2 = 22
    //打印标题
    printf("[");
    printline(22);
    printf("The Calender of Year %4d ", year);
    printline(22);
    printf("]\n");
    //从1月到6月,以parag月与parag+6月为一段输出
    for(int parag = 1; parag < 7; parag++) {
        printparag(year, parag);
    }
    //打印结尾
    printf("[");
    printline(70);
    printf("]\n");
}

int main(int argc, const char * argv[]) {
    int year;
    printf("Please input the year whose you want to know:");
    scanf("%d", &year);
    printf("\n");
    Calender(year);
    return 0;
}

