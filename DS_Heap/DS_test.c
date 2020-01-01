//�ѣ�����ѣ�����һ���߼��ϵ���ȫ������������˳��洢��ʵ�ʴ���������
//��ȡһ����㣬Ҫ�����ֵ>=���Һ��ӵ�ֵ����ѣ���֮��С�ѣ�   �����ֵ��Զ�����ڶ������߼��ϵĸ�
//�Ѳ��������µ������ѻ���
//ǰ�⣺ֻ��һ��λ�ò����������
//ֹͣ������1.�ߵ�Ҷ�ӽ�� 2.�������Ѿ�����ѵ�����
//˼·��С�ѣ����ҵ� �� ���� �Һ��� ��������С�ķŵ����ϣ�ֻҪ����Ҷ�ӣ�һ�������ӣ�����һ�����Һ��ӣ�
void AdjustDown(int tree[], int size, int rootIdx){//���飬size��Ҫ�����Ľ���±�
	//�ж�rootIdx�ǲ���Ҷ��
	//û�����Һ���
	//��ȫ������û�����Ӿ�һ��û���Һ���
	//��Ϊ����������ж������±��Ƿ�Խ��
	int leftIdx = 2 * rootIdx + 1;
	int rightIdx = 2 * rootIdx + 2;
	if (leftIdx>= size){
		return;
	}
	//����Ҷ��
	//�ҵ���С��һ�����Ӻ͸��Ƚ�
	//������Һ��ӱȽ�����
	//����ֱ�������ӱȽ�
	int minIdx = leftIdx;
	if (rightIdx < size&&tree[rightIdx] < tree[leftIdx]){
		minIdx = rightIdx;
	}

	if (tree[rootIdx] <= tree[minIdx]){
		//��С�Ѿ��Ǹ�
		return;
	}

	int temp = tree[minIdx];
	tree[minIdx] = tree[rootIdx];
	tree[rootIdx] = temp;

	//����֮�� �������Ķ����ʿ��ܱ��ƻ� ��������
	AdjustDown(tree, size, minIdx);
}


//O(log2(n))   O(1)
void AdjustDown(int tree[], int size, int rootIdx){
	int minIdx = 2 * rootIdx + 1;
	//�����Ҷ��ֱ�ӷ���
	if (2 * rootIdx + 1 >= size){
		return;
	}
	//����Ҷ�ӣ�������С���ӵ��±�
	if (2 * rootIdx + 2 >= size){
		minIdx = 2 * rootIdx + 1;
	}
	else if (tree[2 * rootIdx + 1] <= tree[2 * rootIdx + 2]){
		minIdx = 2 * rootIdx + 1;
	}
	else{
		minIdx = 2 * rootIdx + 2;
	}
	//�Ƚ���С���ӵ�ֵ��Ҫ�����ĸ���ֵ�Ƚ�
	if (tree[rootIdx] <= tree[minIdx]){
		return;
	}
	//����ֵ��С��ֱ�ӷ���
	//���� ����������С����
	else{
		int temp = tree[minIdx];
		tree[minIdx] = tree[rootIdx];
		tree[rootIdx] = temp;
	}
	//��������С�����±���е���
	AdjustDown(tree, size, minIdx);
}

//�Ž��� ��С��
void HeapSort(int array[], int size){
	CreateHeap(array, size);
	for (int i = 0; i < size; i++){
		int temp = array[0];
		array[0] = array[size - 1 - i];
		array[size - 1 - i] = temp;

		AdjustDown(array, size - 1 - i, 0);
	}
}