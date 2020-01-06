#include<stdio.h>
//ѡ�����򣨶�����
//���ȶ�
//���µ���
//1.���Һ�����ֵ�ϴ��(1)û���Һ���(2)���Һ���
//2.����ֵ�͸���ֵ���Ƚ�
//3.�������ֵ>���ӵ�ֵ ֹͣ
//4.���򽻻� �������µ���
//5.��Ҷ�ӾͿ���ͣ��
void Swap(int array[], int i, int j){
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

void Heapify(int array[], int size, int rIdx){
	while (1){
		int leftIdx = 2 * rIdx + 1;
		int rightIdx = 2 * rIdx + 2;
		if (leftIdx >= size){
			return;
		}

		int maxIdx;
		if (rightIdx >= size){
			maxIdx = leftIdx;
		}
		else if (array[leftIdx] >= array[rightIdx]){
			maxIdx = leftIdx;
		}
		else{
			maxIdx = rightIdx;
		}

		if (array[maxIdx] <= array[rIdx]){
			return;
		}
		else{
			Swap(array, maxIdx, rIdx);
		}
		rIdx = maxIdx;
	}
}

void CreateHeap(int array[], int size){
	for (int i = (size - 1 - 1) / 2; i >= 0; i--){
		Heapify(array, size, i);
	}
}

void HeapSort(int array[], int size){
	CreateHeap(array, size);
	for (int i = 0; i < size; i++){
		Swap(array, 0, size - 1 - i);
		Heapify(array, size - 1 - i, 0);
	}
}

void PrintArrary(int array[], int size){
	for (int i = 0; i < size; i++){
		printf("%d ", array[i]);
	}
	printf("\n");
}

int main(){
	int array[] = { 3, 9, 1, 4, 4, 7, 5, 2, 8, 0, 10, 9 };
	int size = sizeof(array) / sizeof(array[0]);
	PrintArrary(array, size);
	HeapSort(array, size);
	PrintArrary(array, size);
	return 0;
}
