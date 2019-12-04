//����������������˳��� array1��array2
//��array2�ϲ���array1�� 
//ʹarray1��Ϊһ������˳���
//��ʼ�� array1��Ԫ������Ϊm
//��ʼ�� array2��Ԫ������Ϊn
//���� array1���㹻�Ŀռ���������array2�е�Ԫ��

void merge(int* array1, int array1size, int m, int* array2, int array2size, int n){
	int dst = m - 1;
	int src = n - 1;
	int k = m + n - 1;

	for (dst, src; dst >= 0 && src >= 0;){
		if (array1[dst]>array2[src]){
			array1[k--] = array1[dst--];
		}
		else{
			array1[k--] = array2[src--];
		}
	}

	//array2ʣ��Ԫ��
	if (src >= 0){
		memcpy(array1, array2, (src + 1)*sizeof(int));
	}
}

//˫ָ��ͬʱ�Ӻ���ǰ����������
//�ϴ�ֵ����array1�����һ����k--
//���ѭ��