#define MaxSize 50

typedef struct SqStack{
    int data[MaxSize];
    int top;
}SqStack;

typedef struct SqQueue{
    int data[MaxSize];
    int *front, *rear;
}SqQueue;

#define MaxVertexNum 100

typedef char VexType;
typedef char InfoType;
typedef int EdgeType;

//邻接矩阵
typedef struct MGraph
{
    /* data */
    VexType Vex[MaxVertexNum];
    EdgeType Edge[MaxVertexNum][MaxVertexNum];
    int vexnum, arcnum;
}MGraph;

//弧节点
typedef struct ArcNode
{
    /* data */
    int adjvex;
    struct ArcNode *Next;
    InfoType info;
}ArcNode;

//顶点节点
typedef struct VNode
{
    /* data */
    VexType data;
    ArcNode *first;
}VNode,AdjList[MaxVertexNum];

//邻接表
typedef struct ALGraph
{
    /* data */
    AdjList vertices;
    int vexnum,arcnum;
}ALGraph;

int BFS(ALGraph &G);

int DFS(ALGraph &G);

int Order(ALGraph &G);