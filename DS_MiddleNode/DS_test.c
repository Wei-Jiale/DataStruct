#include <stdio.h>
//链表的结点结构体
typedef struct Node{
	int value;
	struct Node *next;//保存着下一个结点的地址
}Node;
//5.给定一个带有头结点的head的非空单链表，返回链表的中间结点（如果有两个中间结点，则返回第二个中间结点）
struct Node* middleNode(Node* head){
	//定义双指针，一快一慢
	Node *fast = head;
	Node *slow = head;
	//双指针开始遍历
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