#include<stdio.h>

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
	val(x), next(NULL) {
	}
};

class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		ListNode* fast = pListHead;
		ListNode* slow = pListHead;

		//头结点为空或者k=0  
		if (pListHead == NULL || k == 0){
			return NULL;
		}

		//快指针先走k步
		while (k--){

			//当k的值大于链表结点总个数
			if (fast == NULL){
				return NULL;
			}
			fast = fast->next;
		}

		//快慢指针再一起走
		while (fast){
			slow = slow->next;
			fast = fast->next;
		}

		return slow;
	}
};