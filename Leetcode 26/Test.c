//����һ������˳��� ����Ҫ��ԭ��ɾ���ظ����ֵ�Ԫ��
//ʹ��ÿ��Ԫ��ֻ����һ�� �����Ƴ���˳�����³���
//�ռ临�Ӷ�O��1��

int RemoveDuplicates(int* array, int size){
	int front = 0;
	int back = 0;

	//ע�����˳���Ϊ���򷵻�back+1��������
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

//����ע������һ������˳���
//����ǰ��ָ�� ǰfront  ��back
//���±�ΪfrontԪ��==�±�Ϊback��Ԫ��  ��back���� front++
//���±�ΪfrontԪ��!=�±�Ϊback��Ԫ��  ��array[back+1] = array[front]  ��ʹback++
//���շ���back+1
//����ע��˳���Ϊ�յ����