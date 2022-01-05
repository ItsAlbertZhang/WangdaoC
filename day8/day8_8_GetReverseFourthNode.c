//
//  day8_8_GetReverseFourthNode.c
//  day8_8_GetReverseFourthNode
//
//  Created by 雨轩 on 2022/1/5.
//

//  找出链表的倒数第四个节点.

#include "LinkedList.h"

node* GetReverseFourthNode(node* head) {
    node *p[4];
    p[0] = head;
    p[1] = p[2] = p[3] = NULL;
    while(p[0]->next) {
        p[3] = p[2];
        p[2] = p[1];
        p[1] = p[0];
        p[0] = p[0]->next;
    }
    if(p[3] == head) {
        p[3] = NULL;
    }
    return p[3];
}

int main(int argc, const char * argv[]) {
    node *head = (node*)malloc(sizeof(node));
    head->next = NULL;
    head->val = 0;
    printf("Now create the linked list.\n");
    LinkedList(head);
    node *ret = GetReverseFourthNode(head);
    if(ret) {
        printf("The value of reverse fourth node is %d\n", ret->val);
    } else {
        printf("There are less than four nodes in the linked list.\n");
    }
    return 0;
}
