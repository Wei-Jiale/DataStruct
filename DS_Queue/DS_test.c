#pragma once
#include<stdio.h>
#include<stdbool.h>
//���
typedef struct Node{
	int value;
	struct Node* next;
}Node;

//����
typedef struct{
	Node*head;//����
	Node*last;//��β
}Queue;

//��ʼ��
void QueueInit(Queue *q){
	q->head = q->last = NULL;
}

//����(β��)
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

//ɾ����ͷɾ��
void QueuePop(Queue*q){
	Node*second = q->head->next;
	free(q->head);
	q->head = second;
	if (q->head == NULL){
		q->last == NULL;
	}
}

//���ض���Ԫ��
int QueueFront(Queue*q){
	return q->head->value;
}

//���д�С
int QueueSize(Queue *q){
	int size = 0;
	for (Node*n = q->head; n != NULL; n = n->next){
		size++;
	}
	return size;
}

//�ж϶����Ƿ�Ϊ��
bool QueueEmpty(Queue *q){
	return q->head == NULL;
}
