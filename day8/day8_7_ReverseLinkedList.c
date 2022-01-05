//
//  day8_7_ReverseLinkedList.c
//  day8_7_ReverseLinkedList
//
//  Created by 雨轩 on 2022/1/5.
//

//  将一个链表逆置.

#include "LinkedList.h"

void Reverse(node *head, node *prenode, node *thisnode) {
    if(thisnode->next) {
        Reverse(head, thisnode, thisnode->next);
    } else {
        head->next->next = NULL;
        head->next = thisnode;
    }
    thisnode->next = prenode;
}   //非递归要写链栈,太麻烦,递归偷懒一下

void ReverseLinkedList(node *head) {
    if(head->next->next) {
        Reverse(head, head->next, head->next->next);
    }
}

int main(int argc, const char * argv[]) {
    node *head = (node*)malloc(sizeof(node));
    head->next = NULL;
    head->val = 0;
    printf("Now create the linked list.\n");
    LinkedList(head);
    ReverseLinkedList(head);
    printf("After Reverse:\n");
    PrintList(head);
    return 0;
}
