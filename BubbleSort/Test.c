//冒泡排序
#include<stdio.h>

void Swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void PrintSort(int *array, int n){
	for (int i = 0; i < n; i++){
		printf("%d ", array[i]);
	}

	printf("\n");
}

void BubbleSort(int *array, int n){
	//控制每一次的冒泡次数
	for (int end = n-1; end > 0; end--){
		int flag = 0;
		//单趟冒泡（最大的数排序到队尾）
		for (int i = 0; i < end; i++){
			if (array[i]>array[i + 1]){
				Swap(&array[i], &array[i + 1]);
				flag = 1;
			}
		}

		if (flag == 0){
			break;
		}
	}
}

int main(){
	int array[] = { 9, 5, 6, 4, 2, 3, 7, 1, 8 };
	BubbleSort(array, sizeof(array) / sizeof(array[0]));
	PrintSort(array, sizeof(array) / sizeof(array[0]));

	return 0;
}