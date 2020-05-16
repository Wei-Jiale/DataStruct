#include<stdio.h>

void Swap(int* num1, int* num2){
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

void Print(int* array, int sz){
	for (int cur = 0; cur < sz; cur++){
		printf("%d ", array[cur]);
	}
	printf("\n");
}

void Adjustdown(int* array, int start, int end){
	int parent = start;
	int child = parent * 2 + 1;

	while (child < end){
		// 选出左右孩子中较大的
		if (child + 1 < end && array[child + 1] > array[child]){
			child++;
		}
		// 孩子和父亲比较
		if (array[child] > array[parent]){
			// 孩子大于父亲则交换
			Swap(&array[child], &array[parent]);
			// 向下继续传递
			parent = child;
			child = parent * 2 + 1;
		}
		else{
			break;
		}
	}
}

void Heapsort(int* array, int sz){
	// 建堆：从最后一个非叶子结点(最后一个结点的父结点）开始进行向下调整
	for (int index = (sz - 1 - 1) / 2; index >= 0; index--){
		Adjustdown(array, index, sz);
	}
	// 堆排序
	while (sz > 0){
		Swap(&array[0], &array[sz - 1]);
		sz--;
		Adjustdown(array, 0, sz);
	}

}

int main(){
	int array[] = { 4, 6, 8, 5, 9 };
	int sz = sizeof(array) / sizeof(array[0]);
	Heapsort(array,sz);
	Print(array, sz);
}