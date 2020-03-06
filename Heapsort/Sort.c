#include<stdio.h>

typedef int HpDataType;

//����
void Swap(int* a, int* b){
	int x = *a;
	*a = *b;
	*b = x;
}

//���µ�����С�ѣ�
void AdjustDown(HpDataType* a, int n, int root){
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n){
		// �ҳ�С���Ǹ���ֽ
		if (child + 1 < n && a[child + 1] < a[child]){
			++child;
		}

		// 1����ֽ�ȸ���С���򽻻����������µ�
		// 2����ֽ�ȸ��״�����ֹ����
		if (a[parent] > a[child]){
			Swap(&a[child], &a[parent]);

			parent = child;
			child = parent * 2 + 1;
		}
		else{
			break;
		}
	}
}

//�����򣨽���
void HeapSort(HpDataType* a, int n)
{
	// ��С��
	for (int i = (n - 2) / 2; i >= 0; --i){
		AdjustDown(a, n, i);
	}

	//������һ��Ԫ�غ����һ��Ԫ��
	//��С�����ͱ������ѵ�
	int end = n - 1;
	while (end > 0){
		Swap(&a[end], &a[0]);

		//�ظ����µ���
		AdjustDown(a, end, 0);
		--end;
	}

	for (int i = 0; i < n; i++){
		printf("%d ", a[i]);

	}
}

int main(){
	int a[10] = { 27, 15, 19, 34, 65, 37, 25, 49, 28, 18 };
	HeapSort(a, 10);

	return 0;
}