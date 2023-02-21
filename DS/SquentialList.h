#pragma once
#include "macro.h"
#include<stdio.h>
//Squential List 

#define MAXSIZE 100
typedef struct {
	ElemType* elem;
	int length;
}SqList;

//init Squential List 
Status InitSqList(SqList& L) {
	L.elem = new ElemType[MAXSIZE];
	if (!L.elem) return OVERFLOW;
	L.length = 0;
	return OK;
}
//get element from SqList
Status GetElem(SqList L, int i, ElemType& e) {
	//�ж��±��Ƿ����
	if (i < 0 || i >= L.length) return ERROR;
	e = L.elem[i - 1];
	return OK;
}

//locate element from SqList
int LocateElem(SqList L, ElemType e) {
	for (int i = 0; i < L.length; i++) {
		if (L.elem[i] == e) { return i + 1; }
	}
	//if can't find
	return 0;
}

//insert element to Sqlist
//�ڵ�i��λ�ò���Ԫ��,�±�Ϊi-1

Status ListInsert(SqList& L, unsigned int i, ElemType e) {
	if (i<1 || i>L.length + 1 || (i == MAXSIZE)) { return ERROR; }
	for (int j = L.length - 1; j >= i-1; j--) {
		L.elem[j + 1] = L.elem[j];
	}
	L.elem[i - 1] = e;
	L.length++;
	return OK;
}

//delete element to Sqlist
//�ڵ�i��λ��ɾ��Ԫ��,�±�Ϊi-1

Status ListDelete(SqList& L, unsigned int i) {
	if (i<1 || i>L.length) { return ERROR; }
	for (int j = i - 1; j < L.length; j++) {
		L.elem[j] = L.elem[j + 1];
	}
	L.length--;
	return OK;
}

void PrintList(SqList L) {
	for (int i = 0; i < L.length; i++) {
		printf("%d-->%d\n", i, L.elem[i]);
	}
}

void TestSqList() {
	SqList L;
	InitSqList(L);
	L.elem[0] = 0;
	L.elem[1] = 1;
	L.elem[2] = 2;
	L.elem[3] = 3;
	L.elem[4] = 4;
	L.length = 5;
	//����ȡֵ
	ElemType e;
	GetElem(L, 3, e);
	printf("����ֵΪ%d\n", e);
	//���Բ���
	printf("���ҵ�%d�ǵ�%d��Ԫ��\n", e, LocateElem(L, e));

	printf("���Բ���\n");
	printf("����ǰ\n");
	PrintList(L);
	//���Բ���
	//�ڱ�ĵ�4��λ�ò���7
	ListInsert(L, 4, 7);
	printf("�����\n");
	PrintList(L);
	printf("\n");
	//����ɾ��
	//�ڱ�ĵ�3��λ��ɾ��Ԫ��
	printf("����ɾ��\n");
	printf("ɾ��ǰ\n");
	PrintList(L);
	ListDelete(L, 3);
	printf("ɾ����\n");
	PrintList(L);
}