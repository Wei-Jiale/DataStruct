#include"Heap.h"

//���µ����㷨��С�ѣ� 
void AdjustDown(HpDataType* a, size_t n, int root){
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
void HeapCreate(Heap*hp, HpDataType* a, size_t n){
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

//�ж϶��Ƿ�Ϊ��
int HeapEmpty(Heap* hp){
	return hp->_size == 0 ? 1 : 0;
}

//��ӡ��
void HeapPrint(Heap* hp){
	for (int i = 0; i < hp->_size; ++i){
		printf("%d ", hp->_a[i]);
	}

	printf("\n");
}

//������
void HeapDestory(Heap* hp){
	free(hp->_a);
	hp->_size = hp->_capacity = 0;
	hp->_a = NULL;
}
