//��������
//����һ���������� nums ���ҵ�һ���������͵����������飨���������ٰ���һ��Ԫ�أ�������������

int maxSubArray(int* nums, int numsSize){
	//�������������Сֵ����Ŀ
	//��������ֵӦΪ�����е�Ԫ��
	//��Ҫ����Ϊ0
	int max = nums[0];

	//������ʼλ��
	int i = 0;
	//����������
	int j = 0;

	for (i = 0; i < numsSize; i++){
		//sumӦ����ѭ���ڲ�
		//�������ڲ�ѭ��ʱsum������Ϊ0
		int sum = 0;

		//��Ϊ����Ϊ����������
		//����j��ֵӦ�ô�i��
		for (j = i; j < numsSize; j++){
			sum += nums[j];
			if (sum>max){
				max = sum;
			}
		}
	}
	return max;
}