#include<stdio.h>

typedef int HpDataType;

//交换
void Swap(int* a, int* b){
	int x = *a;
	*a = *b;
	*b = x;
}

//向下调整（小堆）
void AdjustDown(HpDataType* a, int n, int root){
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n){
		// 找出小的那个孩纸
		if (child + 1 < n && a[child + 1] < a[child]){
			++child;
		}

		// 1、孩纸比父亲小，则交换，继续往下调
		// 2、孩纸比父亲大，则终止调整
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

//堆排序（降序）
void HeapSort(HpDataType* a, int n)
{
	// 建小堆
	for (int i = (n - 2) / 2; i >= 0; --i){
		AdjustDown(a, n, i);
	}

	//交换第一个元素和最后一个元素
	//最小的数就被换到堆底
	int end = n - 1;
	while (end > 0){
		Swap(&a[end], &a[0]);

		//重复向下调整
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