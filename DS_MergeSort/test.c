//�鲢����(һ����һ����ȫ������) O(n��logn)
//�ȶ�
void Merge(int array[], int left, int mid, int right, int extra[]){
	int i = left;//���������±�
	int j = mid;//�ұ�������±�
	int k = left;//extra���±�
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
	//��extra�������ƻ���
	for (int x = left; x < right; x++){
		array[x] = extra[x];
	}
}


void _MergeSort(int array, int left, int right, int extra){
	//ֱ��size == 0
	if (right <= left){
		return;
	}
	//ֱ��size == 1
	if (right == left + 1){
		return;
	}

	//1.������ƽ���ֳ�������
	int mid = left + (right - left) / 2;
	//[left,mid)
	//[mid,right)
	//2.�����㷨����������������
	_MergeSort(array, left, mid, extra);
	_MergeSort(array, mid, right, extra);
	//3.�ϲ�������������
	Merge(array, left, mid, right, extra);
}

void MergeSort(int array[], int size){
	int *extra = (int *)malloc(sizeof(int)*size);
	_MergeSort(array, 0, size, extra);//����ҿ�
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