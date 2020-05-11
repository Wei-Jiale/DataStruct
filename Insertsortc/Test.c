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

// 插入排序传参：数组+数组大小
void InsertSort(int* array, int sz){
	// 1.判断数组大小
	if (sz <= 1){
		return;
	}

	// 2.直接插入排序
	for (int disorder = 1; disorder < sz; disorder++){
		int goal = disorder;
		while (goal > 0 && array[goal] < array[goal - 1]){
			Swap(&array[goal], &array[goal - 1]);
			goal--;
		}
	}
}

int main(){
	int array[] = { 5, 2, 4, 6, 1, 3 };
	int sz = sizeof(array) / sizeof(array[0]);
	InsertSort(array, sz);
	Print(array, sz);

	return 0;
}