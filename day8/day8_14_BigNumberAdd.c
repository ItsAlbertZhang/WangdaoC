//
//  day8_14_BigNumberAdd.c
//  day8_14_BigNumberAdd
//
//  Created by 雨轩 on 2022/1/5.
//

//  大整数加法.

#include "LinkedList.h"

void GetNumToLinkedList(node *head) {
    //懒得写char链表了,用int链表凑合吧
    char c = 0;
    while((c = getchar()) != '\n') {
        if(c >= '0' && c <= '9') {
            NodeInsertAtHead(head, c - '0');
        }
    }
}

void BigNumberAdd(node *head1, node *head2) {
    node *p1 = head1, *p2 = head2;
    int temp = 0;
    while(p1->next && p2->next) {
        p1->next->val = p1->next->val + p2->next->val + temp;
        temp = 0;
        if(p1->next->val > 9) {
            temp = p1->next->val / 10;
            p1->next->val %= 10;
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    if(p2->next) {
        p1->next = p2->next;
    }   //如果p2位数较高,将p2的高位接至p1的末尾.
    while(temp && p1->next) {
        p1->next->val = p1->next->val + temp;
        temp = 0;
        if(p1->next->val > 9) {
            temp = p1->next->val /= 10;
            p1->next->val %= 10;
        }
        p1 = p1->next;
    }
    if(temp) {
        NodeInsertAtTail(p1, temp);
    }
}

void PrintTheNumber(node *head) {
    //用递归栈实现链表的反序输出
    //注意不要输出头结点
    if(head->next->next) {
        PrintTheNumber(head->next);
    }
    printf("%d", head->next->val);
}

int main(int argc, const char * argv[]) {
    char string[][10] = {"first", "second"};
    node *head1 = (node*)malloc(sizeof(node));
    head1->next = NULL;
    head1->val = 0;
    printf("Now input the %s number, and use \\n to end.\n", string[0]);
    GetNumToLinkedList(head1);
    node *head2 = (node*)malloc(sizeof(node));
    head2->next = NULL;
    head2->val = 0;
    printf("Now input the %s number, and use \\n to end.\n", string[1]);
    GetNumToLinkedList(head2);
    BigNumberAdd(head1, head2);
    PrintTheNumber(head1);
    printf("\n");
    return 0;
}
