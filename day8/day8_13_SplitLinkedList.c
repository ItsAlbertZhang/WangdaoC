//
//  day8_13_SplitLinkedList.c
//  day8_13_SplitLinkedList
//
//  Created by 雨轩 on 2022/1/5.
//

//  将一个链表拆分（将链表奇数位置上的节点构成一个链表，偶数位置上的节点构成另一个链表）


#include "LinkedList.h"

void SplitLinkedList(node* head1, node *head2) {
    node *p1 = head1->next, *p2 = head2;
    while(p1 && p1->next) {
        p2->next = p1->next;
        p1->next = p1->next->next;
        p2->next->next = NULL;
        p1 = p1->next;
        p2 = p2->next;
    }
}

int main(int argc, const char * argv[]) {
    node *head1 = (node*)malloc(sizeof(node));
    head1->next = NULL;
    head1->val = 0;
    printf("Now create the linked list.\n");
    LinkedList(head1);
    node *head2 = (node*)malloc(sizeof(node));
    head2->next = NULL;
    head2->val = 0;
    SplitLinkedList(head1, head2);
    printf("linked list 1:\n");
    PrintList(head1);
    printf("linked list 2:\n");
    PrintList(head2);
    return 0;
}
