#include"slist.h"

//打印
void SListPrint(SListNode* pList){
	SListNode* cur = pList;
	while (cur != NULL){
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

//尾插
void SListPushBack(SListNode** ppList, SLDataType x){
	//新结点申请空间
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	//将x赋给新结点的数据域
	newNode->data = x;
	//尾插 所以新结点的指针域为NULL
	newNode->next = NULL;
	
	//考虑链表为空的情况
	if (*ppList == NULL){
		*ppList = newNode;
	}
	else{
		//找到最后一个结点
		SListNode* cur = *ppList;
		while (cur->next != NULL){
			cur = cur->next;
		}
		//最后一个结点的指针域为新结点
		cur->next = newNode;
	}
}

//头插
void SListPushFront(SListNode** ppList, SLDataType x){
	//新结点申请空间
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	//将x赋给新结点的数据域
	newNode->data = x;
	//头插所以新结点指针域为原链表的第一个结点地址
	newNode->next = *ppList;

	//改变pplist的指向 指向新链表的头结点
	*ppList = newNode;
}

//尾删
void SListPopBack(SListNode** ppList){
	//删除最后一个结点
	//意味着使倒数第二个结点指针域为NULL

	//注意考虑链表为空
	if (*ppList == NULL){
		return NULL;
	}
	//注意考虑链表只有一个结点
	else if ((*ppList)->next == NULL){
		free(*ppList);
		*ppList = NULL;
	}
	//找到倒数第二个结点
	else{
		SListNode* cur = *ppList;
		while (cur->next->next != NULL){
			cur = cur->next;
		}

		//释放最后一个结点
		free(cur->next);
		//改变指向
		cur->next = NULL;
	}
}

//头删
void SListPopFront(SListNode** ppList){
	//注意考虑链表为空
	if (*ppList == NULL){
		return NULL;
	}
	//链表有多个结点
	else{
		SListNode* next = (*ppList)->next;
		free(*ppList);
		*ppList = next;
	}
}

//查找
SListNode* SListFind(SListNode* pList, SLDataType x){
	SListNode* cur = pList;
	while (cur != NULL){
		cur = cur->next;
		if (cur->data == x){
			return cur;
		}
	}
	return NULL;
}

//pos结点后做插入
void SListInsertAfter(SListNode* pos, SLDataType x){
	//新结点申请空间
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	//将x赋给新结点的数据域
	newNode->data = x;
	newNode->next = pos->next;

	pos->next = newNode;
}

//pos结点之后做删除
void SListEraseAfter(SListNode* pos){
	SListNode* next = pos->next;
	pos->next = next->next;
	free(next);
}

//单链表的销毁
void SListDestory(SListNode* pList){
	SListNode* cur = pList;
	SListNode* next;
	for (cur; cur != NULL; cur = next){
		next = cur->next;
		free(cur);
	}
}

