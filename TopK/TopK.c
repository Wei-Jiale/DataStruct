#include<stdio.h>
#include<malloc.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>

typedef int HpDataType;
typedef struct Heap{
	HpDataType* _a;
	int      _size;
	int      _capacity;
}Heap;

//���µ����㷨��С�ѣ� 
void AdjustDown(HpDataType* a, int n, int root){
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n){
		// �ҳ�С���Ǹ���ֽ
		// Ĭ������С
		// ����Һ���С�������� child++
		if (child + 1 < n && a[child + 1] < a[child]){
			++child;
		}

		// 1����ֽ�ȸ���С���򽻻����������µ�
		// 2����ֽ�ȸ��״�����ֹ����
		if (a[parent] > a[child]){
			HpDataType tmp = a[parent];
			a[parent] = a[child];
			a[child] = tmp;

			// ���´���
			parent = child;
			child = parent * 2 + 1;
		}
		else{
			break;
		}
	}
}

//���ѣ���һ�����������ת��Ϊ����ѵ�����
void HeapCreate(Heap*hp, HpDataType* a, int n){
	hp->_a = (HpDataType*)malloc(sizeof(HpDataType)*n);
	memcpy(hp->_a, a, sizeof(HpDataType)*n);
	hp->_size = n;
	hp->_capacity = n;

	// ����
	// �����һ����Ҷ�ӽ�㣨���һ�����ĸ��ڵ㣩��ʼ���µ���
	for (int i = (n - 1 - 1) / 2; i >= 0; --i){
		AdjustDown(hp->_a, hp->_size, i);
	}
}

//���ϵ���
void AdjustUp(HpDataType* a, int child){
	int parent = (child - 1) / 2;
	while (child > 0){
		if (a[child]<a[parent]){
			HpDataType tmp = a[parent];
			a[parent] = a[child];
			a[child] = tmp;

			child = parent;
			parent = (child - 1) / 2;
		}
		else{
			break;
		}
	}
}

//���
void HeapPush(Heap* hp, HpDataType x){
	//����
	if (hp->_size == hp->_capacity){
		size_t newcapacity = hp->_capacity * 2;
		hp->_a = (HpDataType*)realloc(hp->_a, sizeof(HpDataType)*newcapacity);
		hp->_capacity = newcapacity;
	}

	hp->_a[hp->_size] = x;
	hp->_size++;

	// ���ϵ��� ���ɶ�
	AdjustUp(hp->_a, hp->_size - 1);
}

//����
void HeapPop(Heap* hp){
	//�Ѷ�Ԫ�غ����һ��Ԫ�ػ���
	HpDataType temp = hp->_a[0];
	hp->_a[0] = hp->_a[hp->_size - 1];
	hp->_a[hp->_size - 1] = temp;

	hp->_size--;

	//���µ����ɶ�
	AdjustDown(hp->_a, hp->_size, 0);
}

//��ȡ�Ѷ�Ԫ��
HpDataType HeapTop(Heap* hp){
	return hp->_a[0];
}

//��ӡ��
void HeapPrint(Heap* hp){
	for (int i = 0; i < hp->_size; ++i){
		printf("%d ", hp->_a[i]);
	}

	printf("\n");
}

// TopK����
void PrintTopK(int* a, int n, int k){
	// k������С��
	Heap hp;
	HeapCreate(&hp, a, k);

	for (int i = k; i < n; ++i){
		// �ȶѶ�������Ҫ�󣬾������
		if (HeapTop(&hp) < a[i]){
			HeapPop(&hp);
			HeapPush(&hp, a[i]);
		}
	}

	HeapPrint(&hp);
}

int main(){
	int n = 10000;
	int* a = (int*)malloc(sizeof(int)*n);

	srand(time(0));

	for (int i = 0; i < n; ++i){
		a[i] = rand() % 1000000;
	}

	a[15] = 1000000 + 1;
	a[1231] = 1000000 + 2;
	a[531] = 1000000 + 3;
	a[5121] = 1000000 + 4;
	a[115] = 1000000 + 5;
	a[2335] = 1000000 + 6;
	a[9999] = 1000000 + 7;
	a[760] = 1000000 + 8;
	a[423] = 1000000 + 9;
	a[3144] = 1000000 + 10;

	PrintTopK(a, n, 10);

	return 0;
}