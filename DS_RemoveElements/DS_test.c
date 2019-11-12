#include <stdio.h>
//链表的结点结构体
typedef struct Node{
	int value;
	struct Node *next;//保存着下一个结点的地址
}Node;
//1.删除链表中等于给定值val的所有结点
//遍历链表中所有结点，如果不是value 就把这个结点尾插到新的链表上
struct Node* removeElements(struct ListNode* head, int val){
	//定义结果链表
	Node *result = NULL;
	//记录result的最后一个结点
	Node *last = NULL;
	//遍历原有链表
	Node *node = head;
	while (node != NULL){
		Node *next = node->next;

		if (node->value != val){
			//尾插到结果链表
			if (last == NULL){
				//结果链表为空
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
//删除所有
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