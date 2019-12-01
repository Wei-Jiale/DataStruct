#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
//����
typedef int SLDatetype;

typedef struct Seqlist{
	SLDatetype *array;
	size_t size;
	size_t capacity;
}	Seqlist;

//��ʼ��
void SeqlistInit(Seqlist*ps);

//����
void SeqlistDestory(Seqlist*ps);

//��ӡ
void Print(Seqlist*ps);

//����
void CheckCapacity(Seqlist*ps);

//ͷ��
void PushFront(Seqlist*ps, SLDatetype x);

//β��
void PushBack(Seqlist*ps, SLDatetype x);

//ͷɾ
void PopFront(Seqlist*ps);

//βɾ
void PopBack(Seqlist*ps);

//����
int SeqlistFind(Seqlist*ps, SLDatetype x);

//��posλ�ò���
void SeqlistInsert(Seqlist*ps, size_t pos, SLDatetype x);

//��posλ��ɾ��
void SeqlistErase(Seqlist*ps, size_t pos);