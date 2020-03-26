//快排（挖坑）
#include<stdio.h>

void Swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void PrintSort(int* array, int n){
	for (int i = 0; i < n; i++){
		printf("%d ", array[i]);
	}

	printf("\n");
}

int PartSort(int* array, int begin, int end){
	//选定基准值
	int key = array[end];
	//定义前后指针
	int cur = begin;
	int prev = begin - 1;

	while (cur < end){
		if (array[cur] < key && ++prev != cur){
			Swap(&array[cur], &array[prev]);
		}
		cur++;
	}

	prev++;
	Swap(&array[prev], &array[end]);

	//返回相遇点
	return prev;
}


void QuickSort(int* array, int begin, int end){
	//区间长度为0或者1
	if (begin >= end){
		return;
	}
	int keyindex = PartSort(array, begin, end);
	//将区间分为三段（小于基准值 基准值 大于基准值）
	QuickSort(array, begin, keyindex - 1);
	QuickSort(array, keyindex + 1, end);

}

int main(){
	int array[] = { 8, 6, 4, 2, 3, 7, 9, 1, 5 };
	QuickSort(array, 0, sizeof(array) / sizeof(array[0]) - 1);
	PrintSort(array, sizeof(array) / sizeof(array[0]));

	return 0;
}