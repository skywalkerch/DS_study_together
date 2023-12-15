#define MaxSize 50

typedef struct SqStack{
    int data[MaxSize];
    int top;
}SqStack;

typedef struct SqQueue{
    int data[MaxSize];
    int *front, *rear;
}SqQueue;

typedef struct BiTNODE{
    int data;
    BiTNODE *lchild, *rchild;
}BiTNODE, *BiTree;

int QueueEmpty(SqQueue Q);
int InitQueue(SqQueue &Q);
int DeQueue(SqQueue &Q, BiTree T);
int EnQueue(SqQueue &Q, BiTree T);
int visit(BiTree &T);

int LevelOrderVisit(BiTree T){
    SqQueue Q;
    InitQueue(Q);
    BiTree p;
    EnQueue(Q, T);
    while(!QueueEmpty(Q)){
        DeQueue(Q, p);
        visit(p);
        EnQueue(Q, T->lchild);
        EnQueue(Q, T->rchild);
    }
}

int PreOrderVisit(BiTree &T);
int InOrderVisit(BiTree &T);
int PostOrderVisit(BiTree &T);

//Non
int PreOrderVisit2(BiTree &T);
int InOrderVisit2(BiTree &T);
int PostOrderVisit2(BiTree &T);

typedef struct ThreadNode{
    int data;
    struct ThreadNode *lchild, *rchild;
    int ltag, rtag;
}ThreadNode, *ThreadTree;
