//����һ������nums��һ��Ŀ��ֵtarget
//�ڸ��������ҳ���ΪĿ��ֵ������������  ���������ǵ������±�
//�����ظ��������������ͬ����Ԫ��

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
	int back;
	int front;

	int* AddRet = (int*)malloc(sizeof(int)* 2);

	for (back = 0; back<numsSize - 1; back++){
		for (front = back + 1; front<numsSize; front++){
			if (nums[back] + nums[front] == target){
				AddRet[0] = back;
				AddRet[1] = front;
				//��������Ĵ�С
				*returnSize = 2;
				return AddRet;
			}
		}
	}
	//��������Ĵ�С
	*returnSize = 0;
	return AddRet;
}