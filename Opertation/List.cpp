#define MaxSize 50
typedef struct SqList{
    int data[MaxSize];
    int Length;
}SqList;

typedef struct SqStack{
    int data[MaxSize];
    int top;
}SqStack;

typedef struct SqQueue{
    int data[MaxSize];
    int *front, *rear;
}SqQueue;

typedef struct LNODE{
    int data;
    LNODE * next;
}LNODE, *LinkList;

typedef struct LinkStack{
    int data;
    LinkStack *next;
}*LinkStack;

typedef struct LinkQueue{
    int data;
    LinkQueue *next, *front;
} *LinkQueue;