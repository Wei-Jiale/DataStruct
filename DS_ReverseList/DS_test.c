#include <stdio.h>
//����Ľ��ṹ��
typedef struct Node{
	int value;
	struct Node *next;//��������һ�����ĵ�ַ
}Node;
//2.��ת����
//���������ó����ͷ���ڽ������
struct Node* reverseList(Node*head){
	//����������
	Node* result = NULL;
	//����
	Node* node = head;
	while (node != NULL)
	{
		Node*next = node->next;
		//ͷ��
		node->next = result;
		result = node;
		//����
		node = next;
	}
	return result;
}
//ֱ�Ӹı�ָ�� ǰ�����
struct Node* reverseList(Node*head){
	//��Ϊ������
	if (head == NULL){
		return NULL;
	}
	//��Ϊ������
	Node*prev = NULL;
	Node*cur = head;
	Node*next = cur->next;

	//����
	while (cur != NULL){
		//ָ��ǰ��
		cur->next = prev;

		prev = cur;
		cur = next;

		if (next != NULL){
			next = next->next;
		}
	}
	return prev;
}
