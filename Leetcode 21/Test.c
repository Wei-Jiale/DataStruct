//合并两个有序链表

#include<stdio.h>
struct ListNode {
	int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
	//定义结果链表
	struct ListNode* result = NULL;
	struct ListNode* last = NULL;

	//其中有一个链表为空可直接返回另一个
	if (l1 == NULL){
		return l2;
	}
	if (l2 == NULL){
		return l1;
	}

	while (l1&&l2){
		if (l1->val <= l2->val){
			//刚开始result为空时
			if (result == NULL){
				result = l1;
				last = l1;
			}
			else{
				last->next = l1;
				last = l1;
			}

			l1 = l1->next;
		}
		else{
			//刚开始result为空时
			if (result == NULL){
				result = l2;
				last = l2;
			}
			else{
				last->next = l2;
				last = l2;
			}

			l2 = l2->next;
		}
	}

	//已经有一个链表被搬空的情况
	if (l1 == NULL){
		last->next = l2;
	}
	if (l2 == NULL){
		last->next = l1;
	}

	return result;
}


//定义结果链表
//两链表依次遍历比较
//较小的头插到结果链表
//直到有一个链表被搬空
