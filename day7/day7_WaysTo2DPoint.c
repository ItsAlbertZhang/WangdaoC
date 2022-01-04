//
//  day7_WaysTo2DPoint.c
//  day7_WaysTo2DPoint
//
//  Created by 雨轩 on 2022/1/4.
//

//  从坐标原点出发,每次只能向上或向右走一步,有多少种路径可以走到点(m,n)?
//  求出可能路径的数量并输出这些路径.

#include <stdio.h>
#include <stdlib.h>

typedef struct _BiTreeNode {
    int x;
    int y;
    struct _BiTreeNode *lchild;
    struct _BiTreeNode *rchild;
} BiTreeNode;

//  一个结点(x,y)(x、y均大于0)的左孩子为(x-1,y),右孩子为(x,y-1).
void CreateBiTreeNode(BiTreeNode *parent) {
    if(parent->x) {
        parent->lchild = (BiTreeNode*)malloc(sizeof(BiTreeNode));
        parent->lchild->x = parent->x - 1;
        parent->lchild->y = parent->y;
        CreateBiTreeNode(parent->lchild);
    } else {
        parent->lchild = NULL;
    }
    if(parent->y) {
        parent->rchild = (BiTreeNode*)malloc(sizeof(BiTreeNode));
        parent->rchild->x = parent->x;
        parent->rchild->y = parent->y - 1;
        CreateBiTreeNode(parent->rchild);
    } else {
        parent->rchild = NULL;
    }
}

//  用一个二进制数记录路径.从根出发,向左走记1,向右走记0.
//  如11(二进制为1011)代表(0,0)->(1,0)->(1,1)->(2,1)->(3,1)
void PrintWay(int record, int sum) {
    int x = 0, y = 0, bin = 1;
    for(int i = sum; i > 1; i--) {
        bin *= 2;
    }   //将x的1位移至要输出的第一位
    printf("%d,%d", x, y);
    while(bin) {
        if(bin & record) {
            x++;
        } else {
            y++;
        }
        bin >>= 1;
        printf(" -> %d,%d", x, y);
    }
    printf("\n");
}

void PreOrder(BiTreeNode *parent, int record, int *ways, int sum) {
    if(parent) {
        if(parent->lchild == NULL && parent->rchild == NULL) {
            PrintWay(record, sum);
            (*ways)++;
        }
        PreOrder(parent->lchild, record * 2 + 1, ways, sum);
        PreOrder(parent->rchild, record * 2, ways, sum);
    }
}

void DelTree(BiTreeNode *parent) {
    if(parent) {
        DelTree(parent->lchild);
        DelTree(parent->rchild);
        free(parent);
    }
}

int main(int argc, const char * argv[]) {
    printf("Input x and y, and use space or \\n to separate them.\nUse control D to exit.\n");
    int x = 0, y = 0;
    while(scanf("%d %d", &x, &y) != EOF) {
        int ways = 0;
        BiTreeNode *root = (BiTreeNode*)malloc(sizeof(BiTreeNode));
        root->x = x;
        root->y = y;
        CreateBiTreeNode(root);
        PreOrder(root, 0, &ways, x + y);
        printf("The ways to (%d,%d) is %d\n", x, y, ways);
        DelTree(root);
    }
    return 0;
}
