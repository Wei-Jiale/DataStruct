#include <stdio.h>
//链表的结点结构体
typedef struct Node{
	int value;
	struct Node *next;//保存着下一个结点的地址
}Node;
//8.在一个有序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回该链表的头指针。
struct Node* deleteDuplication(Node* Head){
	//创建一个假结点（这样每个结点都有自己的前驱）
	if (Head == NULL){
		return NULL;
	}
	Node *fake = (Node*)malloc(sizeof(Node));
	fake->next = Head;

	Node*prev = fake;
	Node*p1 = Head;
	Node*p2 = Head->next;

	while (p2!=NULL)
	{
		if (p1->value != p2->value){
			prev = p1;
			p1 = p2;
			p2 = p2->next;
		}
		else{
			while (p2!=NULL&&p1->value == p2->value)
			{
				p2 = p2->next;
			}
			//p2要不走完 要不遇到不相等
			prev->next = p2;//删除

			p1 = p2;
			if (p2 != NULL){
				p2 = p2->next;
			}

		}
	}
	Head = fake->next;
	free(fake);
	return Head;
};