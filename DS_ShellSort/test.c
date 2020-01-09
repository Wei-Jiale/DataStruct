#include<stdio.h>
//希尔排序（分组插排）
//不稳定
//组间(gap)跨度越大移动的越快
//gap = size
//1. gap = gap/3+1;
//2. gap = gap/2;

void ShellSort(int array[],int size){
	int gap = size;
	while (1){
		gap = gap / 3 + 1;
		for (int i = 0; i < size; i++){
			//保存第一层处理的数
			int key = array[i];
			int j;
			//向前比较找合适的位置
			for (j = i - gap; j >= 0; j-=gap){
				if (array[j] <= key){
					break;
				}
				else{
					//向后般
					array[j + gap] = array[j];
				}
			}
			array[j + gap] = key;
		}
		if (gap == 1){
			return;
		}
	}
}

void PrintArrary(int array[], int size){
	for (int i = 0; i < size; i++){
		printf("%d ", array[i]);
	}
	printf("\n");
}

int main(){
	int array[] = { 3, 9, 1, 4, 4, 7, 5, 2, 8, 0, 10, 9 };
	int size = sizeof(array) / sizeof(array[0]);
	PrintArrary(array, size);
	ShellSort(array, size);
	PrintArrary(array, size);
	return 0;
}
