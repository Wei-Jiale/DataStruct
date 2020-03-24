#include<stdio.h>

//����
void Swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

//��ӡ��
void PrintSort(int *array, int n){
	for (int i = 0; i < n; i++){
		printf("%d ", array[i]);
	}

	printf("\n");
}

//���µ����㷨����ѣ�
void AdjustDown(int *array, int n, int root){
	int parent = root;
	int child = 2 * parent + 1;

	while (child < n){
		//�ҳ���ĺ��Ӻ͸��ױȽ�
		if (child + 1<n&&array[child + 1]>array[child]){
			++child;
		}

		//���Ӵ��ڸ��׾ͺ͸��׽���
		if (array[child]>array[parent]){
			Swap(&array[child], &array[parent]);

			parent = child;
			child = 2 * parent + 1;
		}
		else{
			break;
		}
	}
}

void HeapSort(int *array, int n){
	//�����(�����һ����Ҷ�ӽ�����µ�����
	for (int i = (n - 2) / 2; i >= 0; i--){
		AdjustDown(array, n, i);
	}

	//������һ��Ԫ�غ����һ��Ԫ��
	int end = n - 1;

	while (end > 0){
		Swap(&array[0], &array[end]);
		AdjustDown(array, end, 0);
		--end;
	}
}

int main(){
	int array[] = { 3, 7, 9, 5, 4, 2, 1, 8, 6 };
	HeapSort(array, sizeof(array)/sizeof(array[0]));
	PrintSort(array, sizeof(array) / sizeof(array[0]));

	return 0;
}