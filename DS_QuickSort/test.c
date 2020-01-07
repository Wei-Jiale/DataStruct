//�������򣨷����㷨��
//��Ҫ���������[low,high]

//������[low,high]������������
//��׼ֵ��array[low]
void Swap(int array[], int i, int j){
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

int Partition(int array[], int low, int high){
	//�����������������뱻�Ƚ�
	int begin = low;
	int end = high;
	int pivot = array[low];//�ڿӷ� begin�ǿӵ��±�
	//(begin,end)��������û�б��ȽϹ�������
	while (begin < end){
		//�����׼ֵ����ߣ���Ҫ���ұ߿�ʼ��
		while (begin<end && array[end] >= pivot){
			end--;
		}
		//�ڿӷ� array[begin] = array[end]
		if (begin == end){
			break;
		}
		//array[end]<��׼ֵ
		while (begin < end&&array[begin] <= pivot){
			begin++;
		}
		//�ڿӷ� array[end] = array[begin]

		//array[begin]>��׼ֵ
		Swap(array, begin, end);
	}

	//low��׼ֵ
	//[low+1,begin]�Ȼ�׼ֵС
	//[begin+1,high]�Ȼ�׼ֵ��
	//�ѻ�׼ֵ�ͱ���С�����һ��������
	Swap(array, low, begin);
	//�ڿӷ� array[begin] = pivot

	return begin;
}

void _QuickSort(int array[], int low, int high){
	//ֱ�����䳤��Ϊ1
	if (low == high){
		return;
	}
	//ֱ�����䳤��Ϊ0
	if (low > high){
		return;
	}

	//1.�һ�׼ֵ��ѡ����ߣ���׼ֵ���±���low
	//2.�����������䣬С�ķ��󣬴�ķ��ң����ػ�׼ֵ�����±�
	int pivotIdx = Partition(array, low, high);
	//3.���䱻�ֳ�������[low,pivotIdx] [pivotIdx,pivotIdx] [pivotIdx+1,high] �����㷨����
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
		//�Ȼ�׼ֵ�� ����i++��
		i++;
	}
	Swap(array, d - 1, low);

	return d - 1;
}
