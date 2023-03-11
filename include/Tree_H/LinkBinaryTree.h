//
// Created by skywalkerch on 2023/3/3.
//

#ifndef DS_LINKBINARYTREE_H
#define DS_LINKBINARYTREE_H
#include<stack>
#include<vector>
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
// preOrder only use stack
vector<int> S_PreOrder(BiTree T){
    stack<BiTNode*> S;
    vector<int> result;
    BiTNode* curNode=T;
    while(!(!curNode&&S.empty()){
        if (curNode){
        S.push(curNode);
        result.push_back(curNode->data);
        curNode=curNode->lchild;
        }else{
        curNode=S.top()->rchild;
        S.pop();
        }
}
    return result;
}

//二叉树的中序遍历
void InOrder(BiTree T) {
    if (T) {
        InOrder(T->lchild);
        visit(T);
        InOrder(T->rchild);
    }
}

// InOrder only use stack
vector<int> S_InOrder(BiTree T){
    vector<int> result;
    BiTNode* curNode=T;
    stack<BiTNode*>;
    while(!(!curNode&&S.empty())){
        if(curNode){
            S.push(curNode);
            curNode=curNode->lchild;
        }else{
            curNode=S.top->rchild;
            result.push_back(S.top->data);
            S.pop();
        }
    }
    return result;
}




//二叉树的后序遍历
void PostOrder(BiTree T) {
    if (T) {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        visit(T);
    }
}

//PostOrder only use stack
//
vector<int> S_PostOrder(BiTree T)
{
vector<int> result;
stack<int> temp;
BiTNode *curNode=T;
stack<BiTNode*> S;
while(!(!curNode&&S.empty())){
    if(curNode){
        S.push(curNode);
        temp.push(curNode->data);
        curNode=curNode->rchild; 
    }else{
    curNode=S.top->lchild;
    S.pop();
    }
}
while(!temp.empty()){
    result.push_back(temp.top);
    temp.pop();
}
return result;
}

#endif //DS_LINKBINARYTREE_H
