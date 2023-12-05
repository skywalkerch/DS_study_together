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

//十字链表弧节点
typedef struct XArcNode
{
    /* data */
    int tailvex, headvex;
    struct XArcNode *hlink, *tlink;
    InfoType info;
}XArcNode;

//十字链表顶点节点
typedef struct XVNode
{
    /* data */
    VexType data;
    XArcNode *firstin;
    XArcNode *firstout;
}XVNode,XList[MaxVertexNum];

//十字链表
typedef struct XGraph
{
    /* data */
    XList vertices;
    int vexnum,arcnum;
}XGraph;

