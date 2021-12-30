//
//  2_PrintGraphics.c
//  2_PrintGraphics
//
//  Created by 雨轩 on 2021/12/29.
//

#include <stdio.h>
#define SIDE_LENGTH 5
#define CYCLE_TIME  1
#define HEART_BEGIN 2
#define HEART_MAX   10

void SolidDiamond(void) {
    int CycleTime = CYCLE_TIME * 2;
    int step = 1, end = 1;
    int i = 1;
    while (CycleTime > 0 || end >= 0) {
        for (int space = SIDE_LENGTH - i; space > 0; space--) {
            printf(" ");
        }
        printf("*");
        for (int star = i - 1; star > 0; star--) {
            printf(" *");
        }
        printf("\n");
        i += step;
        if (i == 1 || i == SIDE_LENGTH) {
            step = 0 - step;
            CycleTime--;
        }
        if (CycleTime == 0) {
            end--;
        }
    }
}

void HollowDiamond(void) {
    int CycleTime = CYCLE_TIME * 2;
    int step = 1, end = 1;
    int i = 1;
    while (CycleTime > 0 || end >= 0) {
        for (int space1 = SIDE_LENGTH - i; space1 > 0; space1--) {
            printf(" ");
        }
        if (i == 1) {
            printf("*");
        } else {
            printf("*");
            for (int space2 = (i - 1) * 2 - 1; space2 > 0; space2--) {
                printf(" ");
            }
            printf("*");
        }
        printf("\n");
        i += step;
        if (i == 1 || i == SIDE_LENGTH) {
            step = 0 - step;
            CycleTime--;
        }
        if (CycleTime == 0) {
            end--;
        }
    }
}

void Heart(void) {
    //每2列视为1组，以行号奇偶性区分星号在前或空格在前
    //做到这一题才想到这个方法，上面两个菱形应该也适用此方法

    //上半部分
    int up = HEART_MAX / 2 - HEART_BEGIN;
    int parity = (up + 1) % 2;
    for (int line = 0; line < up; line++) {
        for (int space1 = (up - line) / 2; space1 > 0; space1--) {
            printf("  ");
        }
        for (int star = line + HEART_BEGIN; star > 0; star--) {
            if (parity) {
                printf("* ");
            } else {
                printf(" *");
            }
        }
        for (int space2 = up - line; space2 > 0; space2--) {
            printf("  ");
        }
        for (int star = line + HEART_BEGIN; star > 0; star--) {
            if (parity) {
                printf("* ");
            } else {
                printf(" *");
            }
        }
        printf("\n");
        parity = (parity + 1) % 2;
    }

    //下半部分
    for (int line = 0; line < HEART_MAX; line++) {
        for (int space = line / 2; space > 0; space--) {
            printf("  ");
        }
        for (int star = HEART_MAX - line; star > 0; star--) {
            if (parity) {
                printf("* ");
            } else {
                printf(" *");
            }
        }
        printf("\n");
        parity = (parity + 1) % 2;
    }
}

int main(int argc, const char * argv[]) {
    printf("This is a Solid Diamond:\n\n");
    SolidDiamond();
    printf("\nThis is a Hollow Diamond:\n\n");
    HollowDiamond();
    printf("\nThis is a Heart:\n\n");
    Heart();
    return 0;
}
