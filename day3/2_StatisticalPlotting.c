//
//  2_StatisticalPlotting.c
//  2_StatisticalPlotting
//
//  Created by 雨轩 on 2021/12/30.
//

#include <stdio.h>
#define MAX_LENGTH 100

void StatisticalPlotting(char *s, int len) {
    int stat[3];
    for(int i = 0; i < 3; i++) {
        stat[i] = 0;
    }
    //获取字母、数字、其他字符的个数
    for(int i = 0; i < len; i++) {
        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')) {
            stat[0] += 1;
        } else if (s[i] >= '0' && s[i] <= '9') {
            stat[1] += 1;
        } else {
            stat[2] += 1;
        }
    }
    //打印
    int cnt = 0, restcnt = 3, cnti = 0;
    int plotcnt[3], plottype[3];
    for(int i = 0; i < 3; i++) {
        plotcnt[i] = 0;
        plottype[i] = 0;
    }
    while(restcnt > 0) {
        for(int i = 0; i < 3; i++) {
            if(stat[i] > 0) {
                stat[i] -= 1;
            }
            if(stat[i] == 0) {
                stat[i] -= 1;
                plotcnt[cnti] = cnt + 1;
                plottype[cnti++] = i;
                restcnt--;
            }
        }
        cnt++;
    }
    //plotcnt是一个升序数组,plottype记录对应的类型
    int max = plotcnt[2];
    for(int line = 0; line <= max; line++) {
        for(int i = 2; i >= 0; i--) {
            if(max - plotcnt[i] == line) {
                printf("  %d  \t", plotcnt[i]);
            } else if(max - plotcnt[i] < line) {
                printf("*****\t");
            } else {
                printf("     \t");
            }
        }
        printf("\n");
    }
    for(int i = 2; i >= 0; i--) {
        if(plottype[i] == 0) {
            printf(" alp \t");
        } else if(plottype[i] == 1) {
            printf(" num \t");
        } else if(plottype[i] == 2) {
            printf(" oth \t");
        }
    }
}

int main(int argc, const char * argv[]) {
    char s[MAX_LENGTH];
    char temp = 0;
    int len = 0;
    for(; len < MAX_LENGTH; len++) {
        scanf("%c", &temp);
        if(temp != '\n') {
            s[len] = temp;
        } else {
            break;
        }
    }
    StatisticalPlotting(s, len);
    return 0;
}

