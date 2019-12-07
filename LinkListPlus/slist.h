#pragma once
#include<stdio.h>

typedef int SLDataType;
typedef struct SListNode{
	SLDataType data;
	struct SListNode* next;
}SListNode;

//��ӡ���
void SListPrint(SListNode* pList);

//β��
void SListPushBack(SListNode** ppList, SLDataType x);

//ͷ��
void SListPushFront(SListNode** ppList, SLDataType x);

//βɾ
void SListPopBack(SListNode** ppList);

//ͷɾ
void SListPopFront(SListNode** ppList);

//����
SListNode* SListFind(SListNode* pList, SLDataType x);

//pos����������
void SListInsertAfter(SListNode* pos, SLDataType x);

//pos������ɾ��
void SListEraseAfter(SListNode* pos);

//�����������
void SListDestory(SListNode* pList);
