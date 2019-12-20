#include"Queue.h"

//���еĳ�ʼ��
void QueueInit(Queue* q){
	assert(q);
	q->front = q->back = NULL;
}

//�����
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

//������
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

//��ȡ����ͷ��Ԫ��
QDataType QueueFront(Queue* q){
	assert(q);
	return q->front->data;
}

//��ȡ����β��Ԫ��
QDataType QueueBack(Queue* q){
	assert(q);
	return q->back->data;
}

//��ȡ��������ЧԪ�ظ���
int QueueSize(Queue* q){
	int size = 0;
	QueueNode* cur = q->front;
	while (cur){
		size++;
		cur = cur->next;
	}

	return size;
}

//�������Ƿ�Ϊ��
int QueueEmpty(Queue* q){
	return q->front == NULL ? 1 : 0;
}

//���ٶ���
void QueueDestroy(Queue* q){
	QueueNode* cur = q->front;
	while (cur){
		QueueNode* next = cur->next;
		free(cur);
		cur = next;
	}

	q->front = q->back = NULL;
}