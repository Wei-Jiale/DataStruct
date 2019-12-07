#pragma once
#include<stdio.h>

typedef int SLDataType;
typedef struct SListNode{
	SLDataType data;
	struct SListNode* next;
}SListNode;

//打印结点
void SListPrint(SListNode* pList);

//尾插
void SListPushBack(SListNode** ppList, SLDataType x);

//头插
void SListPushFront(SListNode** ppList, SLDataType x);

//尾删
void SListPopBack(SListNode** ppList);

//头删
void SListPopFront(SListNode** ppList);

//查找
SListNode* SListFind(SListNode* pList, SLDataType x);

//pos结点后做插入
void SListInsertAfter(SListNode* pos, SLDataType x);

//pos结点后做删除
void SListEraseAfter(SListNode* pos);

//单链表的销毁
void SListDestory(SListNode* pList);
