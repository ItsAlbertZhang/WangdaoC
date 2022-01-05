//
//  LinkedList.h
//  LinkedList
//
//  Created by 雨轩 on 2022/1/5.
//

#ifndef LinkedList_h
#define LinkedList_h

#include <stdio.h>
#include <stdlib.h>

typedef int Elem;

typedef struct LinkedListNode {
    Elem val;
    struct LinkedListNode *next;
} node;
//链表带头结点

void NodeInsertAtHead(node *head, Elem val);
void NodeInsertAtTail(node *head, Elem val);
void NodeInsertBySort(node *head, Elem val);
int NodeDel(node *head, Elem val);
void PrintList(node *head);
void DelAllNodes(node *head);
void LinkedList(node *head);

#endif /* LinkedList_h */
