#include <stdio.h>
//串的定长顺序存储结构
#define MAXSIZE 255
typedef struct {
    char ch[MAXSIZE];
    int length;
} SString;

/** TODO 实现串的基本操作
 * StrAssign(&T,chars) 赋值操作,把串T赋值为chars
**/

int BF_Index(SString S, SString T) {
    int i = 1, j = 1;
    while (i <= S.length && j <= T.length) {
        if (S.ch[i] == T.ch[j]) {
            i++;
            j++;
        } else {
            i = i - j + 2;
            j = 1;
        }
    }
    if (j > T.length) { return i - T.length; }
    return 0;
}

//KMP算法,核心是求next数组算法
void GetNext(SString T, int next[]) {
    int i = 1;
    int j = 0;
    next[1] = 0;
    while (i < T.length) {
        if (j == 0 || T.ch[i] == T.ch[j]) {
            i++;
            j++;
            next[i] = j;
        } else {
            j = next[j];
        }
    }
}


int KMP_Index(SString S, SString T, int next[]) {
    int i = 1, j = 1;
    while (i <= S.length && j <= T.length) {
        if (j == 0 || S.ch[i] == T.ch[j]) {
            i++;
            j++;
        } else {
            j = next[j];
        }
    }
    if (j > T.length) { return i - T.length; }
    return 0;
}


