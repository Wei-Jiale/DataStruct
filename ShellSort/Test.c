#include<stdio.h>

void PrintSort(int *array, int n){
	for (int i = 0; i < n; i++){
		printf("%d ", array[i]);
	}

	printf("\n");
}

void ShellSort(int *array, int n){
	//间隔为gap的预排序
	int gap = n;
	//gap>1时为预排序
	//gap=1时为直接插入排序
	while (gap > 1){
		gap = gap / 3 + 1; //保证最后一次gap为1
		for (int i = 0; i < n - gap; i++){
			int end = i;
			//end的后一个数字向前插入
			int temp = array[end + gap];

			while (end >= 0){
				if (temp < array[end]){
					array[end + gap] = array[end];
					end = end - gap;
				}
				else{
					break;
				}

				array[end + gap] = temp;
			}
		}
	}
}

int main(){
	int array[] = { 3, 6, 2, 5, 7, 9, 8, 6, 1, 4 };
	ShellSort(array, sizeof(array) / sizeof(array[0]));
	PrintSort(array, sizeof(array) / sizeof(array[0]));

	return 0;
}