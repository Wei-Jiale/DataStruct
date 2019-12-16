#include"stack.h"

void Test(){
	Stack st;
	//初始化
	StackInit(&st);
	//入栈
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPush(&st, 5);

	while (!StackEmpty(&st)){
		//访问
		printf("%d ", StackTop(&st));
		//Pop之后才能取到下一个数据
		StackPop(&st);
	}

	//销毁
	StackDestroy(&st);
}

int main(){
	Test();
	return 0;
}