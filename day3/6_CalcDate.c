//
//  6_CalcDate.c
//  6_CalcDate
//
//  Created by 雨轩 on 2021/12/30.
//

#include <stdio.h>
#include "_6&7_mydate.h"

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

int getweek(date d) {
    //公元1949年10月1日星期六
    date a;
    a.year = 1949; a.month = 10; a.day = 1;
    int week = (distance(a, d) + 6) % 7;
    return week;
}

date afterdays(date a, int day) {
    day += tonewyear(a);
    a.month = 1; a.day = 1;
    date ret;
    ret.year = a.year; ret.month = 1; ret.day = 1;
    while(day > 365 + isleap(ret.year)) {
        day -= 365 + isleap(ret.year);
        ret.year += 1;
    }
    int retisleap = isleap(ret.year);
    if(retisleap) {
        while(day > leap[ret.month]) {
            day -= leap[ret.month];
            ret.month += 1;
        }
    } else {
        while(day > common[ret.month]) {
            day -= common[ret.month];
            ret.month += 1;
        }
    }
    ret.day = day;
    return ret;
}

void calendar(int year, int month) {
    date d;
    d.year = year; d.month = month; d.day = 1;
    int dweek = getweek(d);
    int disleap = isleap(d.year);
    int dmonthdays;
    if(disleap) {
        dmonthdays = leap[d.month];
    } else {
        dmonthdays = common[d.month];
    }
    printf(" MON TUE WED THU FRI SAT SUN\n");
    for(int i = 1; i < dweek; i++) {
        printf("    ");
    }
    for(int i = 1, cnt = dweek; i < dmonthdays; i++, cnt++) {
        printf("%4d", i);
        if(cnt % 7 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

int main(int argc, const char * argv[]) {
    printf("请输入以下数字使用相应功能:\n");
    printf("1.计算某个日期是当年的第几天.\n");
    printf("2.计算两个日期的差.\n");
    printf("3.输入日期计算当天是星期几.\n");
    printf("4.输入一个日期并计算指定天数后的日期.\n");
    printf("5.输入一个年份和月份,输出该月份的日历.\n");
    int i = 0, x = 0;
    date a, b;
    while(scanf("%d", &i) != EOF) {
        switch (i) {
            case 1:
                printf("请依次输入年月日,以空格或回车隔开.\n");
                scanf("%d %d %d", &a.year, &a.month, &a.day);
                printf("这个日期是当年的第%d天.\n", tonewyear(a));
                break;
            case 2:
                printf("请依次输入两个日期的年月日,以空格或回车隔开.\n");
                scanf("%d %d %d", &a.year, &a.month, &a.day);
                scanf("%d %d %d", &b.year, &b.month, &b.day);
                printf("这两个日期相距%d天.\n", distance(a, b));
                break;
            case 3:
                printf("请依次输入年月日,以空格或回车隔开.\n");
                scanf("%d %d %d", &a.year, &a.month, &a.day);
                printf("这个日期是星期%d.\n", getweek(a));
                break;
            case 4:
                printf("请依次输入年月日与指定间隔天数,以空格或回车隔开.\n");
                scanf("%d %d %d %d", &a.year, &a.month, &a.day, &x);
                b = afterdays(a, x);
                printf("%d天后的日期是%d年%d月%d日.\n", x, b.year, b.month, b.day);
                break;
            case 5:
                printf("请依次输入年和月,以空格或回车隔开.\n");
                scanf("%d %d", &a.year, &a.month);
                calendar(a.year, a.month);
                break;
            default:
                break;
        }
    }
    return 0;
}

