#include "SeqList.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//ȷ���������ã������Ҫ���ݾ�����
//static Ӱ�캯�����������ԣ����ⲿ�������Ը�Ϊ�ڲ������.c�ļ��޷����ã�
//O(n)
static void CheckCapacity(SeqList *ps){
	if (ps->size < ps->capacity){
		return;
	}
	//��Ҫ����
	int newCapacity = ps->capacity * 2;
	int *newArray = (int*)malloc(sizeof(int)*newCapacity);
	assert(newArray != NULL);

	//����
	for (int i = 0; i < ps->size; i++){
		newArray[i] = ps->array[i];
	}

	//�ͷ��Ͽռ�
	free(ps->array);
	ps->array = newArray;
	ps->capacity = newCapacity;
}



void SeqListInit(SeqList *ps,int capacity){
	//ps �����Ǳ����ĵ�ַ


	ps->array = malloc(sizeof(int) * capacity);//����ռ��С
	assert(ps->array != NULL);
	ps->size = 0;
	ps->capacity = capacity;
}

void SeqListDestroy(SeqList *ps){

	//�ͷ� array �Ŀռ�
	free(ps->array);

	//������
	ps->array = NULL;
	ps->size = 0;
	ps->capacity = 0;

}

//O(1)  ���ݹ�ģsize  ����ָ���size�޹�   �������ݱ�O��n��
void SeqListPushBack(SeqList *ps, int v){
	CheckCapacity(ps);
	ps->array[ps->size] = v;
	ps->size++;
}


//O(n)  
void SeqListPushFront(SeqList *ps, int v){
	CheckCapacity(ps);
	//i��ʾ�ռ��±�
	for (int i = ps->size; i >= 1; i--){
		ps->array[i] = ps->array[i - 1];
	}
	ps->array[0] = v;
	ps->size++;
}


//O(n)
void SeqListInsert(SeqList *ps, int pos, int v){
	CheckCapacity(ps);
	//pos = 0Ϊͷ��  pos = sizeΪβ��
	assert(pos >= 0 && pos <= ps->size);
	//i�������ݵ��±�
	for (int i = ps->size - 1; i >= pos; i--){
		ps->array[i + 1] = ps->array[i];
	}

	ps->array[pos] = v;
	ps->size++;
}

//O(1)
void SeqListPopBack(SeqList *ps){
	assert(ps->size > 0);
	ps->size--;
}

//O(n)
void SeqListPopFront(SeqList *ps){
	assert(ps->size > 0);
	//i����ռ���±�
	for (int i = 0; i <= ps->size - 2; i++){
		ps->array[i] = ps->array[i + 1];
	}
	ps->size--;
}

//O(n)
void SeqListErase(SeqList *ps, int pos){
	assert(ps->size > 0);
	assert(pos >= 0 && pos < ps->size);
	//i�������ݵ��±�
	for (int i = pos + 1; i <= ps->size - 1; i++){
		ps->array[i - 1] = ps->array[i];
	}
	ps->size--;
}

int SeqListFind(SeqList *ps, int v){
	for (int i = 0; i < ps->size; i++){
		if (ps->array[i] = v){
			return i;
		}
	}
	return -1;
}

void SeqListModify(SeqList *ps, int pos, int v){
	assert(pos >= 0 && pos < ps->size);
	ps->array[pos] = v;
}

//O(n)
int SeqListRemove(SeqList *ps, int v){
	int pos = SeqListFind(ps, v);
	if (pos = -1){
		return;
	}

	SeqListErase(ps, pos);

}


int SeqListRemoveAll(SeqList *ps, int v){
	int i, j;
	for (i = 0, j = 0; i < ps->size; i++){
		if (ps->array[i] != v){
			ps->array[j] = ps->array[i];
			j++;
		}
	}
	ps->size = j;
}
