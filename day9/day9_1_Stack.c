//
//  day9_1_Stack.c
//  day9_1_Stack
//
//  Created by 雨轩 on 2022/1/6.
//

//  完成栈的进栈，出栈，获取栈顶元素，判断栈是否为空，获取栈大小

#include <stdio.h>
#include <stdlib.h>

typedef int Elem;

typedef struct LinkedListNode {
    Elem val;
    struct LinkedListNode *next;
} node;
//链表带头结点

typedef struct StackHead {
    int size;
    node *head;
} Stack;

Stack* StackInit(void) {
    Stack *S = (Stack*)malloc(sizeof(Stack));
    S->size = 0;
    S->head = (node*)malloc(sizeof(node));
    S->head->val = 0;
    S->head->next = NULL;
    return S;
}
void StackPush(Stack *S, Elem val) {
    node *newnode = (node*)malloc(sizeof(node));
    newnode->val = val;
    newnode->next = S->head->next;
    S->head->next = newnode;
    S->size++;
}
int StackPop(Stack *S, Elem *val) {
    int ret = -1;
    if(S->size) {
        node *delnode = S->head->next;
        *val = delnode->val;
        S->head->next = delnode->next;
        free(delnode);
        S->size--;
        ret = 0;
    }
    return ret;
}
int StackGetTop(Stack *S, Elem *val) {
    int ret = -1;
    if(S->size) {
        *val = S->head->next->val;
        ret = 0;
    }
    return ret;
}
int StackEmpty(Stack *S) {
    int ret = 1;
    if(S->size) {
        ret = 0;
    }
    return ret;
}
int StackSize(Stack *S) {
    return S->size;
}

int main(int argc, const char * argv[]) {
    Stack *S = StackInit();
    int i = 0;
    Elem val = 0;
    printf("Input a number to continue.\n");
    printf("1.Push some data into stack.\n");
    printf("2.Pop a data in Stack.\n");
    printf("3.Get the top of the stack.\n");
    printf("4.Determine if the stack is empty.\n");
    printf("5.Get the size of the stack.\n");
    while ((void)(rewind(stdin)), scanf("%d", &i) != EOF) {
        switch (i) {
            case 1:
                printf("Please input values, and use space or \\n to separate.\n");
                printf("Use control D to end the input.\n");
                while(scanf("%d", &val) != EOF) {
                    StackPush(S, val);
                }
                printf("Push successfully!\n");
                break;
            case 2:
                if(StackPop(S, &val) != EOF) {
                    printf("Pop successfully! The value of the data poped is %d\n", val);
                } else {
                    printf("There is no data in the stack.\n");
                }
                break;
            case 3:
                if(StackGetTop(S, &val) != EOF) {
                    printf("The value of the top data is %d\n", val);
                } else {
                    printf("There is no data in the stack.\n");
                }
                break;
            case 4:
                if(StackEmpty(S)) {
                    printf("The stack is empty.\n");
                } else {
                    printf("The stack is not empty.\n");
                }
                break;
            case 5:
                val = StackSize(S);
                printf("The size of the stack is %d", val);
                break;
        }
        printf("\nYou can use control D to exit, or continue to operate the linked list.\n\n");
    }
    return 0;
}
