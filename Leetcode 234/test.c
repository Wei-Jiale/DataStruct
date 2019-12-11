#include<stdio.h>
#include<stdbool.h>

//����Ľ��ṹ��
typedef struct Node{
	int value;
	struct Node *next;//��������һ�����ĵ�ַ
}Node;
//����Ļ��Ľṹ����ǰ���ʹӺ�һ������ABCBA,ABCCBA)
bool Palindrome(Node*head){
	//��������
	int len = 0;
	for (Node*cur = head; cur != NULL; cur = cur->next){
		len++;
	}
	//�ҵ�������м���
	Node*middle = head;
	for (int i = 0; i < len / 2; i++){
		middle = middle->next;
	}
	//���ú�һ������
	Node*node = middle;
	Node*rhead = NULL;
	while (node != NULL)
	{
		Node*next = node->next;
		//ͷ�嵽�������
		node->next = rhead;
		rhead = node;
		node = next;
	}
	//�Ƚ��Ƿ����
	Node*p1 = head;
	Node*p2 = rhead;
	while (p1 != NULL&&p2 != NULL)
	{
		if (p1->value != p2->value){
			return false;
		}
		p1 = p1->next;
		p2 = p2->next;
	}

	return true;

}