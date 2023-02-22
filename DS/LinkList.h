//链表代码
#include"macro.h"
#include <iostream>
#pragma once
typedef int ElemType;
//单链表
typedef struct LNode {
	ElemType data;
	LNode* next;
}LNode, * LinkList;

//单链表的初始化（有头结点）
Status InitList(LinkList& L) {
	L = new LNode;
	L->next = NULL;
	return OK;
}

//单链表取值,取出头结点后第i个元素 
Status GetElem(LinkList L, int i, ElemType& e) {
	//判断i是否合法
	LNode* p = L->next;//p指向首元结点
	int j = 1;
	while (p && j < i) {
		p = p->next;
		j++;
	}
	if (!p || j > i)return ERROR;
	e = p->data;
	return OK;
}

//单链表查找,返回数据域的数值为e的结点
LNode* LocateElem(LinkList L, ElemType e) {
	if (!L) return ERROR;
	LNode* p = L->next;
	while (p && p->data != e) {
		p = p->next;
	}
	return p;
}

//单链表的插入
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

//单链表删除，删除头结点之后第i个结点
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

//前插法创建单链表
Status CreateList_H(LinkList& L, int n) {
	L = new LNode;
	L->next = NULL;
	for (int i = 0; i < n; i++) {
		std::cout << "逆序输入数据:";
		LNode* p = new LNode;
		std::cin >> p->data;
		p->next = L->next;
		L->next = p;
	}
	return OK;
}

//后插法创建单链表
Status CreateList_R(LinkList& L, int n) {
	L = new LNode;
	L->next = NULL;
	LNode* r = L;
	for (int i = 0; i < n; i++) {
		std::cout << "顺序输入数据:";
		LNode* p = new LNode;
		std::cin >> p->data;
		p->next = r->next;
		r->next = p;
		r = p;
	}
	return OK;
}


//销毁单链表
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

//打印单链表
void PrintLinkList(LinkList L) {
	if (!L->next) { std::cout << "单链表为空" << std::endl; }
	while (L->next) {
		std::cout << L->next->data << std::endl;
		L = L->next;
	}
	std::cout << std::endl;
}



//测试专用创建链表函数
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
	//前插法和后插法已测试通过

	LinkList L;
	CreateList_T(L, 6);
	//删除除单链表
	DestroyList(L);
	if (!L->next) std::cout << "销毁函数测试通过\n" << std::endl;
	//测试单链表的插入
	CreateList_T(L, 6);
	ListInsert(L, 1, 8);
	PrintLinkList(L);
	std::cout << "插入函数测试通过\n" << std::endl;
	DestroyList(L);

	CreateList_T(L, 6);
	//测试单链表删除
	if (ListDelete(L, 6)) {
		PrintLinkList(L);
		std::cout << "删除结点函数测试通过\n" << std::endl;
	}
	else {
		std::cout << "删除结点函数测试不通过\n" << std::endl;
	}
	DestroyList(L);
	CreateList_T(L, 6);
	//单链表的取值操作测试
	ElemType e;
	ElemType n=3;
	if (GetElem(L, n, e)) {
		if (e == n) {
			std::cout << "取值函数测试通过\n" << std::endl;
		}
	}
	else {
		std::cout << "取值函数测试不通过\n" << std::endl;
	}

	//测试单链表查找函数
	if (LocateElem(L, e)->data == e) {
		std::cout << "查找函数测试通过\n" << std::endl;
	}
	else {
		std::cout << "查找函数测试不通过\n" << std::endl;
	}



}





