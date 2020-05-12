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

void Shellsort(int* array, int sz){
	// 设置增量并递减增量
	for (int gap = sz / 2; gap > 0; gap /= 2){
		// 对每组进行插入排序
		for (int disorder = gap; disorder < sz; disorder++){
			int goal = disorder;
			while (goal - gap >= 0 && array[goal] < array[goal - gap]){
				Swap(&array[goal], &array[goal - gap]);
				goal -= gap;
			}
		}
	}
}

int main(){
	int array[] = { 9, 1, 2, 5, 7, 4, 8, 6, 3, 5 };
	int sz = sizeof(array) / sizeof(array[0]);
	Shellsort(array, sz);
	Print(array, sz);
}