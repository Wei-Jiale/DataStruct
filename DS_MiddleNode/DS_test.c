#include <stdio.h>
//����Ľ��ṹ��
typedef struct Node{
	int value;
	struct Node *next;//��������һ�����ĵ�ַ
}Node;
//5.����һ������ͷ����head�ķǿյ���������������м��㣨����������м��㣬�򷵻صڶ����м��㣩
struct Node* middleNode(Node* head){
	//����˫ָ�룬һ��һ��
	Node *fast = head;
	Node *slow = head;
	//˫ָ�뿪ʼ����
	while (fast != NULL){
		fast = fast->next;
		if (fast == NULL){
			break;
		}
		slow = slow->next;
		fast = fast->next;

	}
	return slow;
}