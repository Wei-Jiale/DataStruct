#include <stdio.h>
//����Ľ��ṹ��
typedef struct Node{
	int value;
	struct Node *next;//��������һ�����ĵ�ַ
}Node;

//9.���������жϽ����
int getlen(Node*head){
	int len = 0;
	for (Node*cur = head; cur != NULL; cur = cur->next){
		len++;
	}
	return len;
}

struct Node* Intersection(Node*headA, Node*headB){
	int lenA = getlen(headA);
	int lenB = getlen(headB);

	Node*longer = headA;
	Node*shorter = headB;
	int diff = lenA - lenB;

	if (lenB > lenA){
		longer = headB;
		shorter = headA;
		diff = lenB - lenA;
	}
	for (int i = 0; i < diff; i++){
		longer = longer->next;
	}
	while (longer != shorter)
	{
		longer = longer->next;
		shorter = shorter->next;
	}
	return longer;
};