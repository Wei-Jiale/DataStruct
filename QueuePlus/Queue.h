#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdbool.h>

typedef int QDataType;

//结点
typedef struct QueueNode{
	QDataType data;
	struct QueueNode* next;

}QueueNode;

//队首和队尾
typedef struct Queue{
	struct QueueNode* front;
	struct QueueNode* back;

}Queue;

//队列的初始化
void QueueInit(Queue* q);

//入队列
void QueuePush(Queue* q, QDataType data);

//出队列
void QueuePop(Queue* q);

//获取队列头部元素
QDataType QueueFront(Queue* q);

//获取队列尾部元素
QDataType QueueBack(Queue* q);

//获取队列中有效元素个数
int QueueSize(Queue* q);

//检测队列是否为空
int QueueEmpty(Queue* q);

//销毁队列
void QueueDestroy(Queue* q);