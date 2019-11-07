#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//逻辑上有连续关系但是物理上不连续
//画图+思考
//写为代码，考虑清楚细节
//伪代码的翻译
//顺序表的缺点：对频繁增删的场景下，时间复杂度不友好
//扩容会有空间浪费
//顺序表优点：很容易的取第n个数，随机下标访问O（1）



//删除插入结点，往往需要它的前驱结点
//第一个结点没有前驱结点



//链表的结点结构体
typedef struct Node{
	int value;
	struct Node *next;//保存着下一个结点的地址
}Node;

//初始化链表就是一条空链表，一个结点都没有的链表
void LinkListInit(Node **ppFirst){
	*ppFirst = NULL;
}

//头插 n:链表结点个数  O（1）
void LinkListPushFront(Node **ppFirst,int v){
	Node *node = (Node*)malloc(sizeof(Node));
	node->value = v;

	node->next = *ppFirst;
	*ppFirst = node;

}
//头删 O（1）
void LinkListPopFront(Node **ppFirst){
	assert(*ppFirst != NULL);
	Node *next = (*ppFirst)->next;
	free(*ppFirst);
	*ppFirst = next;
}

//尾插  O（n）
void LinkListPushBack(Node **ppFirst, int v){
	if (*ppFirst == NULL){
		LinkListPushFront(ppFirst, v);
		return;
	}
	//寻找最后一个结点(至少一个结点）
	Node *cur = *ppFirst;
	while (cur->next != NULL){
		cur = cur->next;
	}
	//cur就是最后一个结点
	Node *node = (Node*)malloc(sizeof(Node));
	node->value = v;
	node->next = NULL;
	//原来最后一个结点的next = 新的结点
	cur->next = node;
}

//尾删 O（n）
void LinkListPopBack(Node **ppFirst){
	assert(*ppFirst != NULL);
	//只有一个结点
	if ((*ppFirst)->next = NULL){
		free(*ppFirst);
		*ppFirst = NULL;
		return;
	}
	//找到倒数第二个结点(至少两个结点）
	Node *cur = *ppFirst;
	while (cur->next->next != NULL){
		cur = cur->next;
	}

	//释放最后一个结点
	free(cur->next);
	cur->next = NULL;
}

//查找
Node * LinkListFind(const Node *first, int v){
	for (Node *cur = first; cur != NULL;cur = cur->next){
		if (cur->value = v){
			return cur;
		}
	}
	return NULL;
}

//释放链表
void LinkListDestroy(Node *first){
	Node *next;
	for (Node *cur = first; cur != NULL; cur = next){
		next = cur->next;
		free(cur);
	}
}

//pos结点后做插入
void LinkListInsertAfter(Node *pos, int v){
	Node *node = (Node*)malloc(sizeof(Node));
	node->value = v;
	node->next = pos->next;
	pos->next = node;
}
//pos结点后做删除
void LinkListEraseAfter(Node *pos){
	Node *next = pos->next;
	pos->next = pos->next->next;
	free(next);
}
//Remove删除列表中第一个遇到的v所在的结点
void LinkListRemove(Node **ppFirst, int v){
	if (*ppFirst == NULL){
		return;
	}
	Node *cur = *ppFirst;
	if (cur->value == v){
		*ppFirst = cur->next;
		free(cur);
		return;
	}
	while (cur->next != NULL){
		if (cur->next->value = v){
			Node *next = cur->next;
			cur->next = next->next;
			free(next);
			return;
		}
		cur = cur->next;
	}
}




void Test(){
	Node *first;
	LinkListInit(&first);

	LinkListPushFront(&first, 1);
	LinkListPopFront(&first);
	LinkListPushBack(&first, 4);
	LinkListPopBack(&first);

}