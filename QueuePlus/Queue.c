#include"Queue.h"

//队列的初始化
void QueueInit(Queue* q){
	assert(q);
	q->front = q->back = NULL;
}

//入队列
void QueuePush(Queue* q, QDataType data){
	assert(q);
	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
	newNode->data = data;
	newNode->next = NULL;

	if (q->back == NULL){
		q->front = q->back = newNode;
	}
	else{
		q->back->next = newNode;
		q->back = newNode;
	}
}

//出队列
void QueuePop(Queue* q){
	assert(q);

	if (q->front->next == NULL){
		free(q->front);
		q->front = q->back = NULL;
	}
	else{
		QueueNode* next = q->front->next;
		free(q->front);
		q->front = next;
	}
}

//获取队列头部元素
QDataType QueueFront(Queue* q){
	assert(q);
	return q->front->data;
}

//获取队列尾部元素
QDataType QueueBack(Queue* q){
	assert(q);
	return q->back->data;
}

//获取队列中有效元素个数
int QueueSize(Queue* q){
	int size = 0;
	QueueNode* cur = q->front;
	while (cur){
		size++;
		cur = cur->next;
	}

	return size;
}

//检测队列是否为空
int QueueEmpty(Queue* q){
	return q->front == NULL ? 1 : 0;
}

//销毁队列
void QueueDestroy(Queue* q){
	QueueNode* cur = q->front;
	while (cur){
		QueueNode* next = cur->next;
		free(cur);
		cur = next;
	}

	q->front = q->back = NULL;
}