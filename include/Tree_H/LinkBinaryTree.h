//
// Created by skywalkerch on 2023/3/3.
//

#ifndef DS_LINKBINARYTREE_H
#define DS_LINKBINARYTREE_H

#include "macro.h"
#include <cstdio>

typedef int Elemtype;
//树结点定义
typedef struct BiTNode {
    Elemtype data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

typedef struct LinkTree {
    BiTree T;
    int num;
}LinkBiTree;


//访问根节点数据
Status visit(BiTree T) {
    if (T) {
        printf("%d ", T->data);
        return OK;
    }
    return ERROR;
}


//二叉树的先序遍历
void PreOrder(BiTree T) {
    if (T) {
        visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

//二叉树的中序遍历
void InOrder(BiTree T) {
    if (T) {
        InOrder(T->lchild);
        visit(T);
        InOrder(T->rchild);
    }
}

//二叉树的后序遍历
void PostOrder(BiTree T) {
    if (T) {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        visit(T);
    }
}

#endif //DS_LINKBINARYTREE_H
