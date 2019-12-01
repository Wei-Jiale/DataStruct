#include"seqlist.h"
//��ʼ��
void SeqlistInit(Seqlist*ps){
	assert(ps);

	ps->array = 0;
	ps->size = 0;
	ps->capacity = 0;
}

//����
void SeqlistDestory(Seqlist*ps){
	assert(ps);

	free(ps->array);
	ps->array = NULL;
	ps->size = ps->capacity = 0;
}

//��ӡ
void Print(Seqlist*ps){
	for (size_t i = 0; i < ps->size; i++){
		printf("%d ", ps->array[i]);
	}
	printf("\n");
}

//����
void CheckCapacity(Seqlist*ps){
	if (ps->size == ps->capacity){
		size_t newcapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		ps->array = (SLDatetype*)realloc(ps->array, newcapacity*sizeof(SLDatetype));
		ps->capacity = newcapacity;
	}
}

//ͷ��
void PushFront(Seqlist*ps, SLDatetype x){
	CheckCapacity(ps);
	for (size_t i = ps->size; i >= 1; i--){
		ps->array[i] = ps->array[i - 1];
	}
	ps->array[0] = x;
	ps->size++;
}

//β��
void PushBack(Seqlist*ps, SLDatetype x){
	assert(ps);

	CheckCapacity(ps);
	ps->array[ps->size] = x;
	ps->size++;
}

//ͷɾ
void PopFront(Seqlist*ps){
	assert(ps);

	for (size_t i = 0; i < ps->size - 1; i++){
		ps->array[i] = ps->array[i + 1];
	}
	ps->size--;
}

//βɾ
void PopBack(Seqlist*ps){
	assert(ps);

	ps->size--;
}

//����
int SeqlistFind(Seqlist*ps, SLDatetype x){
	for (size_t i = 0; i < ps->size; i++){
		if (ps->array[i] == x){
			return i;
		}
	}
	return -1;
}

//��posλ�ò���
void SeqlistInsert(Seqlist*ps, size_t pos, SLDatetype x){
	CheckCapacity(ps);

	assert(ps);
	assert(pos <= ps->size);

	for (size_t i = ps->size; i > pos; i--){
		ps->array[i] = ps->array[i - 1];
	}
	ps->array[pos] = x;
	ps->size++;
}

//��posλ��ɾ��
void SeqlistErase(Seqlist*ps, size_t pos){
	assert(ps&&pos < ps->size);

	for (size_t i = pos; i < ps->size - 1; i++){
		ps->array[i] = ps->array[i + 1];
	}
	ps->size--;
}


void Test(){
	Seqlist seqlist;
	SeqlistInit(&seqlist);

	PushBack(&seqlist, 1);
	PushBack(&seqlist, 2);
	PushBack(&seqlist, 3);
	PushBack(&seqlist, 4);
	PushBack(&seqlist, 5);
	Print(&seqlist);

	//SeqlistDestory(&seqlist);
	//Print(&seqlist);

	PushFront(&seqlist, 0);
	Print(&seqlist);

	PopBack(&seqlist);
	Print(&seqlist);

	PopFront(&seqlist);
	Print(&seqlist);

	SeqlistInsert(&seqlist, 0, 0);
	Print(&seqlist);

	SeqlistErase(&seqlist, 0, 0);
	Print(&seqlist);

	int ret = SeqlistFind(&seqlist, 2);
	printf("%d\n", ret);
}