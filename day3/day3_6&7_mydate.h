//
//  day3_6&7_mydate.h
//  day3
//
//  Created by 雨轩 on 2021/12/30.
//

#ifndef _6_7_mydate_h
#define _6_7_mydate_h

typedef struct _date {
    int year;
    int month;
    int day;
} date;

extern const int leap[13];
extern const int common[13];

int isleap(int year);
int leapcntto1(int year);

#endif /* _6_7_mydate_h */

