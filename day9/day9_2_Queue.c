//
//  day9_2_Queue.c
//  day9_2_Queue
//
//  Created by 雨轩 on 2022/1/6.
//

//  完成循环队列的入队，出队

#include <stdio.h>
#include <stdlib.h>

typedef int Elem;

typedef struct LinkedListNode {
    Elem val;
    struct LinkedListNode *next;
    struct LinkedListNode *pred;
} node;
//带头结点的循环双链表

node* QueueInit(void) {
    node *head = (node*)malloc(sizeof(node));
    head->val = 0;
    head->pred = head;
    head->next = head;
    return head;
}

void InQueue(node *head, Elem val) {
    node *newnode = (node*)malloc(sizeof(node));
    newnode->val = val;
    newnode->next = head;
    newnode->pred = head->pred;
    head->pred->next = newnode;
    head->pred = newnode;
}

int DeQueue(node *head, Elem *val) {
    int ret = -1;
    node *delnode = head->next;
    *val = delnode->val;
    if(delnode != head) {
        head->next = delnode->next;
        delnode->next->pred = head;
        free(delnode);
        ret = 0;
    }
    return ret;
}

int main(int argc, const char * argv[]) {
    node *Q = QueueInit();
    int i = 0;
    Elem val = 0;
    printf("Input a number to continue.\n");
    printf("1.Input some data into queue.\n");
    printf("2.Output a data from queue.\n");
    while ((void)(rewind(stdin)), scanf("%d", &i) != EOF) {
        switch (i) {
            case 1:
                printf("Please input values, and use space or \\n to separate.\n");
                printf("Use control D to end the input.\n");
                while(scanf("%d", &val) != EOF) {
                    InQueue(Q, val);
                }
                printf("Inqueue successfully!\n");
                break;
            case 2:
                if(DeQueue(Q, &val) != EOF) {
                    printf("Dequeue successfully! The value of the data output is %d\n", val);
                } else {
                    printf("There is no data in the queue.\n");
                }
                break;
        }
        printf("\nYou can use control D to exit, or continue to operate the linked list.\n\n");
    }
    return 0;
}
