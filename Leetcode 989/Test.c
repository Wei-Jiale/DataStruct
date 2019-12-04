//对于非负整数X而言，X的数组形式是每位数字按从左到右的顺序形成的数组。
//例如X=1231 数组形式为[1,2,3,1]
//给定非负整数X的数组形式A  返回整数X+K的数组形式
//A=[2,7,4] K=181  输出[4,5,5]  274+181=455

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
	//相加的结果
	int* AddRet = malloc(10001 * sizeof(int));

	//不知道是否进位
	//分解 
	//因为存在进位 所以长的结束才算结束

	//结果的下标
	int reti = 0;

	//进位值
	int next = 0;

	//数组下标
	//从个位走起
	int Ai = ASize - 1;

	//取到相加的值
	while (Ai >= 0 || K>0){
		int x1 = 0;
		if (Ai >= 0){
			//取数组值
			x1 = A[Ai];
			Ai--;
		}
		int x2 = 0;
		if (K>0){
			//取数字
			x2 = K % 10;
			K = K / 10;
		}

		int ret = x1 + x2 + next;
		//考虑进位
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