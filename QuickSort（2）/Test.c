//���ţ��ڿӣ�
#include<stdio.h>

void PrintSort(int* array, int n){
	for (int i = 0; i < n; i++){
		printf("%d ", array[i]);
	}

	printf("\n");
}

int PartSort(int* array, int begin, int end){
	//ѡ����׼ֵ���ڿӷ��Ŀӣ�
	int key = array[end];
	//ѡ������
	while (begin < end){
		//begin�Ҵ��ڻ�׼ֵ��Ԫ��
		while (begin < end&&array[begin] <= key){
			begin++;
		}
		array[end] = array[begin];

		//end��С�ڻ�׼ֵ��Ԫ��
		while (end > begin&&array[end] >= key){
			end--;
		}
		array[begin] = array[end];

	}

	array[begin] = key;

	//����������
	return begin;
}


void QuickSort(int* array, int begin, int end){
	//���䳤��Ϊ0����1
	if (begin >= end){
		return;
	}
	int keyindex = PartSort(array, begin, end);
	//�������Ϊ���Σ�С�ڻ�׼ֵ ��׼ֵ ���ڻ�׼ֵ��
	QuickSort(array, begin, keyindex - 1);
	QuickSort(array, keyindex + 1, end);

}

int main(){
	int array[] = { 8, 6, 4, 2, 3, 7, 9, 1, 5 };
	QuickSort(array, 0, sizeof(array) / sizeof(array[0]) - 1);
	PrintSort(array, sizeof(array) / sizeof(array[0]));

	return 0;
}