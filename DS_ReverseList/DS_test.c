#include <stdio.h>
//链表的结点结构体
typedef struct Node{
	int value;
	struct Node *next;//保存着下一个结点的地址
}Node;
//2.反转链表
//遍历链表，拿出结点头插在结果链表
struct Node* reverseList(Node*head){
	//定义结果链表
	Node* result = NULL;
	//遍历
	Node* node = head;
	while (node != NULL)
	{
		Node*next = node->next;
		//头插
		node->next = result;
		result = node;
		//遍历
		node = next;
	}
	return result;
}
//直接改变指向 前驱结点
struct Node* reverseList(Node*head){
	//若为空链表
	if (head == NULL){
		return NULL;
	}
	//不为空链表
	Node*prev = NULL;
	Node*cur = head;
	Node*next = cur->next;

	//遍历
	while (cur != NULL){
		//指向前驱
		cur->next = prev;

		prev = cur;
		cur = next;

		if (next != NULL){
			next = next->next;
		}
	}
	return prev;
}
