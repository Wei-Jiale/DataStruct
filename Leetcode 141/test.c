//环形链表
//快慢指针
//慢指针一次走一步 快指针一次走两步
#include<stdio.h>
#include<stdbool.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

bool hasCycle(struct ListNode *head) {
	struct ListNode* slow = head;
	struct ListNode* fast = head;

	while (fast&&fast->next){
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast){
			return true;
		}
	}

	return false;
}