//�鲢����
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

void PrintSort(int *array, int n){
	for (int i = 0; i < n; i++){
		printf("%d ", array[i]);
	}

	printf("\n");
}

void _MergeSort(int* array, int begin, int end, int* temp){
	if (begin >= end)
		return;

	//�����黮��Ϊ��������[begin,mid] [mid+1,end]
	int mid = (begin + end) >> 1;
	//����������
	_MergeSort(array, begin, mid, temp);
	_MergeSort(array, mid + 1, end, temp);

	//�鲢������������
	int begin1 = begin,begin2 = mid + 1,end1 = mid,end2 = end;
	int index = begin;
	//С�Ľ�����ʱ����
	while (begin1 <= end1&&begin2 <= end2){
		if (array[begin1] < array[begin2])
			temp[index++] = array[begin1++];
		else
			temp[index++] = array[begin2++];
	}
	//����һ�������Ѿ�û��Ԫ��
	if (begin1 <= end1){
		while (begin1 <= end1)
			temp[index++] = array[begin1++];
	}
	else{
		while (begin2 <= end2)
			temp[index++] = array[begin2++];
	}

	//�Ż�ԭ����
	memcpy(array + begin, temp + begin, sizeof(int)*(end - begin + 1));
}

void MergeSort(int *array, int n){
	//������ʱ����
	int* temp = (int*)malloc(sizeof(int)*n);
	_MergeSort(array, 0, n - 1, temp);

	free(temp);
}

int main(){
	int array[] = { 8, 6, 2, 4, 5, 3, 9, 7, 1 };
	MergeSort(array, sizeof(array) / sizeof(array[0]));
	PrintSort(array, sizeof(array) / sizeof(array[0]));

	return 0;
}