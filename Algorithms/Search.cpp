#include <cstddef>
#include <stdlib.h>


using namespace std;

#define MaxSize 50
typedef struct{
    int data[MaxSize];
    int length;
}SqList;

typedef struct LNode{
    int data;
    LNode *next;
}LNode, *LinkList;

typedef struct TNode{
    int data;
    TNode *lchild, *rchild;
}TNode, *Tree;

int LinkLineSearch(LinkList &L,int &e){
    int i = 0,aim = NULL;
    if(L->data == NULL)         //若有头节点,==接自定义的头节点data值
        L = L->next;
    while(L != NULL){
        aim = L->data;
        i ++;
        //if(aim > e)
        //    return false;   //如果是顺序表，加这两行
        if(aim == e)
            return i;
        L = L->next;
    }
}

int LineSearch(SqList &L,int &e,int low,int high,int i){
    //返回无序线性表中在 low 到 high 之间等于e的数值的数组位置
    while(i < MaxSize){
        if(L.data[i++] == e)          //i表示在 data[MaxSize] 中的下标，i++，取值为 L[i]
            return 0;                 //i++ 后，i=i+1,此时的i表示[1...n]中的位置，是逻辑线性表的位置
    }
    return false;
}

int BiSearch(SqList &L,int &e,int &low,int &high,int &mid){
    //二分查找 low 到 high 之间等于e的值的数组位置mid
    //如果没有找到就返回大于e的最小值
    while(low <= high){
        mid = (low + high)/2;
        if(L.data[mid] > e)
            high = mid - 1;//这里的mid就是大于e的最小值
        else if(L.data[mid] < e)
            low = ++mid;//++mid是大于e的最小值
        else
            break;
    }
    return 0;
}

int BlockSearch(SqList &Index,SqList &Index_value,SqList &S_L,int &e){
    //Index 记录块索引，Index_value 记录块最大值
    int low,high,mid;
    //二分查找大于e的最小值
    BiSearch(Index_value,e,low,high,mid);
    //块内查找e
    if(LineSearch(S_L,e,Index.data[mid],Index_value.data[++mid],mid) == 0)
        return mid;
    else
        return false;
}

Tree BSTSearch(Tree T,int &e,Tree ){
    //对一棵二叉排序树进行查找
    //左子树小于根小于右子树
    //返回指向节点的指针 T(Tree)
    while(T != NULL){
        if(T->data > e)
            T = T->lchild;
        else if (T->data < e)
            T = T->rchild;
        else
            return T;
    }
}

Tree BSTCreate();

