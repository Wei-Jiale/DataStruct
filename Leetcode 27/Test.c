//给定一个顺序表array和一个值val
//要求原地移除所有值等于val的元素再返回移除后数组的新长度
//不要使用额外的顺序表空间 时间复杂度为O（n）空间复杂度为O（1）

int RemoveElement(int* array, int size, int val){
	int front;
	int back;
	for (front = 0, back = 0; front<size; front++){
		if (array[front] != val){
			array[back] = array[front];
			back++;
		}
	}
	return back;
}

//0  1  2  2  3  0  4  2 （val：2）
//定义front  back  终止条件front<size
//array[front] != val时  交换front和back对应元素
//back存储不是val的值
