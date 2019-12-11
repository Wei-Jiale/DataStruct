#include<stdio.h>
#include<stdbool.h>

//链表的结点结构体
typedef struct Node{
	int value;
	struct Node *next;//保存着下一个结点的地址
}Node;
//链表的回文结构（从前看和从后看一样）（ABCBA,ABCCBA)
bool Palindrome(Node*head){
	//得链表长度
	int len = 0;
	for (Node*cur = head; cur != NULL; cur = cur->next){
		len++;
	}
	//找到链表的中间结点
	Node*middle = head;
	for (int i = 0; i < len / 2; i++){
		middle = middle->next;
	}
	//逆置后一半链表
	Node*node = middle;
	Node*rhead = NULL;
	while (node != NULL)
	{
		Node*next = node->next;
		//头插到结果链表
		node->next = rhead;
		rhead = node;
		node = next;
	}
	//比较是否回文
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