//给定一个排序顺序表 你需要在原地删除重复出现的元素
//使得每个元素只出现一次 返回移除后顺序表的新长度
//空间复杂度O（1）

int RemoveDuplicates(int* array, int size){
	int front = 0;
	int back = 0;

	//注意如果顺序表为空则返回back+1会有问题
	if (size == 0){
		return 0;
	}

	for (front = 0, back = 0; front<size; front++){
		if (array[front] != array[back]){
			array[back + 1] = array[front];
			back++;
		}
	}

	return back + 1;
}

//首先注意这是一个有序顺序表
//定义前后指针 前front  后back
//当下标为front元素==下标为back的元素  则back不动 front++
//当下标为front元素!=下标为back的元素  则array[back+1] = array[front]  再使back++
//最终返回back+1
//尤其注意顺序表为空的情况