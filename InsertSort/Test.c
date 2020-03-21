//ֱ�Ӳ�������
#include<stdio.h>

void PrintSort(int *array, int n){
	for (int i = 0; i < n; i++){
		printf("%d ", array[i]);
	}

	printf("\n");
}

void InsertSort(int *array, int n){
	//����end��ͷ��ʼ������
	for (int i = 0; i < n - 1; i++){
		//��������(һ�������뵽һ���������䣩
		//��������[0,end]
		int end = i;
		int temp = array[end + 1];

		while (end >= 0){
			if (temp < array[end]){
				//ԭ���������Ԫ������ƶ�
				array[end + 1] = array[end];
				--end;
			}
			else{
				break;
			}
		}

		//��ʱend<0
		array[end + 1] = temp;
	}
}

int main(){
	int array[] = { 3, 6, 2, 5, 7, 9, 8, 6, 1, 4 };
	InsertSort(array, sizeof(array) / sizeof(array[0]));
	PrintSort(array, sizeof(array) / sizeof(array[0]));
	return 0;
}