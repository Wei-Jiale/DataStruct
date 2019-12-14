//在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 
//例如 链表1->2->3->3->4->4->5 处理后为 1->2->5
#include<stdio.h>

typedef struct ListNode {
	int val;
	struct ListNode *next;
}	ListNode;

ListNode* deleteDuplication(ListNode* pHead){
	//链表判空
	if (pHead == NULL){
		return NULL;
	}

	//创建一个假结点（这样每个结点都会有自己的前驱结点）
	ListNode* fake = (ListNode*)malloc(sizeof(ListNode));
	fake->next = pHead;

	ListNode* prev = fake;
	ListNode* back = pHead;
	ListNode* front = pHead->next;

	while (front != NULL){
		if (back->val != front->val){
			prev = back;
			back = front;
			front = front->next;
		}
		else{
			//front->val == back->val  front一直向后遍历
			while (front != NULL&&back->val == front->val){
				front = front->next;
			}
			//front走完或者back->val!=front->val
			prev->next = front;

			//改变back、front的指向
			back = front;

			if (front != NULL){
				front = front->next;
			}
		}
	}

	pHead = fake->next;
	free(fake);
	return pHead;
}