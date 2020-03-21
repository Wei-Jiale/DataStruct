//直接插入排序
#include<stdio.h>

void PrintSort(int *array, int n){
	for (int i = 0; i < n; i++){
		printf("%d ", array[i]);
	}

	printf("\n");
}

void InsertSort(int *array, int n){
	//控制end从头开始到结束
	for (int i = 0; i < n - 1; i++){
		//单趟排序(一个数插入到一个有序区间）
		//有序区间[0,end]
		int end = i;
		int temp = array[end + 1];

		while (end >= 0){
			if (temp < array[end]){
				//原有序区间的元素向后移动
				array[end + 1] = array[end];
				--end;
			}
			else{
				break;
			}
		}

		//此时end<0
		array[end + 1] = temp;
	}
}

int main(){
	int array[] = { 3, 6, 2, 5, 7, 9, 8, 6, 1, 4 };
	InsertSort(array, sizeof(array) / sizeof(array[0]));
	PrintSort(array, sizeof(array) / sizeof(array[0]));
	return 0;
}