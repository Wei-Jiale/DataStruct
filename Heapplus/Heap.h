#pragma once
#include<stdio.h>
#include<string.h>
#include<malloc.h>

typedef int HpDataType;
typedef struct Heap{
	HpDataType* _a;//����
	size_t _size;//�����С
	size_t _capacity;//��������
}Heap;


//���µ���
void AdjustDown(HpDataType* a, size_t n, int root);

//����:��һ������������Ϊ����ѵ�����
void HeapCreate(Heap* hp, HpDataType* _a, size_t n);

//���ϵ���
void AdjustUp(HpDataType* a, int child);

//���
void HeapPush(Heap* hp, HpDataType x);

//����
void HeapPop(Heap* hp);

//��ȡ�Ѷ�Ԫ��
HpDataType HeapTop(Heap* hp);

//�ж϶��Ƿ�Ϊ��
int HeapEmpty(Heap* hp);

//��ӡ��
void HeapPrint(Heap* hp);

//������
void HeapDestory(Heap* hp);
