#include <stdio.h>
//����Ľ��ṹ��
typedef struct Node{
	int value;
	struct Node *next;//��������һ�����ĵ�ַ
}Node;
//6.����һ�������������������k�����
struct Node* FindKthToTail(Node* head, int k){
	//����˫ָ�룬һǰһ��
	Node *front = head;
	Node *back = head;
	//ǰ��ָ������k-1��
	int i;
	for (i = 0; i < k - 1; i++){
		front = front->next;
	}
	//
	if (front == NULL){
		if (i <= k - 1){
			//����ѭ��û����
			return NULL;
		}
	}
	//��ͬʱ����
	while (front != NULL){
		front = front->next;
		if (front == NULL){
			break;
		}
		back = back->next;
	}
	return back;
}
