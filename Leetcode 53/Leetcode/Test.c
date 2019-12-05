//最大子序和
//给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和

int maxSubArray(int* nums, int numsSize){
	//类似于找最大最小值的题目
	//定义的最大值应为数组中的元素
	//不要定义为0
	int max = nums[0];

	//控制起始位置
	int i = 0;
	//控制向后遍历
	int j = 0;

	for (i = 0; i < numsSize; i++){
		//sum应放在循环内部
		//不满足内层循环时sum都被置为0
		int sum = 0;

		//因为必须为连续子数组
		//所以j的值应该从i起
		for (j = i; j < numsSize; j++){
			sum += nums[j];
			if (sum>max){
				max = sum;
			}
		}
	}
	return max;
}