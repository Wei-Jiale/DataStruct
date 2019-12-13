#include"Double.h"

//创建返回链表的头结点
ListNode* ListCreat(){
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	//带头双向循环
	head->next = head;
	head->prev = head;

	return head;
}

//双向链表的尾插
void ListPushBack(ListNode* list, LTDataType x){
	//创建新结点
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->data = x;
	newNode->prev = NULL;
	newNode->next = NULL;

	ListNode* tail = list->prev;
	tail->next = newNode;
	newNode->prev = tail;
	newNode->next = list;
	list->prev = newNode;
}

//双向链表的打印
void ListPrint(ListNode* list){
	ListNode* cur = list->next;

	while (cur != list){
		printf("%d ",cur->data);
		cur = cur->next;
	}
	printf("\n");
}

//双向链表的尾删
void ListPopBack(ListNode* list){
	//找尾和倒数第二个
	ListNode* tail = list->prev;
	ListNode* prev = tail->prev;

	free(tail);
	prev->next = list;
	list->prev = prev;
	
}

//双向链表的头插
void ListPushFront(ListNode* list, LTDataType x){
	//创建新结点
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->data = x;
	newNode->prev = NULL;
	newNode->next = NULL;

	ListNode* node = list->next;

	list->next = newNode;
	newNode->prev = list;
	newNode->next = node;
	node->prev = newNode;
}

//双向链表的头删
void ListPopFront(ListNode* list){
	assert(list->next != list);
	//找到第二个结点
	ListNode* node = list->next->next;

	list->next = node;
	node->prev = list;
}

//双向链表的查找
ListNode* ListFind(ListNode* list, LTDataType x){
	ListNode* cur = list->next;
	while (cur!=list){
		if (cur->data == x){
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

//双向链表在pos之前插入
void ListInsert(ListNode* pos, LTDataType x){
	//创建新结点
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->data = x;
	newNode->prev = NULL;
	newNode->next = NULL;

	ListNode* node = pos->prev;

	pos->prev = newNode;
	newNode->next = pos;
	newNode->prev = node;
	node->next = newNode;
	
}

//双向链表删除pos位置结点
void ListErase(ListNode* pos){
	//找到pos位置下一个结点
	ListNode* next = pos->next;
	//找到pos位置前一个结点
	ListNode* prev = pos->prev;

	free(pos);
	prev->next = next;
	next->prev = prev;
}

//双向链表的销毁
void ListDestory(ListNode* list){
	ListNode* cur = list->next;
	while (cur != list){
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(list);
}