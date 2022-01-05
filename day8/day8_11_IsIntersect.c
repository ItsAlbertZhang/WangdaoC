//
//  day8_11_IsIntersect.c
//  day8_11_IsIntersect
//
//  Created by 雨轩 on 2022/1/5.
//

//  判断两个链表是否相交,如果相交,计算交点.

#include "LinkedList.h"

node* IsIntersect(node *head1, node *head2) {
    node *ret = NULL;
    int len1 = 0, len2 = 0;
    node *p1 = head1, *p2 = head2;
    while(p1->next) {
        p1 = p1->next;
        len1++;
    }
    while(p2->next) {
        p2 = p2->next;
        len2++;
    }
    p1 = head1; p2 = head2;
    int cnt = 0;
    if(len1 > len2) {
        for(int i = 0; i< len1 - len2; i++) {
            p1 = p1->next;
        }
        cnt = len2;
    } else {
        for(int i = 0; i< len2 - len1; i++) {
            p2 = p2->next;
        }
        cnt = len1;
    }
    for(int i = 0; i < cnt; i++) {
        p1 = p1->next;
        p2 = p2->next;
        if(p1 == p2) {
            ret = p1;
            break;
        }
    }
    return ret;
}

int main(int argc, const char * argv[]) {
    char string[][10] = {"first", "second"};
    node *head1 = (node*)malloc(sizeof(node));
    head1->next = NULL;
    head1->val = 0;
    printf("Now create the %s linked list.\n", string[0]);
    LinkedList(head1);
    node *head2 = (node*)malloc(sizeof(node));
    head2->next = NULL;
    head2->val = 0;
    printf("Now create the %s linked list.\n", string[1]);
    LinkedList(head2);
    //构造交点
    node *p1 = head1, *p2 = head2;
    for(int cnt = 3; cnt > 0 && p1->next->next; cnt--) {
        p1 = p1->next;
    }
    while(p2->next) {
        p2 = p2->next;
    }
    p2->next = p1;  //此行代码为制造交点代码(将list2尾连接至list1的第cnt位),注释此行代码可以切换链表是否有交点
    node *ret = IsIntersect(head1, head2);
    if(ret) {
        printf("The value of their intersection is %d.\n", ret->val);
    } else {
        printf("They are not intersecting.\n");
    }
    return 0;
}
