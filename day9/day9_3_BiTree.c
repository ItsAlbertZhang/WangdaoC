//
//  day9_3_BiTree.c
//  day9_3_BiTree
//
//  Created by 雨轩 on 2022/1/6.
//

//  完成二叉树的层次建树

#include <stdio.h>
#include <stdlib.h>

typedef struct BiTreeNode {
    int val;
    struct BiTreeNode *lchild;
    struct BiTreeNode *rchild;
} tree;

typedef tree* Elem;

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

tree* TreeLevelInit(void) {
    tree *root = NULL;
    int val = 0;
    node *Q = QueueInit();
    if(scanf("%d", &val)) {
        root = (tree*)malloc(sizeof(tree));
        root->val = val;
        root->lchild = NULL;
        root->rchild = NULL;
        tree *treenode = root;
        //建立根结点，并用一个指针treenode指向它
        while(scanf("%d", &val) != EOF) {
            tree *newnode = (tree*)malloc(sizeof(tree));
            newnode->val = val;
            newnode->lchild = NULL;
            newnode->rchild = NULL;
            //建立新结点
            if(NULL == treenode->lchild) {
                treenode->lchild = newnode;
                //如果treenode左孩子为空，则将新结点挂至左孩子
            } else {
                treenode->rchild = newnode;
                DeQueue(Q, &treenode);
                //否则将新结点挂至右孩子，此时treenode左右孩子已满，因此从队列中出队一个结点并将其赋给treenode
            }
            InQueue(Q, newnode);
            //新结点入队
        }
        while(DeQueue(Q, &treenode) != EOF);
        //清空队列（队头除外）
        free(Q);
        //释放队头
    }
    return root;
}



int main(int argc, const char * argv[]) {
    printf("Please input values, and use space or \\n to separate.\n");
    printf("Use control D to end the input.\n");
    tree *root = TreeLevelInit();
    return 0;
}
