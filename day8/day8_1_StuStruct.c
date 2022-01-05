//
//  day8_1_StuStruct.c
//  day8_1_StuStruct
//
//  Created by 雨轩 on 2022/1/5.
//

//  有一个学生结构体,其数据成员有:学号,姓名,3门课程.
//  从键盘上输入5个学生的信息.要求输出:
//  1.按照学号递增输出全部学生信息，每个学生的信息一行。
//  (格式: 学号 姓名 分数1 分数2 分数3 总分)
//  2.输出每门课程最高分的学生的信息
//  3.输出每门课程的平均分
//  4.按照总分输出学生排名


#include <stdio.h>

const int len = 5;

typedef struct _Student {
    int ID;
    char name[10];
    double score[3];
    double total;
} stu;

void swap(stu **a, stu **b) {
    stu *temp = *a;
    *a = *b;
    *b = temp;
}

void SortByID(stu **arr, int len) {
    //5个数,冒泡排序算了,就不写更复杂的了
    for(int i = 0; i < len; i++) {
        for(int j = i + 1; j < len; j++) {
            if((*arr[j]).ID < (*arr[i]).ID) {
                swap(&arr[j], &arr[i]);
            }
        }
    }
}
void SortByScore(stu **arr, int len, int subject) {
    //5个数,冒泡排序算了,就不写更复杂的了
    for(int i = 0; i < len; i++) {
        for(int j = i + 1; j < len; j++) {
            if((*arr[j]).score[subject] > (*arr[i]).score[subject]) {
                swap(&arr[j], &arr[i]);
            }
        }
    }
}
void SortByTotal(stu **arr, int len) {
    //5个数,冒泡排序算了,就不写更复杂的了
    for(int i = 0; i < len; i++) {
        for(int j = i + 1; j < len; j++) {
            if((*arr[j]).total > (*arr[i]).total) {
                swap(&arr[j], &arr[i]);
            }
        }
    }
}

void GetAvrScore(double *ret, stu **arr, int len) {
    for(int subject = 0; subject < 3; subject++) {
        ret[subject] = 0;
        for(int i = 0; i < len; i++) {
            ret[subject] += (*arr[i]).score[subject];
        }
        ret[subject] /= len;
    }
}

void PrintAll(stu **arr) {
    printf("ID   name      score1 score2 score3 total\n");
    for(int i = 0; i < len; i++) {
        printf("%-5d%-10s%-7.2lf%-7.2lf%-7.2lf%-7.2lf\n", (*arr[i]).ID, (*arr[i]).name, (*arr[i]).score[0], (*arr[i]).score[1], (*arr[i]).score[2], (*arr[i]).total);
    }
}

int main(int argc, const char * argv[]) {
    printf("Please input ID, name, score1, score2 and score3, and use space to separate them.\n");
    stu inf[len];
    for(int i = 0; i < len; i++) {
        printf("Please input the information of student %d.\n", i + 1);
        scanf("%d %s %lf %lf %lf", &(inf[i].ID), inf[i].name, &(inf[i].score[0]), &(inf[i].score[1]), &(inf[i].score[2]));
        inf[i].total = inf[i].score[0] + inf[i].score[1] + inf[i].score[2];
    }
    stu *arr[len];
    for(int i = 0; i < len; i++) {
        arr[i] = &inf[i];
    }
    SortByID(arr, len);
    printf("\nSort by ID:\n");
    PrintAll(arr);
    for(int i = 0; i < 3; i++) {
        SortByScore(arr, len, i);
        printf("\nSort by score%d:\n", i + 1);
        PrintAll(arr);
    }
    double avr[len];
    GetAvrScore(avr, arr, len);
    printf("\n");
    for(int i = 0; i < len; i++) {
        printf("The average score of subject %d is:%.2lf\n", i, avr[i]);
    }
    SortByTotal(arr, len);
    printf("\nSort by total score:\n");
    PrintAll(arr);
    return 0;
}

/*
测试用例:
1012 Lily 98.2 80.5 86.4
1008 James 86.5 77.7 65.4
1064 Snape 68.2 83.3 60.4
4396 Harry 95.2 91.0 70.5
4354 Hermione 98.6 99.2 96.3
*/
