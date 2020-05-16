#include<stdio.h>

void Swap(int* num1, int* num2){
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

void Print(int* array, int sz){
	for (int cur = 0; cur < sz; cur++){
		printf("%d ", array[cur]);
	}
	printf("\n");
}

void Adjustdown(int* array, int start, int end){
	int parent = start;
	int child = parent * 2 + 1;

	while (child < end){
		// ѡ�����Һ����нϴ��
		if (child + 1 < end && array[child + 1] > array[child]){
			child++;
		}
		// ���Ӻ͸��ױȽ�
		if (array[child] > array[parent]){
			// ���Ӵ��ڸ����򽻻�
			Swap(&array[child], &array[parent]);
			// ���¼�������
			parent = child;
			child = parent * 2 + 1;
		}
		else{
			break;
		}
	}
}

void Heapsort(int* array, int sz){
	// ���ѣ������һ����Ҷ�ӽ��(���һ�����ĸ���㣩��ʼ�������µ���
	for (int index = (sz - 1 - 1) / 2; index >= 0; index--){
		Adjustdown(array, index, sz);
	}
	// ������
	while (sz > 0){
		Swap(&array[0], &array[sz - 1]);
		sz--;
		Adjustdown(array, 0, sz);
	}

}

int main(){
	int array[] = { 4, 6, 8, 5, 9 };
	int sz = sizeof(array) / sizeof(array[0]);
	Heapsort(array,sz);
	Print(array, sz);
}