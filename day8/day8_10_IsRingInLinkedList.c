//
//  day8_10_IsRingInLinkedList.c
//  day8_10_IsRingInLinkedList
//
//  Created by 雨轩 on 2022/1/5.
//

//  判断单链表是否有环.

#include "LinkedList.h"

int IsRingInLinkedList(node* head) {
    int ret = 0;
    node *pfast = head, *pslow = head;
    int isslowgo = 0;
    do {
        pfast = pfast->next;
        if(isslowgo) {
            pslow = pslow->next;
            isslowgo = 0;
        } else {
            isslowgo = 1;
        }
    } while(pfast->next && pfast != pslow);
    if(pfast == pslow) {
        ret = 1;
    }
    return ret;
}

int main(int argc, const char * argv[]) {
    node *head = (node*)malloc(sizeof(node));
    head->next = NULL;
    head->val = 0;
    printf("Now create the linked list.\n");
    LinkedList(head);
    //人工造环
    node *p1 = head, *p2 = head;
    for(int cnt = 3; cnt > 0 && p1->next->next; cnt--) {
        p1 = p1->next;
    }
    while(p2->next) {
        p2 = p2->next;
    }
    p2->next = p1;  //此行代码为造环代码,注释此行代码可以切换链表是否有环
    if(IsRingInLinkedList(head)) {
        printf("There is ring in the linked list.\n");
    } else {
        printf("There is no ring in the linked list.\n");
    }
    return 0;
}
