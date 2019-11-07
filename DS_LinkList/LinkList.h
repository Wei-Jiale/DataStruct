#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//�߼�����������ϵ���������ϲ�����
//��ͼ+˼��
//дΪ���룬�������ϸ��
//α����ķ���
//˳����ȱ�㣺��Ƶ����ɾ�ĳ����£�ʱ�临�ӶȲ��Ѻ�
//���ݻ��пռ��˷�
//˳����ŵ㣺�����׵�ȡ��n����������±����O��1��



//ɾ�������㣬������Ҫ����ǰ�����
//��һ�����û��ǰ�����



//����Ľ��ṹ��
typedef struct Node{
	int value;
	struct Node *next;//��������һ�����ĵ�ַ
}Node;

//��ʼ���������һ��������һ����㶼û�е�����
void LinkListInit(Node **ppFirst){
	*ppFirst = NULL;
}

//ͷ�� n:���������  O��1��
void LinkListPushFront(Node **ppFirst,int v){
	Node *node = (Node*)malloc(sizeof(Node));
	node->value = v;

	node->next = *ppFirst;
	*ppFirst = node;

}
//ͷɾ O��1��
void LinkListPopFront(Node **ppFirst){
	assert(*ppFirst != NULL);
	Node *next = (*ppFirst)->next;
	free(*ppFirst);
	*ppFirst = next;
}

//β��  O��n��
void LinkListPushBack(Node **ppFirst, int v){
	if (*ppFirst == NULL){
		LinkListPushFront(ppFirst, v);
		return;
	}
	//Ѱ�����һ�����(����һ����㣩
	Node *cur = *ppFirst;
	while (cur->next != NULL){
		cur = cur->next;
	}
	//cur�������һ�����
	Node *node = (Node*)malloc(sizeof(Node));
	node->value = v;
	node->next = NULL;
	//ԭ�����һ������next = �µĽ��
	cur->next = node;
}

//βɾ O��n��
void LinkListPopBack(Node **ppFirst){
	assert(*ppFirst != NULL);
	//ֻ��һ�����
	if ((*ppFirst)->next = NULL){
		free(*ppFirst);
		*ppFirst = NULL;
		return;
	}
	//�ҵ������ڶ������(����������㣩
	Node *cur = *ppFirst;
	while (cur->next->next != NULL){
		cur = cur->next;
	}

	//�ͷ����һ�����
	free(cur->next);
	cur->next = NULL;
}

//����
Node * LinkListFind(const Node *first, int v){
	for (Node *cur = first; cur != NULL;cur = cur->next){
		if (cur->value = v){
			return cur;
		}
	}
	return NULL;
}

//�ͷ�����
void LinkListDestroy(Node *first){
	Node *next;
	for (Node *cur = first; cur != NULL; cur = next){
		next = cur->next;
		free(cur);
	}
}

//pos����������
void LinkListInsertAfter(Node *pos, int v){
	Node *node = (Node*)malloc(sizeof(Node));
	node->value = v;
	node->next = pos->next;
	pos->next = node;
}
//pos������ɾ��
void LinkListEraseAfter(Node *pos){
	Node *next = pos->next;
	pos->next = pos->next->next;
	free(next);
}
//Removeɾ���б��е�һ��������v���ڵĽ��
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