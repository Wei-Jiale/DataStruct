#pragma once
#include<stdio.h>
#include<stdbool.h>
//结点
typedef struct Node{
	int value;
	struct Node* next;
}Node;

//队列
typedef struct{
	Node*head;//队首
	Node*last;//队尾
}Queue;

//初始化
void QueueInit(Queue *q){
	q->head = q->last = NULL;
}

//进入(尾插)
void QueuePush(Queue *q, int v){
	Node *node = (Node*)malloc(sizeof(Node));
	node->value = v;
	node->next = NULL;
	if (q->head == NULL){
		q->head = node;
	}
	else{
		q->last->next = node;
		q->last = node;
	}
}

//删除（头删）
void QueuePop(Queue*q){
	Node*second = q->head->next;
	free(q->head);
	q->head = second;
	if (q->head == NULL){
		q->last == NULL;
	}
}

//返回队首元素
int QueueFront(Queue*q){
	return q->head->value;
}

//队列大小
int QueueSize(Queue *q){
	int size = 0;
	for (Node*n = q->head; n != NULL; n = n->next){
		size++;
	}
	return size;
}

//判断队列是否为空
bool QueueEmpty(Queue *q){
	return q->head == NULL;
}
