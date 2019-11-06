#pragma once

////��̬˳���
//typedef struct SeqList{
//	int array[100];
//	int size;//˳�����ʵ�ʴ洢�����ݸ���
//}SeqList;//����


//��̬˳���
typedef struct SeqList{
	int* array;//��̬�Ӷ�������
	int capacity;//����
	int size;//��Ч���ݵĸ���  β��ʱ������λ�õ��±�
}SeqList;

//��ʼ��
void SeqListInit(SeqList *ps,int capacity);

//����
void SeqListDestroy(SeqList *ps);

//��ɾ���
//β��
void SeqListPushBack(SeqList *ps, int v);
//ͷ��
void SeqListPushFront(SeqList *ps, int v);
//����pos�±����
void SeqListInsert(SeqList *ps, int pos, int v);

//βɾ
void SeqListPopBack(SeqList *ps);

//ͷɾ
void SeqListPopFront(SeqList *ps);

//����pos�±�ɾ��
void SeqListErase(SeqList *ps, int pos);

//����
int SeqListFind(SeqList *ps, int v);

//����
void SeqListModify(SeqList *ps, int pos, int v);

//ɾ����һ��������v
int SeqListRemove(SeqList *ps, int v);

//ɾ������������v
int SeqListRemoveAll(SeqList *ps, int v);



