//删除链表中倒数第n个结点

#include<stdio.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
	//链表判空
	if (head == NULL || n == 0 ){
		return NULL;
	}

	//定义快慢指针
	struct ListNode* front = head;
	struct ListNode* back = head;

	//快指针先走k步
	while (n--){
		//n大于结点个数
		if (front == NULL){
			return NULL;
		}
		front = front->next;
	}

	//当k等于结点个数时
	if (front == NULL){
		return head->next;
	}

	while (front->next){
		//快慢指针再一起走
		front = front->next;
		back = back->next;
	}

	//记录待移除的结点
	struct ListNode* remove = back->next;
	back->next = remove->next;
	free(remove);

	return head;

}