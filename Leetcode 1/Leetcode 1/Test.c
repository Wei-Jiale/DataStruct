//给定一个数组nums和一个目标值target
//在该数组中找出和为目标值的那两个整数  并返回它们的数组下标
//不能重复利用这个数组中同样的元素

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
	int back;
	int front;

	int* AddRet = (int*)malloc(sizeof(int)* 2);

	for (back = 0; back<numsSize - 1; back++){
		for (front = back + 1; front<numsSize; front++){
			if (nums[back] + nums[front] == target){
				AddRet[0] = back;
				AddRet[1] = front;
				//返回数组的大小
				*returnSize = 2;
				return AddRet;
			}
		}
	}
	//返回数组的大小
	*returnSize = 0;
	return AddRet;
}