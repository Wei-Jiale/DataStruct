//���ڷǸ�����X���ԣ�X��������ʽ��ÿλ���ְ������ҵ�˳���γɵ����顣
//����X=1231 ������ʽΪ[1,2,3,1]
//�����Ǹ�����X��������ʽA  ��������X+K��������ʽ
//A=[2,7,4] K=181  ���[4,5,5]  274+181=455

void reverse(int* nums, int begin, int end){
	while (begin<end){
		int tmp = nums[begin];
		nums[begin] = nums[end];
		nums[end] = tmp;

		begin++;
		end--;
	}
}

int* addToArrayForm(int* A, int ASize, int K, int* returnSize){
	//��ӵĽ��
	int* AddRet = malloc(10001 * sizeof(int));

	//��֪���Ƿ��λ
	//�ֽ� 
	//��Ϊ���ڽ�λ ���Գ��Ľ����������

	//������±�
	int reti = 0;

	//��λֵ
	int next = 0;

	//�����±�
	//�Ӹ�λ����
	int Ai = ASize - 1;

	//ȡ����ӵ�ֵ
	while (Ai >= 0 || K>0){
		int x1 = 0;
		if (Ai >= 0){
			//ȡ����ֵ
			x1 = A[Ai];
			Ai--;
		}
		int x2 = 0;
		if (K>0){
			//ȡ����
			x2 = K % 10;
			K = K / 10;
		}

		int ret = x1 + x2 + next;
		//���ǽ�λ
		if (ret>9){
			ret = ret % 10;
			next = 1;
		}
		else{
			next = 0;
		}
		AddRet[reti++] = ret;
	}

	if (next == 1){
		AddRet[reti++] = 1;
	}

	reverse(AddRet, 0, reti - 1);
	*returnSize = reti;
	return AddRet;
}