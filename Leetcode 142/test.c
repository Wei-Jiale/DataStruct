//返回链表开始入环的第一个结点
//定义快慢指针
//先判断链表是否带环
//求出相遇点
//两个指针从头和相遇点一起出发 相遇则是环的入口点
#include<stdio.h>
struct ListNode {
	int val;
    struct ListNode *next;
};

struct ListNode *detectCycle(struct ListNode *head) {
	struct ListNode* slow = head;
	struct ListNode* fast = head;
	//先找到相遇点
	while (fast&&fast->next){
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast){
			//相遇点
			struct ListNode* meet = slow;
			while (1){
				//公式证明
				//L = NC-X
				if (meet == head){
					return meet;
				}
				else{
					meet = meet->next;
					head = head->next;
				}
			}
		}
	}
	return NULL;

}