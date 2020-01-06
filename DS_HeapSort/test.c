#include<stdio.h>
//选择排序（堆排序）
//不稳定
//向下调整
//1.左右孩子中值较大的(1)没有右孩子(2)有右孩子
//2.大孩子值和根的值作比较
//3.如果根的值>大孩子的值 停止
//4.否则交换 继续向下调整
//5.是叶子就可以停了
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
