#include <stdio.h>
//链表的结点结构体
typedef struct Node{
	int value;
	struct Node *next;//保存着下一个结点的地址
}Node;

//9.交叉链表判断交叉点
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