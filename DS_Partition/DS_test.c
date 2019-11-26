#include <stdio.h>
//链表的结点结构体
typedef struct Node{
	int value;
	struct Node *next;//保存着下一个结点的地址
}Node;
//4.以一个x为基准将链表分割成两部分，所有小于x的结点排在大于或等于x的结点之前（分割后保持原来的数据顺序不变）
struct Node* partition(Node*head, int x){
	Node* small = NULL;
	Node* small_last = NULL;

	Node* big = NULL;
	Node* big_last = NULL;

	Node*cur = head;
	while (cur != NULL){
		Node*next = cur->next;
		cur->next = NULL; // （big的last应指向空）
		if (cur->value < x){
			//尾插到small
			if (small == NULL){
				//small为空
				small = small_last = cur;
			}
			else{
				//small不为空
				small_last->next = cur;
				small_last = cur;
			}
		}
		else{
			if (big == NULL){
				//big为空
				big = big_last = cur;
			}
			else{
				//big不为空
				big_last->next = cur;
				big_last = cur;
			}
		}
		cur = next;
	}
	// small  big  拼接  
	if (small == NULL){
		return big;
	}
	else if (big == NULL){
		return small;
	}
	else{
		small_last->next = big;
		return small;
	}

}
