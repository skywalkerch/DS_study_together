//
// Created by skywalkerch on 2023/2/25.
//
#include "macro.h"
#include <cstdio>

typedef int ElemType;
typedef struct LinkNode {
    ElemType data;
    LinkNode *next;
} LinkNode;
typedef struct {
    LinkNode *front, *rear;
} LinkQueue;


//由于不带头结点的单链表不易操作,因此这里默认链队具有头结点,且front指向头结点
Status InitQueue(LinkQueue &Q) {
    LinkNode *head = new LinkNode;
    head->next = NULL;
    Q.front = head;
    Q.rear = head;
    return OK;
}

Status QueueEmpty(LinkQueue &Q) {
    if (Q.front == Q.rear) {
        return TRUE;
    }
    return FALSE;
}

Status EnQueue(LinkQueue &Q, ElemType e) {
    //rear方向入队,用单链表的后插法
    LinkNode *p = new LinkNode;
    p->data = e;
    p->next = NULL;
    Q.rear->next = p;
    Q.rear = p;
    return OK;
}

Status DeQueue(LinkQueue &Q, ElemType &e) {
    if (QueueEmpty(Q)) {
        printf("队列为空");
        return ERROR;
    }
    LinkNode *p = Q.front->next;
    e = p->data;
    Q.front->next = p->next;
    if (Q.rear == p) {
        Q.rear = Q.front;
    }
    delete p;
    return OK;
}

Status GetHead(LinkQueue Q, ElemType &e) {
    if (QueueEmpty(Q)) {
        printf("队列为空");
        return ERROR;
    }
    e = Q.front->next->data;
    return OK;
}

void LinkQueueTest() {
    LinkQueue Q;
    InitQueue(Q);
    //1 2 3 4 5入队
    EnQueue(Q, 1);
    EnQueue(Q, 2);
    EnQueue(Q, 3);
    EnQueue(Q, 4);
    EnQueue(Q, 5);
    ElemType e;
    GetHead(Q, e);
    printf("队头元素%d\n", e);
    DeQueue(Q, e);
    DeQueue(Q, e);
    DeQueue(Q, e);
    DeQueue(Q, e);
    GetHead(Q, e);
    printf("队头元素%d\n", e);
}



