//
// Created by skywalkerch on 2023/2/25.
//
#include "macro.h"
#include <stdio.h>
//顺序队的实现
#define MAXSIZE 50
typedef int ElemType;
typedef struct {
    ElemType *data;
    int front;
    int rear;
} SqQueue;

//这里参考王道23版的教材
//初始front和rear相等表示空队
//front指向对头元素
//rear指向队尾元素的下一个位置
Status InitQueue(SqQueue &Q) {
    Q.data = new ElemType[MAXSIZE];
    Q.front = Q.rear = 0;
    return OK;
};

Status QueueEmpty(SqQueue &Q) {
    if (Q.front == Q.rear) { return TRUE; }
    return FALSE;

};

Status EnQueue(SqQueue &Q, ElemType e) {
    //判断队列Q是否是满的
    if ((Q.rear + 1) % MAXSIZE == Q.front) {
        printf("队列已满\n");
        return ERROR;
    }
    Q.data[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MAXSIZE;
    return OK;
};

Status DeQueue(SqQueue &Q, ElemType &e) {
    if (QueueEmpty(Q)) {
        printf("队空\n");
        return ERROR;
    }
    e = Q.data[Q.front];
    Q.front = (Q.front + 1) % MAXSIZE;
    return OK;
};

Status GetHead(SqQueue &Q, ElemType &e) {
    if (QueueEmpty(Q)) {
        printf("队空\n");
        return ERROR;
    }
    e = Q.data[Q.front];
    return OK;
};

void SqQueueTest() {
    SqQueue Q;
    InitQueue(Q);
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
    GetHead(Q, e);
    printf("队头元素%d\n", e);
}