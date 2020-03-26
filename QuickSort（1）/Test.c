//快排（Hover）
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
	int keyindex = end;
	//选定区间
	while (begin < end){
		//begin找大于基准值的元素
		while (begin < end&&array[begin] <= key){
			begin++;
		}
		//end找小于基准值的元素
		while (end > begin&&array[end] >= key){
			end--;
		}

		//begin和end都找到了目标
		Swap(&array[begin], &array[end]);
	}

	Swap(&array[begin], &array[keyindex]);

	//返回相遇点
	return begin;
}


void QuickSort(int* array, int begin, int end){
	//区间长度为0或者1
	if (begin >= end){
		return;
	}
	int keyindex = PartSort(array, begin, end);
	//将区间分为三段（小于基准值 基准值 大于基准值）
	QuickSort(array, begin, keyindex - 1);
	QuickSort(array, keyindex+1, end);

}

int main(){
	int array[] = { 8, 6, 4, 2, 3, 7, 9, 1, 5 };
	QuickSort(array, 0, sizeof(array) / sizeof(array[0]) - 1);
	PrintSort(array, sizeof(array) / sizeof(array[0]));

	return 0;
}