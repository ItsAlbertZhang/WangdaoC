//
//  LinkedList.c
//  LinkedList
//
//  Created by 雨轩 on 2022/1/5.
//

#include "LinkedList.h"

void NodeInsertAtHead(node *head, Elem val) {
    node *newnode = (node*)malloc(sizeof(node));
    newnode->val = val;
    newnode->next = head->next;
    head->next = newnode;
}
void NodeInsertAtTail(node *head, Elem val) {
    node *lastnode = head;
    while(lastnode->next) {
        lastnode = lastnode->next;
    }
    node *newnode = (node*)malloc(sizeof(node));
    newnode->val = val;
    newnode->next = NULL;
    lastnode->next = newnode;
}
void NodeInsertBySort(node *head, Elem val) {
    //链表为升序
    node *nextnode = head, *prenode = NULL;
    while(nextnode && nextnode->val < val) {
        prenode = nextnode;
        nextnode = nextnode->next;
    }
    //此时nextnode可能指向NULL,但不影响
    node *newnode = (node*)malloc(sizeof(node));
    newnode->val = val;
    newnode->next = nextnode;
    prenode->next = newnode;
}
int NodeDel(node *head, Elem val) {
    int ret = 0;
    node *delnode = head->next, *prenode = head;
    while(delnode && delnode->val != val) {
        prenode = delnode;
        delnode = delnode->next;
    }
    //此时delnode可能为NULL,也有可能停在delnode->val = val的结点上.
    if (delnode) {
        //如果delnode不为NULL
        prenode->next = delnode->next;
        free(delnode);
        ret = 1;
    }
    return ret;
}
void PrintList(node *head) {
    node *thisnode = head->next;
    while(thisnode) {
        printf("%d\t", thisnode->val);
        thisnode = thisnode->next;
    }
    printf("\n");
}
void DelAllNodes(node *head) {
    node* delnode = head->next;
    while(delnode) {
        head->next = delnode->next;
        free(delnode);
        delnode = head->next;
    }
}

void LinkedList(node *head) {
    int i = 0;
    Elem val = 0;
    printf("Input a number to continue.\n");
    printf("1.Insert at head.\n");
    printf("2.Insert at tail.\n");
    printf("3.Insert as sort.\n");
    printf("4.Print the list.\n");
    printf("5.Delete a node.\n");
    printf("6.Delete all nodes.\n");
    while ((void)(rewind(stdin)), scanf("%d", &i) != EOF) {
        switch (i) {
            case 1:
                printf("Please input values, and use space or \\n to separate.\n");
                printf("Use control D to end the input.\n");
                while(scanf("%d", &val) != EOF) {
                    NodeInsertAtHead(head, val);
                }
                printf("Insert successfully!\n");
                break;
            case 2:
                printf("Please input values, and use space or \\n to separate.\n");
                printf("Use control D to end the input.\n");
                while(scanf("%d", &val) != EOF) {
                    NodeInsertAtTail(head, val);
                }
                printf("Insert successfully!\n");
                break;
            case 3:
                printf("Please input values, and use space or \\n to separate.\n");
                printf("Use control D to end the input.\n");
                while(scanf("%d", &val) != EOF) {
                    NodeInsertBySort(head, val);
                }
                printf("Insert successfully!\n");
                break;
            case 4:
                printf("The list is:\n");
                PrintList(head);
                break;
            case 5:
                printf("Input the value you want to delete.\n");
                scanf("%d", &val);
                int ret = NodeDel(head, val);
                if(ret) {
                    printf("Delete successfully!\n");
                } else {
                    printf("ERROR: No such node.\n");
                }
                break;
            case 6:
                DelAllNodes(head);
                printf("Delete successfully!\n");
                break;
        }
        printf("\nYou can use control D to exit, or continue to operate the linked list.\n\n");
    }
}
