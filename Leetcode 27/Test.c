//����һ��˳���array��һ��ֵval
//Ҫ��ԭ���Ƴ�����ֵ����val��Ԫ���ٷ����Ƴ���������³���
//��Ҫʹ�ö����˳���ռ� ʱ�临�Ӷ�ΪO��n���ռ临�Ӷ�ΪO��1��

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

//0  1  2  2  3  0  4  2 ��val��2��
//����front  back  ��ֹ����front<size
//array[front] != valʱ  ����front��back��ӦԪ��
//back�洢����val��ֵ
