#include <stdio.h>
#include<assert.h>
#include<stdlib.h>
//���ѣ���һ����ȫ���������ֲ�������������ѵ�����
//���������������Ƕ� ֱ�ӶԸ������µ���
//�ȶ�������������
//�����һ����Ҷ�ӽ��������µ���
//���һ������±�size-1
//parent = (child-1)/2
//���һ����Ҷ�ӽ���±�(size-2)/2

void AdjustDown(int tree[], int size, int rootIdx){//���飬size��Ҫ�����Ľ���±�
	//�ж�rootIdx�ǲ���Ҷ��
	//û�����Һ���
	//��ȫ������û�����Ӿ�һ��û���Һ���
	//��Ϊ����������ж������±��Ƿ�Խ��
	int leftIdx = 2 * rootIdx + 1;
	int rightIdx = 2 * rootIdx + 2;
	if (leftIdx >= size){
		return;
	}

	//����Ҷ��
	//�ҵ���С��һ�����Ӻ͸��Ƚ�
	//������Һ��ӱȽ�����
	//����ֱ�������ӱȽ�
	int minIdx = leftIdx;
	if (rightIdx < size&&tree[rightIdx] < tree[leftIdx]){
		minIdx = rightIdx;
	}

	if (tree[rootIdx] <= tree[minIdx]){
		//��С�Ѿ��Ǹ�
		return;
	}

	int temp = tree[minIdx];
	tree[minIdx] = tree[rootIdx];
	tree[rootIdx] = temp;

	//����֮�� �������Ķ����ʿ��ܱ��ƻ� ��������
	AdjustDown(tree, size, minIdx);
}


void CreatHeap(int tree[], int size){
	for (int i = (size - 2) / 2; i >= 0; i--){
		AdjustDown(tree, size, i);
	}
}

typedef struct Heap{
	int tree[100];
	int size;
}	Heap;

//�ѳ�ʼ��
void HeapInit(Heap*pH, int array[], int size){
	assert(size <= 100);
	memcpy(pH->tree, array, size*sizeof(int));
	pH->size = size;
	CreatHeap(pH->tree, pH->size);
}

//���ѵ�ǰ��Сֵ
int HeapPop(Heap*pH){
	int v = pH->tree[0];
	pH->tree[0] = pH->tree[pH->size - 1];
	pH->size --;
	AdjustDown(pH->tree, pH->size, 0);

	return v;
}
//���(���ϵ�����
void AdjustUp(int tree[], int size, int child){
	if (child == 0){
		return;
	}

	int parent = (child - 1) / 2;
	if (tree[child] >= tree[parent]){
		return;
	}
	int temp = tree[child];
	tree[child] = tree[parent];
	tree[parent] = temp;

	AdjustUp(tree, size, parent);
}
void HeapPush(Heap*pH,int v){
	pH->tree[pH->size++] = v;
	AdjustUp(pH->tree, pH->size, pH->size - 1);
}

int main(){
	int array[] = { 9, 5, 7, 3, 8, 4, 2, 1, 0 };
	int size = sizeof(array) / sizeof(array[0]);
	Heap heap;
	HeapInit(&heap, array, size);

	for (int i = 0; i < 3; i++){
		printf("%d\n", HeapPop(&heap));
	}
	printf("After pop\n");
	for (int i = 0; i < 3; i++){
		HeapPush(&heap, i);
	}
	printf("After push\n");

	int sizes = heap.size;
	for (int i = 0; i < sizes; i++){
		printf("%d\n", HeapPop(&heap));
	}
}

