#include<stdio.h>
//ѡ������  
//���ȶ�
//�������� �����㷨
void Swap(int array[], int i, int j){
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

void SelectSort(int array[], int size){
	for (int i = 0; i < size; i++){
		//ѡ�����������������
		int maxIdx = 0;
		for (int j = 0; j < size - i; j++){
			if (array[j]>array[maxIdx]){
				maxIdx = j;
			}
		}
		Swap(array, maxIdx, size - 1 - i);
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
	SelectSort(array, size);
	PrintArrary(array, size);
	return 0;
}
