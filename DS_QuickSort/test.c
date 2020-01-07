//快速排序（分治算法）
//需要排序的区间[low,high]

//对数组[low,high]的区间做分组
//基准值在array[low]
void Swap(int array[], int i, int j){
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

int Partition(int array[], int low, int high){
	//区间内所有数都必须被比较
	int begin = low;
	int end = high;
	int pivot = array[low];//挖坑法 begin是坑的下标
	//(begin,end)的区间是没有被比较过的数据
	while (begin < end){
		//如果基准值在左边，需要从右边开始走
		while (begin<end && array[end] >= pivot){
			end--;
		}
		//挖坑法 array[begin] = array[end]
		if (begin == end){
			break;
		}
		//array[end]<基准值
		while (begin < end&&array[begin] <= pivot){
			begin++;
		}
		//挖坑法 array[end] = array[begin]

		//array[begin]>基准值
		Swap(array, begin, end);
	}

	//low基准值
	//[low+1,begin]比基准值小
	//[begin+1,high]比基准值大
	//把基准值和比它小的最后一个数交换
	Swap(array, low, begin);
	//挖坑法 array[begin] = pivot

	return begin;
}

void _QuickSort(int array[], int low, int high){
	//直到区间长度为1
	if (low == high){
		return;
	}
	//直到区间长度为0
	if (low > high){
		return;
	}

	//1.找基准值，选最左边，基准值的下标是low
	//2.遍历整个区间，小的放左，大的放右，返回基准值所在下标
	int pivotIdx = Partition(array, low, high);
	//3.区间被分成三部分[low,pivotIdx] [pivotIdx,pivotIdx] [pivotIdx+1,high] 分治算法处理
	_QuickSort(array, low, pivotIdx - 1);
	_QuickSort(array, pivotIdx + 1, high);

}

void QuickSort(int array[], int size){
	_QuickSort(array, 0, size - 1);
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
	QuickSort(array, size);
	PrintArrary(array, size);
	return 0;
}


int Partition(int array[], int low, int high){
	int i = low + 1;
	int d = low + 1;
	int pivot = array[low];
	while (i <= high){
		if (array[i] < pivot){
			Swap(array, i, d);
			d++;
		}
		//比基准值大 正常i++；
		i++;
	}
	Swap(array, d - 1, low);

	return d - 1;
}
