#include"Heap.h"

//向下调整算法（小堆） 
void AdjustDown(HpDataType* a, size_t n, int root){
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n){
		// 找出小的那个孩纸
		// 默认左孩子小
		// 如果右孩子小于左孩子则 child++
		if (child + 1 < n && a[child + 1] < a[child]){
			++child;
		}

		// 1、孩纸比父亲小，则交换，继续往下调
		// 2、孩纸比父亲大，则终止调整
		if (a[parent] > a[child]){
			HpDataType tmp = a[parent];
			a[parent] = a[child];
			a[child] = tmp;

			// 向下传递
			parent = child;
			child = parent * 2 + 1;
		}
		else{
			break;
		}
	}
}

//建堆：把一个无序的数组转化为满足堆的性质
void HeapCreate(Heap*hp, HpDataType* a, size_t n){
	hp->_a = (HpDataType*)malloc(sizeof(HpDataType)*n);
	memcpy(hp->_a, a, sizeof(HpDataType)*n);
	hp->_size = n;
	hp->_capacity = n;

	// 建堆
	// 从最后一个非叶子结点（最后一个结点的父节点）开始向下调整
	for (int i = (n - 1 - 1) / 2; i >= 0; --i){
		AdjustDown(hp->_a, hp->_size, i);
	}
}

//向上调整
void AdjustUp(HpDataType* a, int child){
	int parent = (child - 1) / 2;
	while (child > 0){
		if (a[child]<a[parent]){
			HpDataType tmp = a[parent];
			a[parent] = a[child];
			a[child] = tmp;

			child = parent;
			parent = (child - 1) / 2;
		}
		else{
			break;
		}
	}
}

//入堆
void HeapPush(Heap* hp, HpDataType x){
	//增容
	if (hp->_size == hp->_capacity){
		size_t newcapacity = hp->_capacity * 2;
		hp->_a = (HpDataType*)realloc(hp->_a, sizeof(HpDataType)*newcapacity);
		hp->_capacity = newcapacity;
	}

	hp->_a[hp->_size] = x;
	hp->_size++;

	// 向上调整 调成堆
	AdjustUp(hp->_a, hp->_size - 1);
}

//出堆
void HeapPop(Heap* hp){
	//堆顶元素和最后一个元素互换
	HpDataType temp = hp->_a[0];
	hp->_a[0] = hp->_a[hp->_size - 1];
	hp->_a[hp->_size - 1] = temp;

	hp->_size--;

	//向下调整成堆
	AdjustDown(hp->_a, hp->_size, 0);
}

//获取堆顶元素
HpDataType HeapTop(Heap* hp){
	return hp->_a[0];
}

//判断堆是否为空
int HeapEmpty(Heap* hp){
	return hp->_size == 0 ? 1 : 0;
}

//打印堆
void HeapPrint(Heap* hp){
	for (int i = 0; i < hp->_size; ++i){
		printf("%d ", hp->_a[i]);
	}

	printf("\n");
}

//堆销毁
void HeapDestory(Heap* hp){
	free(hp->_a);
	hp->_size = hp->_capacity = 0;
	hp->_a = NULL;
}
