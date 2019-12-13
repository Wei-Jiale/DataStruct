#include"Double.h"

//�������������ͷ���
ListNode* ListCreat(){
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	//��ͷ˫��ѭ��
	head->next = head;
	head->prev = head;

	return head;
}

//˫�������β��
void ListPushBack(ListNode* list, LTDataType x){
	//�����½��
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

//˫������Ĵ�ӡ
void ListPrint(ListNode* list){
	ListNode* cur = list->next;

	while (cur != list){
		printf("%d ",cur->data);
		cur = cur->next;
	}
	printf("\n");
}

//˫�������βɾ
void ListPopBack(ListNode* list){
	//��β�͵����ڶ���
	ListNode* tail = list->prev;
	ListNode* prev = tail->prev;

	free(tail);
	prev->next = list;
	list->prev = prev;
	
}

//˫�������ͷ��
void ListPushFront(ListNode* list, LTDataType x){
	//�����½��
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

//˫�������ͷɾ
void ListPopFront(ListNode* list){
	assert(list->next != list);
	//�ҵ��ڶ������
	ListNode* node = list->next->next;

	list->next = node;
	node->prev = list;
}

//˫������Ĳ���
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

//˫��������pos֮ǰ����
void ListInsert(ListNode* pos, LTDataType x){
	//�����½��
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

//˫������ɾ��posλ�ý��
void ListErase(ListNode* pos){
	//�ҵ�posλ����һ�����
	ListNode* next = pos->next;
	//�ҵ�posλ��ǰһ�����
	ListNode* prev = pos->prev;

	free(pos);
	prev->next = next;
	next->prev = prev;
}

//˫�����������
void ListDestory(ListNode* list){
	ListNode* cur = list->next;
	while (cur != list){
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(list);
}