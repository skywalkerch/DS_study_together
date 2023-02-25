#pragma once

#include"macro.h"
#include <stdio.h>

typedef int ElemType;
typedef struct LinkNode {
    ElemType data;
    struct LinkNode *next;
} *LinkStack;

//链栈规定所有操作均在单链表的表头进行
//本代码规定链栈没有头结点

//初始化
void InitLinkStack(LinkStack &S) {
    S = NULL;
    //S一开始是个空指针;
}

//判断栈是否为空
Status LinkStackEmpty(LinkStack S) {
    if (!S) { return TRUE; }
    else { return FALSE; }
}


//入栈,用无头结点的前插法
Status Push(LinkStack &S, ElemType e) {
    LinkNode *p = new LinkNode;
    p->data = e;
    p->next = S;
    S = p;
    return OK;
}

//弹栈
Status Pop(LinkStack &S, ElemType &e) {
    if (LinkStackEmpty(S)) {
        printf("栈空\n");
        return ERROR;
    }
    e = S->data;
    LinkNode *q = S;
    S = S->next;
    delete q;
    return OK;
}

//读栈顶
Status GetTop(LinkStack S, ElemType &e) {
    if (LinkStackEmpty(S)) {
        printf("栈空\n");
        return ERROR;
    }
    e = S->data;
    return OK;
}

//测试
void LinkStackTest() {
    LinkStack S;
    InitLinkStack(S);

    //1 2 3 4 5 依次进栈
    Push(S, 1);
    Push(S, 2);
    Push(S, 3);
    Push(S, 4);
    Push(S, 5);

    //读栈顶
    ElemType e;
    GetTop(S, e);
    printf("栈顶元素=%d\n", e);

    //弹栈
    Pop(S, e);
    Pop(S, e);
    GetTop(S, e);
    printf("栈顶元素=%d\n", e);
}



