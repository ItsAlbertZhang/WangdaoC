//
//  day2_3_GetPublicElements.c
//  day2_3_GetPublicElements
//
//  Created by 雨轩 on 2021/12/29.
//

//  3. 求 n 个有序数组的公共元素.

#include <stdio.h>
#include <stdlib.h>

typedef struct ArrayOfArrayPoint {
    int* point;
    int len;
} aoa;

typedef struct _node {
    int val;
    struct _node* next;
} node;

void NodeInsert(node* head, int val) {
    node* lastnode = head;
    while (lastnode->next) {
        lastnode = lastnode->next;
    }
    node* newnode = (node*)malloc(sizeof(node));
    newnode->next = NULL;
    newnode->val = val;
    lastnode->next = newnode;
}

void PrintList(node* head) {
    node* thisnode = head->next;
    while (thisnode) {
        printf("%d\t", thisnode->val);
        thisnode = thisnode->next;
    }
    printf("\n");
}

int GetMin(int* a, int len, int *equal) {
    int min = a[0];
    int cnt = 0, ret = 0;
    for (int i = 0; i < len; i++) {
        if (a[i] < min) {
            min = a[i];
            ret = i;
            cnt++;
        } else if (a[i] > min) {
            cnt++;
        }
    }
    if (cnt == 0) {
        *equal = 1;
    } else {
        *equal = 0;
    }
    return ret;
}

node* GetThePublicElem(aoa* p, int lenofaoa) {
    int *aval = (int*)malloc(sizeof(int) * lenofaoa);
    int *apoint = (int*)malloc(sizeof(int) * lenofaoa);
    /*int aval[lenofaoa];
    int apoint[lenofaoa];*/
    for (int i = 0; i < lenofaoa; i++) {
        apoint[i] = 0;
        aval[i] = p[i].point[0];
    }
    int equal = 0;
    node* head = (node*)malloc(sizeof(node));
    head->next = NULL;
    head->val = 0;
    int end = 1;
    while (end) {
        int minp = GetMin(aval, lenofaoa, &equal);
        if (equal == 0) {
            if (apoint[minp] < p[minp].len - 1) {
                apoint[minp] += 1;
                aval[minp] = p[minp].point[apoint[minp]];
            } else {
                end = 0;
            }
        } else {
            NodeInsert(head, aval[minp]);
            for (int i = 0; i < lenofaoa; i++) {
                if (apoint[i] < p[i].len - 1) {
                    apoint[i] += 1;
                    aval[i] = p[i].point[apoint[i]];
                } else {
                    end = 0;
                }
            }
        }
    }
    return head;
}

int main(int argc, const char * argv[]) {
//    int a[] = { 2, 4, 6, 7, 8, 23, 100, };
//    int b[] = { 2, 3, 5, 7, 11, 13, 23, 101, };
//    int c[] = { 1, 2, 3, 5, 7, 9, 11, 13, 23, 102, };
//    int d[] = { 2, 7, 11, 23, };
//    int e[] = { 3, 7, 11, };
//    while (1) {
//        printf("数组1：\t");
//        for(int i = 0; i < sizeof(a) / sizeof(int); )
//        int lenofaoa = 0;
//        scanf("%d", &lenofaoa);
//        aoa* array = (aoa*)malloc(sizeof(aoa) * lenofaoa);
//        //aoa array[lenofaoa];
//        for (int i = 0; i < lenofaoa; i++) {
//            int s;
//            scanf("%d", &s);
//            switch (s)
//            {
//            case 1:
//                array[i].len = sizeof(a) / sizeof(int);
//                array[i].point = a;
//                break;
//            case 2:
//                array[i].len = sizeof(b) / sizeof(int);
//                array[i].point = b;
//                break;
//            case 3:
//                array[i].len = sizeof(c) / sizeof(int);
//                array[i].point = c;
//                break;
//            case 4:
//                array[i].len = sizeof(d) / sizeof(int);
//                array[i].point = d;
//                break;
//            case 5:
//                array[i].len = sizeof(e) / sizeof(int);
//                array[i].point = e;
//                break;
//            }
//        }
//        PrintList(GetThePublicElem(array, lenofaoa));
//    }
    int lenofaoa = 0;
    printf("请输入数组个数：");
    scanf("%d", &lenofaoa);
    aoa* array = (aoa*)malloc(sizeof(aoa) * lenofaoa);
    for (int i = 0; i < lenofaoa; i++) {
        printf("请输入第%d个数组的长度：", i + 1);
        scanf("%d", &array[i].len);
        array[i].point = (int*)malloc(sizeof(int) * array[i].len);
        printf("请依次输入第%d个数组内的元素，以空格或回车隔开：\n", i + 1);
        for (int j = 0; j < array[i].len; j++) {
            scanf("%d", &array[i].point[j]);
        }
    }
    printf("\n这些数组内重复的元素有：\n");
    PrintList(GetThePublicElem(array, lenofaoa));
    return 0;
}
//test
//4
//7
//2 4 6 7 8 23 100
//8
//2 3 5 7 11 13 23 101
//10
//1 2 3 5 7 9 11 13 23 102
//4
//2 7 11 23
