#include <stdio.h>
//����Ľ��ṹ��
typedef struct Node{
	int value;
	struct Node *next;//��������һ�����ĵ�ַ
}Node;
//1.ɾ�������е��ڸ���ֵval�����н��
//�������������н�㣬�������value �Ͱ�������β�嵽�µ�������
struct Node* removeElements(struct ListNode* head, int val){
	//����������
	Node *result = NULL;
	//��¼result�����һ�����
	Node *last = NULL;
	//����ԭ������
	Node *node = head;
	while (node != NULL){
		Node *next = node->next;

		if (node->value != val){
			//β�嵽�������
			if (last == NULL){
				//�������Ϊ��
				result = node;
				last = node;
			}
			else{
				last->next = node;
				last = node;
			}
		}
		node = next;
	}
	if (last != NULL){
		last->next = NULL;
	}
	return result;
}
//ɾ������
struct Node* removeElements(Node* head, int val){
	if (head == NULL){
		return NULL;
	}
	Node *cur = head;
	while (cur->next != NULL)
	{
		if (cur->next->value == val){
			Node* next = cur->next;
			cur->next = next->next;
			free(next);
		}
		else{
			cur = cur->next;
		}
	}
	if (head->value == val){
		Node *second = head->next;
		free(head);
		return second;
	}
	else{
		return head;
	}
}