#include<stdio.h>

//交换
void Swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

//打印堆
void PrintSort(int *array, int n){
	for (int i = 0; i < n; i++){
		printf("%d ", array[i]);
	}

	printf("\n");
}

//向下调整算法（大堆）
void AdjustDown(int *array, int n, int root){
	int parent = root;
	int child = 2 * parent + 1;

	while (child < n){
		//找出大的孩子和父亲比较
		if (child + 1<n&&array[child + 1]>array[child]){
			++child;
		}

		//孩子大于父亲就和父亲交换
		if (array[child]>array[parent]){
			Swap(&array[child], &array[parent]);

			parent = child;
			child = 2 * parent + 1;
		}
		else{
			break;
		}
	}
}

void HeapSort(int *array, int n){
	//建大堆(从最后一个非叶子结点向下调整）
	for (int i = (n - 2) / 2; i >= 0; i--){
		AdjustDown(array, n, i);
	}

	//交换第一个元素和最后一个元素
	int end = n - 1;

	while (end > 0){
		Swap(&array[0], &array[end]);
		AdjustDown(array, end, 0);
		--end;
	}
}

int main(){
	int array[] = { 3, 7, 9, 5, 4, 2, 1, 8, 6 };
	HeapSort(array, sizeof(array)/sizeof(array[0]));
	PrintSort(array, sizeof(array) / sizeof(array[0]));

	return 0;
}