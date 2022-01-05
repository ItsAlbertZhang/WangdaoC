//
//  day8_9_GetMiddleNode.c
//  day8_9_GetMiddleNode
//
//  Created by 雨轩 on 2022/1/5.
//

//  找出链表的中间节点.

#include "LinkedList.h"

node* GetMiddleNode(node* head) {
    node *pfast = head->next, *pslow = head->next;
    int isslowgo = 0;
    if(pfast) {
        while(pfast->next) {
            pfast = pfast->next;
            if(isslowgo) {
                pslow = pslow->next;
                isslowgo = 0;
            } else {
                isslowgo = 1;
            }
        }
    }
    return pslow;
}

int main(int argc, const char * argv[]) {
    node *head = (node*)malloc(sizeof(node));
    head->next = NULL;
    head->val = 0;
    printf("Now create the linked list.\n");
    LinkedList(head);
    node *ret = GetMiddleNode(head);
    if(ret) {
        printf("The node in the middle of the linked list is %d\n", ret->val);
    } else {
        printf("There are not any nodes in the linked list.\n");
    }
    return 0;
}
