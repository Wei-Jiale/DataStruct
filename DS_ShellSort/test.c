#include<stdio.h>
//ϣ�����򣨷�����ţ�
//���ȶ�
//���(gap)���Խ���ƶ���Խ��
//gap = size
//1. gap = gap/3+1;
//2. gap = gap/2;

void ShellSort(int array[],int size){
	int gap = size;
	while (1){
		gap = gap / 3 + 1;
		for (int i = 0; i < size; i++){
			//�����һ�㴦�����
			int key = array[i];
			int j;
			//��ǰ�Ƚ��Һ��ʵ�λ��
			for (j = i - gap; j >= 0; j-=gap){
				if (array[j] <= key){
					break;
				}
				else{
					//����
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
