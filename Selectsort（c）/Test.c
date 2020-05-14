#include<stdio.h>

void Print(int* array, int sz){
	for (int cur = 0; cur < sz; cur++){
		printf("%d ", array[cur]);
	}
	printf("\n");
}

void Swap(int* num1, int* num2){
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

void Selectsort(int* array, int sz){
	for (int disorder = 0; disorder < sz - 1; disorder++){
		int min = disorder;
		for (int goal = disorder + 1; goal < sz; goal++){
			if (array[goal] < array[min]){
				min = goal;
			}
		}
		if (min != disorder){
			Swap(&array[disorder], &array[min]);
		}
	}
}

int main(){
	int array[] = { 7, 4, 5, 9, 8, 2, 1 };
	int sz = sizeof(array) / sizeof(array[0]);
	Selectsort(array, sz);
	Print(array, sz);
}