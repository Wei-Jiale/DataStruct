#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdbool.h>

typedef int QDataType;

//���
typedef struct QueueNode{
	QDataType data;
	struct QueueNode* next;

}QueueNode;

//���׺Ͷ�β
typedef struct Queue{
	struct QueueNode* front;
	struct QueueNode* back;

}Queue;

//���еĳ�ʼ��
void QueueInit(Queue* q);

//�����
void QueuePush(Queue* q, QDataType data);

//������
void QueuePop(Queue* q);

//��ȡ����ͷ��Ԫ��
QDataType QueueFront(Queue* q);

//��ȡ����β��Ԫ��
QDataType QueueBack(Queue* q);

//��ȡ��������ЧԪ�ظ���
int QueueSize(Queue* q);

//�������Ƿ�Ϊ��
int QueueEmpty(Queue* q);

//���ٶ���
void QueueDestroy(Queue* q);