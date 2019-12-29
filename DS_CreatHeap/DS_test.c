#include <stdio.h>
#include<assert.h>
#include<stdlib.h>
//建堆：把一个完全无序的随机分布的数组变成满足堆的性质
//假如左右子树都是堆 直接对根做向下调整
//先对左右子树建堆
//从最后一个非叶子结点进行向下调整
//最后一个结点下标size-1
//parent = (child-1)/2
//最后一个非叶子结点下标(size-2)/2

void AdjustDown(int tree[], int size, int rootIdx){//数组，size，要调整的结点下标
	//判断rootIdx是不是叶子
	//没有左右孩子
	//完全二叉树没有左孩子就一定没有右孩子
	//因为存在数组里，判断左孩子下标是否越界
	int leftIdx = 2 * rootIdx + 1;
	int rightIdx = 2 * rootIdx + 2;
	if (leftIdx >= size){
		return;
	}

	//不是叶子
	//找到最小的一个孩子和根比较
	//如果有右孩子比较左右
	//否则直接用左孩子比较
	int minIdx = leftIdx;
	if (rightIdx < size&&tree[rightIdx] < tree[leftIdx]){
		minIdx = rightIdx;
	}

	if (tree[rootIdx] <= tree[minIdx]){
		//最小已经是根
		return;
	}

	int temp = tree[minIdx];
	tree[minIdx] = tree[rootIdx];
	tree[rootIdx] = temp;

	//交换之后 下面树的堆性质可能被破坏 继续调整
	AdjustDown(tree, size, minIdx);
}


void CreatHeap(int tree[], int size){
	for (int i = (size - 2) / 2; i >= 0; i--){
		AdjustDown(tree, size, i);
	}
}

typedef struct Heap{
	int tree[100];
	int size;
}	Heap;

//堆初始化
void HeapInit(Heap*pH, int array[], int size){
	assert(size <= 100);
	memcpy(pH->tree, array, size*sizeof(int));
	pH->size = size;
	CreatHeap(pH->tree, pH->size);
}

//出堆当前最小值
int HeapPop(Heap*pH){
	int v = pH->tree[0];
	pH->tree[0] = pH->tree[pH->size - 1];
	pH->size --;
	AdjustDown(pH->tree, pH->size, 0);

	return v;
}
//入堆(向上调整）
void AdjustUp(int tree[], int size, int child){
	if (child == 0){
		return;
	}

	int parent = (child - 1) / 2;
	if (tree[child] >= tree[parent]){
		return;
	}
	int temp = tree[child];
	tree[child] = tree[parent];
	tree[parent] = temp;

	AdjustUp(tree, size, parent);
}
void HeapPush(Heap*pH,int v){
	pH->tree[pH->size++] = v;
	AdjustUp(pH->tree, pH->size, pH->size - 1);
}

int main(){
	int array[] = { 9, 5, 7, 3, 8, 4, 2, 1, 0 };
	int size = sizeof(array) / sizeof(array[0]);
	Heap heap;
	HeapInit(&heap, array, size);

	for (int i = 0; i < 3; i++){
		printf("%d\n", HeapPop(&heap));
	}
	printf("After pop\n");
	for (int i = 0; i < 3; i++){
		HeapPush(&heap, i);
	}
	printf("After push\n");

	int sizes = heap.size;
	for (int i = 0; i < sizes; i++){
		printf("%d\n", HeapPop(&heap));
	}
}

