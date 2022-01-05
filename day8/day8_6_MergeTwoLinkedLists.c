//
//  day8_6_MergeTwoLinkedLists.c
//  day8_6_MergeTwoLinkedLists
//
//  Created by 雨轩 on 2022/1/5.
//

//  将两个有序链表合并成一个有序链表。

#include "LinkedList.h"

node* MergeTwoLinkedList(node *head1, node *head2) {
    node *node1 = head1, *node2 = head2, *temp = NULL;
//    while(node1->next && node2->next) {
    while(node1->next || node2->next) {
        if(node1->next && (node2->next == NULL || node1->next->val <= node2->next->val)) {
            node1 = node1->next;
        } else {
            temp = node2->next;
            node2->next = temp->next;
            temp->next = node1->next;
            node1->next = temp;
        }
    }   //其实完全可以用head2代替node2, 因为node2一步都没走
//    while(node2->next) {
//        //此时node1指向第一条链表末尾, 且第二条链表依然有剩余元素
//        temp = node2->next;
//        node2->next = temp->next;
//        temp->next = node1->next;
//        node1->next = temp;
//        node1 = node1->next;
//    }   //不需要在node1->next到NULL时停下. 修改上段代码的循环条件&&为||, 以节省此段代码.
    return head1;
}

int main(int argc, const char * argv[]) {
    char string[][10] = {"first", "second"};
    node *head1 = (node*)malloc(sizeof(node));
    head1->next = NULL;
    head1->val = 0;
    printf("Now create the %s linked list.\nWARNING:\nIt will not be checked that the linked list is ascending or not.\nEnsure that the linked list you returned is sort by ascending.\nThe easiest way to ensure it is to insert values by sort.\n", string[0]);
    LinkedList(head1);
    node *head2 = (node*)malloc(sizeof(node));
    head2->next = NULL;
    head2->val = 0;
    printf("Now create the %s linked list.\nWARNING:\nIt will not be checked that the linked list is ascending or not.\nEnsure that the linked list you returned is sort by ascending.\nThe easiest way to ensure it is to insert values by sort.\n", string[1]);
    LinkedList(head2);
    head2 = MergeTwoLinkedList(head1, head2);
    PrintList(head1);
    return 0;
}
