//
//  day8_12_DelRepeatDlem.c
//  day8_12_DelRepeatDlem
//
//  Created by 雨轩 on 2022/1/5.
//

//  删除单链表中重复的元素.

#include "LinkedList.h"

//  暴力算法,时间复杂度O(n)(排序或查找算法以后再补)
void DelRepeatElem(node* head) {
    //利用带头结点的链表根据值删除结点时,不会搜索头结点内的值的特性,进行以下算(tou)法(lan)
    node *p = head->next;
    while(p) {
        while(NodeDel(p, p->val));
        p = p->next;
    }
}

int main(int argc, const char * argv[]) {
    node *head = (node*)malloc(sizeof(node));
    head->next = NULL;
    head->val = 0;
    printf("Now create the linked list.\n");
    LinkedList(head);
    DelRepeatElem(head);
    printf("After DelRepeat:\n");
    PrintList(head);
    return 0;
}
