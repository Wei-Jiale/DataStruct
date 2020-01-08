//归并排序(一定是一个完全二叉树) O(n×logn)
//稳定
void Merge(int array[], int left, int mid, int right, int extra[]){
	int i = left;//左边区间的下标
	int j = mid;//右边区间的下标
	int k = left;//extra的下标
	while (i < mid&&j < right){
		if (array[i] <= array[j]){
			extra[k++] = array[i++];
		}
		else{
			extra[k++] = array[j++];
		}
	}
	while (i < mid){
		extra[k++] = array[i++];
	}
	while (j < right){
		extra[k++] = array[j++];
	}
	//把extra的数据移回来
	for (int x = left; x < right; x++){
		array[x] = extra[x];
	}
}


void _MergeSort(int array, int left, int right, int extra){
	//直到size == 0
	if (right <= left){
		return;
	}
	//直到size == 1
	if (right == left + 1){
		return;
	}

	//1.把数组平均分成两部分
	int mid = left + (right - left) / 2;
	//[left,mid)
	//[mid,right)
	//2.分治算法，排序左右两部分
	_MergeSort(array, left, mid, extra);
	_MergeSort(array, mid, right, extra);
	//3.合并两个有序数组
	Merge(array, left, mid, right, extra);
}

void MergeSort(int array[], int size){
	int *extra = (int *)malloc(sizeof(int)*size);
	_MergeSort(array, 0, size, extra);//左闭右开
	free(extra);
}

void PrintArrary(int array[], int size){
	for (int i = 0; i < size; i++){
		printf("%d ", array[i]);
	}
	printf("\n");
}

int main(){
	int array[] = { 3, 9, 1, 4, 4, 7, 5, 2, 8, 0, 10, 9 };
	int size = sizeof(array) / sizeof(array[0]);
	PrintArrary(array, size);
	MergeSort(array, size);
	PrintArrary(array, size);
	return 0;
}