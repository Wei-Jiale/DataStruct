//����һ������
//��������Ԫ�������ƶ�K��λ��
//K�ǷǸ���
//Ҫ��ռ临�Ӷ�ΪO��1����ԭ���㷨

void rotate(int* array, int size, int k){
	//����k��ֵ���ܴ���size
	k = k%size;

	int left = 0;
	int right = size - 1;
	int temp = 0;

	int front = 0;
	int back = k - 1;
	int ret = 0;

	int before = k;
	int after = size - 1;
	int exchange = 0;

	while (left<right){
		temp = array[left];
		array[left] = array[right];
		array[right] = temp;

		left++;
		right--;
	}

	while (front<back){
		ret = array[front];
		array[front] = array[back];
		array[back] = ret;

		front++;
		back--;
	}

	while (before<after){
		exchange = array[before];
		array[before] = array[after];
		array[after] = exchange;

		before++;
		after--;
	}
}

//��һ�ν���������
//�ڶ��ν�����ǰk��Ԫ��
//�����ν�����ʣ��Ԫ��
//����ע�⿼�ǵ�k>size�����