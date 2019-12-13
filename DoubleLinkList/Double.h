//任意位置实现O（1）的插入删除
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

//创建返回链表的头结点
ListNode* ListCreat();

//双向链表的尾插
void ListPushBack(ListNode* list, LTDataType x);

//双向链表的打印
void ListPrint(ListNode* list);

//双向链表的尾删
void ListPopBack(ListNode* list);

//双向链表的头插
void ListPushFront(ListNode* list, LTDataType x);

//双向链表的头删
void ListPopFront(ListNode* list);

//双向链表的查找
ListNode* ListFind(ListNode* list, LTDataType x);

//双向链表在pos的前面插入
void ListInsert(ListNode* pos, LTDataType x);

//双向链表删除pos位置的结点
void ListErase(ListNode* pos);

//双向链表的销毁
void ListDestory(ListNode* list);