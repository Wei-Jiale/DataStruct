#include"stack.h"

void Test(){
	Stack st;
	//��ʼ��
	StackInit(&st);
	//��ջ
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPush(&st, 5);

	while (!StackEmpty(&st)){
		//����
		printf("%d ", StackTop(&st));
		//Pop֮�����ȡ����һ������
		StackPop(&st);
	}

	//����
	StackDestroy(&st);
}

int main(){
	Test();
	return 0;
}