//带头非空单链表返回中间结点
//如果有两个中间结点则返回第二个

#include<stdio.h>

struct ListNode {
	int val;
    struct ListNode *next;
};

struct ListNode* middleNode(struct ListNode* head){
	struct ListNode* slow = head;
	struct ListNode* fast = head;

	while (fast != NULL&&fast->next != NULL){
		slow = slow->next;
		fast = fast->next->next;
	}

	return slow;
}

//定义快慢指针fast slow
//区分结点个数为偶数还是奇数
//注意while中的终止条件