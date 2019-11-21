#include <stdio.h>
//链表的结点结构体
typedef struct Node{
	int value;
	struct Node *next;//保存着下一个结点的地址
}Node;
//6.输入一个链表，输出该链表倒数第k个结点
struct Node* FindKthToTail(Node* head, int k){
	//定义双指针，一前一后
	Node *front = head;
	Node *back = head;
	//前方指针先走k-1步
	int i;
	for (i = 0; i < k - 1; i++){
		front = front->next;
	}
	//
	if (front == NULL){
		if (i <= k - 1){
			//上面循环没走完
			return NULL;
		}
	}
	//再同时出发
	while (front != NULL){
		front = front->next;
		if (front == NULL){
			break;
		}
		back = back->next;
	}
	return back;
}
