//堆（二叉堆）：是一种逻辑上的完全二叉树，利用顺序存储，实际存在数组里
//任取一个结点，要求根的值>=左右孩子的值（大堆）反之（小堆）   找最大值永远出现在二叉树逻辑上的根
//堆操作：向下调整（堆化）
//前题：只有一个位置不满足堆性质
//停止条件：1.走到叶子结点 2.过程中已经满足堆的性质
//思路（小堆）：找到 根 左孩子 右孩子 三个中最小的放到根上（只要不是叶子，一定有左孩子，但不一定有右孩子）
void AdjustDown(int tree[], int size, int rootIdx){//数组，size，要调整的结点下标
	//判断rootIdx是不是叶子
	//没有左右孩子
	//完全二叉树没有左孩子就一定没有右孩子
	//因为存在数组里，判断左孩子下标是否越界
	int leftIdx = 2 * rootIdx + 1;
	int rightIdx = 2 * rootIdx + 2;
	if (leftIdx>= size){
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


//O(log2(n))   O(1)
void AdjustDown(int tree[], int size, int rootIdx){
	int minIdx = 2 * rootIdx + 1;
	//如果是叶子直接返回
	if (2 * rootIdx + 1 >= size){
		return;
	}
	//不是叶子，则找最小孩子的下标
	if (2 * rootIdx + 2 >= size){
		minIdx = 2 * rootIdx + 1;
	}
	else if (tree[2 * rootIdx + 1] <= tree[2 * rootIdx + 2]){
		minIdx = 2 * rootIdx + 1;
	}
	else{
		minIdx = 2 * rootIdx + 2;
	}
	//比较最小孩子的值和要调整的根的值比较
	if (tree[rootIdx] <= tree[minIdx]){
		return;
	}
	//根的值较小，直接返回
	//否则 交换根和最小孩子
	else{
		int temp = tree[minIdx];
		tree[minIdx] = tree[rootIdx];
		tree[rootIdx] = temp;
	}
	//继续对最小孩子下标进行调整
	AdjustDown(tree, size, minIdx);
}

//排降序 建小堆
void HeapSort(int array[], int size){
	CreateHeap(array, size);
	for (int i = 0; i < size; i++){
		int temp = array[0];
		array[0] = array[size - 1 - i];
		array[size - 1 - i] = temp;

		AdjustDown(array, size - 1 - i, 0);
	}
}