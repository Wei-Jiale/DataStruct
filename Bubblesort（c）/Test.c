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

void Bubblesort(int* array, int sz){
	// 外层循环控制每一趟冒泡的次数
	for (int out = 0; out < sz - 1; out++){
		int flag = 0;
		// 内层循环控制单趟冒泡
		for (int in = 0; in < sz - out - 1; in++){
			if (array[in]>array[in + 1]){
				Swap(&array[in], &array[in + 1]);
				flag = 1;
			}
		}
		if (flag == 0){
			break;
		}
	}
}

int main(){
	int array[] = { 9, 3, 1, 4, 2, 7, 8, 6, 5 };
	int sz = sizeof(array) / sizeof(array[0]);
	Bubblesort(array, sz);
	Print(array, sz);
}