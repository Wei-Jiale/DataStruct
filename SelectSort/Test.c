#include<stdio.h>

void Swap(int *a, int *b){
	int *temp = *a;
	*a = *b;
	*b = temp;
}

void PrintSort(int *array, int n){
	for (int i = 0; i < n; i++){
		printf("%d ", array[i]);
	}
	printf("\n");
}

void SelectSort(int *array, int n){
	//在区间[begin,end]中选择
	int begin = 0;
	int end = n - 1;

	//选出最小数和最大数
	while (begin < end){
		int maxidenx = end;
		int minidenx = begin;

		for (int i = begin; i <= end; i++){
			if (array[minidenx]>array[i]){
				minidenx = i;
			}
			if (array[maxidenx] < array[i]){
				maxidenx = i;
			}
		}

		//交换begin和最小数 end和最大数
		Swap(&array[minidenx], &array[begin]);
		//解决begin和maxidenx相同 交换错乱的问题
		if (begin == maxidenx){
			maxidenx = minidenx;
		}
		Swap(&array[maxidenx], &array[end]);

		begin++;
		end--;
	}
}

int main(){
	int array[] = { 3, 6, 2, 5, 7, 9, 8, 6, 1, 4 };
	SelectSort(array, sizeof(array) / sizeof(array[0]));
	PrintSort(array, sizeof(array) / sizeof(array[0]));
	return 0;
}