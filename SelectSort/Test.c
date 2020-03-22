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
	//������[begin,end]��ѡ��
	int begin = 0;
	int end = n - 1;

	//ѡ����С���������
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

		//����begin����С�� end�������
		Swap(&array[minidenx], &array[begin]);
		//���begin��maxidenx��ͬ �������ҵ�����
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