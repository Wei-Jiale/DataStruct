//给定一个数组
//将数组中元素向右移动K个位置
//K是非负数
//要求空间复杂度为O（1）的原地算法

void rotate(int* array, int size, int k){
	//考虑k的值可能大于size
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

//第一次交换：整体
//第二次交换：前k个元素
//第三次交换：剩余元素
//尤其注意考虑当k>size的情况