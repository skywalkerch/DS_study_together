//�������
#include"macro.h"
#include <iostream>
#pragma once
typedef int ElemType;
//������
typedef struct LNode {
	ElemType data;
	LNode* next;
}LNode, * LinkList;

//������ĳ�ʼ������ͷ��㣩
Status InitList(LinkList& L) {
	L = new LNode;
	L->next = NULL;
	return OK;
}

//������ȡֵ,ȡ��ͷ�����i��Ԫ�� 
Status GetElem(LinkList L, int i, ElemType& e) {
	//�ж�i�Ƿ�Ϸ�
	LNode* p = L->next;//pָ����Ԫ���
	int j = 1;
	while (p && j < i) {
		p = p->next;
		j++;
	}
	if (!p || j > i)return ERROR;
	e = p->data;
	return OK;
}

//���������,�������������ֵΪe�Ľ��
LNode* LocateElem(LinkList L, ElemType e) {
	if (!L) return ERROR;
	LNode* p = L->next;
	while (p && p->data != e) {
		p = p->next;
	}
	return p;
}

//������Ĳ���
Status ListInsert(LinkList& L, int i, ElemType e) {
	LNode* p = L; int j = 0;
	while (p && j < i - 1) {
		p = p->next;
		j++;
	}
	if (!p || j > i - 1) return ERROR;
	LNode* s = new LNode;
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}

//������ɾ����ɾ��ͷ���֮���i�����
Status ListDelete(LinkList& L, int i) {
	LNode* p = L; int j = 0;
	while (p->next && j < i - 1) {
		p = p->next;
		j++;
	}
	if (!(p->next) || j > i - 1)return ERROR;
	LNode* q = p->next;
	p->next = q->next;
	delete q;
	return OK;
}

//ǰ�巨����������
Status CreateList_H(LinkList& L, int n) {
	L = new LNode;
	L->next = NULL;
	for (int i = 0; i < n; i++) {
		std::cout << "������������:";
		LNode* p = new LNode;
		std::cin >> p->data;
		p->next = L->next;
		L->next = p;
	}
	return OK;
}

//��巨����������
Status CreateList_R(LinkList& L, int n) {
	L = new LNode;
	L->next = NULL;
	LNode* r = L;
	for (int i = 0; i < n; i++) {
		std::cout << "˳����������:";
		LNode* p = new LNode;
		std::cin >> p->data;
		p->next = r->next;
		r->next = p;
		r = p;
	}
	return OK;
}


//���ٵ�����
Status DestroyList(LinkList& L) {
	LNode* p = L->next;
	if (!p) return OK;
	while (p) {
		LNode* q = p;
		L->next = p->next;
		p = L->next;
		delete q;
	}
	return OK;
}

//��ӡ������
void PrintLinkList(LinkList L) {
	if (!L->next) { std::cout << "������Ϊ��" << std::endl; }
	while (L->next) {
		std::cout << L->next->data << std::endl;
		L = L->next;
	}
	std::cout << std::endl;
}



//����ר�ô���������
Status CreateList_T(LinkList& L, int n) {
	L = new LNode;
	L->next = NULL;
	for (int i = 0; i < n; i++) {
		LNode* p = new LNode;
		p->data = n - i;
		p->next = L->next;
		L->next = p;
	}
	return OK;
}


void TestLinkList() {
	//ǰ�巨�ͺ�巨�Ѳ���ͨ��

	LinkList L;
	CreateList_T(L, 6);
	//ɾ����������
	DestroyList(L);
	if (!L->next) std::cout << "���ٺ�������ͨ��\n" << std::endl;
	//���Ե�����Ĳ���
	CreateList_T(L, 6);
	ListInsert(L, 1, 8);
	PrintLinkList(L);
	std::cout << "���뺯������ͨ��\n" << std::endl;
	DestroyList(L);

	CreateList_T(L, 6);
	//���Ե�����ɾ��
	if (ListDelete(L, 6)) {
		PrintLinkList(L);
		std::cout << "ɾ����㺯������ͨ��\n" << std::endl;
	}
	else {
		std::cout << "ɾ����㺯�����Բ�ͨ��\n" << std::endl;
	}
	DestroyList(L);
	CreateList_T(L, 6);
	//�������ȡֵ��������
	ElemType e;
	ElemType n=3;
	if (GetElem(L, n, e)) {
		if (e == n) {
			std::cout << "ȡֵ��������ͨ��\n" << std::endl;
		}
	}
	else {
		std::cout << "ȡֵ�������Բ�ͨ��\n" << std::endl;
	}

	//���Ե�������Һ���
	if (LocateElem(L, e)->data == e) {
		std::cout << "���Һ�������ͨ��\n" << std::endl;
	}
	else {
		std::cout << "���Һ������Բ�ͨ��\n" << std::endl;
	}



}





