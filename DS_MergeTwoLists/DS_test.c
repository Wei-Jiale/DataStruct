#include <stdio.h>
//链表的结点结构体
typedef struct Node{
	int value;
	struct Node *next;//保存着下一个结点的地址
}Node;
//3.将两个有序链表合成为一个新的有序链表（两个链表不一定等长）
//两个链表分别都有一个指针，谁小取出谁头插到结果链表
struct Node* mergeTwoLists(Node*l1, Node*l2){
	//判断是否有空链表
	if (l1 == NULL){
		return l2;
	}
	if (l2 == NULL){
		return l1;
	}

	Node*c1 = l1;
	Node*c2 = l2;
	Node*result = NULL;
	Node*last = NULL;
	//同时遍历两个链表(都不为空才能进行下面的比较）
	while (c1 != NULL&&c2 != NULL){
		if (c1->value <= c2->value){
			Node*next = c1->next;

			c1->next = NULL;
			if (result == NULL){
				result = c1;
				last = c1;
			}
			else{
				last->next = c1;
				last = c1;
			}
			c1 = next;
		}
		else{
			Node*next = c2->next;

			c2->next = NULL;
			if (result == NULL){
				result = c2;
				last = c2;
			}
			else{
				last->next = c2;
				last = c2;
			}
			c2 = next;
		}
	}
	//一个链表会被搬空
	//不为空则剩余
	if (c1 != NULL){
		last->next = c1;
	}
	if (c2 != NULL){
		last->next = c2;
	}
	return result;
}