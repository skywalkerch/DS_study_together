#pragma once

#include "../macro.h"
#include <cstdio>
//顺序栈的实现
#define MAXSIZE 50
typedef int ElemType;
typedef struct {
    ElemType *data;
    int top;
} SqStack;

//初始化
//栈顶指针指向栈顶元素
void InitStack(SqStack &S) {
    S.top = -1;
    S.data = new ElemType[MAXSIZE];
}

//判断栈是否为空
Status StackEmpty(SqStack S) {
    if (S.top == -1) {
        return TRUE;
    } else {
        return FALSE;
    }
}

//进栈
Status Push(SqStack &S, ElemType e) {
    //判断栈是否已经满了
    if (S.top == MAXSIZE - 1) {
        printf("栈满");
        return ERROR;
    }
    S.data[++S.top] = e;
    return OK;
}

//弹栈
Status Pop(SqStack &S, ElemType &e) {
    //判断栈是否哦为空
    if (StackEmpty(S)) {
        printf("栈为空");
        return ERROR;
    }
    e = S.data[S.top--];
    return OK;
}

//读栈顶元素
Status GetTop(SqStack S, ElemType &e) {
    if (StackEmpty(S)) {
        printf("栈为空");
        return ERROR;
    }
    e = S.data[S.top];
    return OK;
}

//test
void SqStackTest() {
    SqStack S;
    InitStack(S);
    //1 2 3 4 5 连续进栈
    Push(S, 1);
    Push(S, 2);
    Push(S, 3);
    Push(S, 4);
    Push(S, 5);
    ElemType e;
    GetTop(S, e);
    //读栈顶
    printf("栈顶元素=%d\n", e);
    //弹栈
    Pop(S, e);
    Pop(S, e);
    printf("弹两次栈后,栈顶元素=%d\n", e);
}