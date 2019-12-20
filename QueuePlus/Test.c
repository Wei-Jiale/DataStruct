#include"Queue.h"

void Test(){
	Queue q;
	//初始化
	QueueInit(&q);
	
	//入队列
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);

	while (!QueueEmpty(&q)){
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}

	//销毁
	QueueDestroy(&q);
}

int main(){
	Test();
	return 0;
}