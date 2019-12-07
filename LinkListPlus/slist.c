#include"slist.h"

//��ӡ
void SListPrint(SListNode* pList){
	SListNode* cur = pList;
	while (cur != NULL){
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

//β��
void SListPushBack(SListNode** ppList, SLDataType x){
	//�½������ռ�
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	//��x�����½���������
	newNode->data = x;
	//β�� �����½���ָ����ΪNULL
	newNode->next = NULL;
	
	//��������Ϊ�յ����
	if (*ppList == NULL){
		*ppList = newNode;
	}
	else{
		//�ҵ����һ�����
		SListNode* cur = *ppList;
		while (cur->next != NULL){
			cur = cur->next;
		}
		//���һ������ָ����Ϊ�½��
		cur->next = newNode;
	}
}

//ͷ��
void SListPushFront(SListNode** ppList, SLDataType x){
	//�½������ռ�
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	//��x�����½���������
	newNode->data = x;
	//ͷ�������½��ָ����Ϊԭ����ĵ�һ������ַ
	newNode->next = *ppList;

	//�ı�pplist��ָ�� ָ���������ͷ���
	*ppList = newNode;
}

//βɾ
void SListPopBack(SListNode** ppList){
	//ɾ�����һ�����
	//��ζ��ʹ�����ڶ������ָ����ΪNULL

	//ע�⿼������Ϊ��
	if (*ppList == NULL){
		return NULL;
	}
	//ע�⿼������ֻ��һ�����
	else if ((*ppList)->next == NULL){
		free(*ppList);
		*ppList = NULL;
	}
	//�ҵ������ڶ������
	else{
		SListNode* cur = *ppList;
		while (cur->next->next != NULL){
			cur = cur->next;
		}

		//�ͷ����һ�����
		free(cur->next);
		//�ı�ָ��
		cur->next = NULL;
	}
}

//ͷɾ
void SListPopFront(SListNode** ppList){
	//ע�⿼������Ϊ��
	if (*ppList == NULL){
		return NULL;
	}
	//�����ж�����
	else{
		SListNode* next = (*ppList)->next;
		free(*ppList);
		*ppList = next;
	}
}

//����
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

//pos����������
void SListInsertAfter(SListNode* pos, SLDataType x){
	//�½������ռ�
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	//��x�����½���������
	newNode->data = x;
	newNode->next = pos->next;

	pos->next = newNode;
}

//pos���֮����ɾ��
void SListEraseAfter(SListNode* pos){
	SListNode* next = pos->next;
	pos->next = next->next;
	free(next);
}

//�����������
void SListDestory(SListNode* pList){
	SListNode* cur = pList;
	SListNode* next;
	for (cur; cur != NULL; cur = next){
		next = cur->next;
		free(cur);
	}
}

