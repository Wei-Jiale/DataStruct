//����λ��ʵ��O��1���Ĳ���ɾ��
#pragma once
#include<stdio.h>
#include<malloc.h>
#include<assert.h>

typedef int LTDataType;
typedef struct DListNode
{
	struct DListNode* next;
	struct DListNode* prev;
	LTDataType data;

}	ListNode;

//�������������ͷ���
ListNode* ListCreat();

//˫�������β��
void ListPushBack(ListNode* list, LTDataType x);

//˫������Ĵ�ӡ
void ListPrint(ListNode* list);

//˫�������βɾ
void ListPopBack(ListNode* list);

//˫�������ͷ��
void ListPushFront(ListNode* list, LTDataType x);

//˫�������ͷɾ
void ListPopFront(ListNode* list);

//˫������Ĳ���
ListNode* ListFind(ListNode* list, LTDataType x);

//˫��������pos��ǰ�����
void ListInsert(ListNode* pos, LTDataType x);

//˫������ɾ��posλ�õĽ��
void ListErase(ListNode* pos);

//˫�����������
void ListDestory(ListNode* list);