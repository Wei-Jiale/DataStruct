//翻转一个单链表

#include<stdio.h>
struct ListNode {
	int val;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head){
	//定义结果链表
	struct ListNode* result = NULL;
	struct ListNode* cur = head;
	//空链表
	if (head == NULL){
		return NULL;
	}
	//遍历原有链表
	//头插到结果链表
	while (cur != NULL){
		struct ListNode* next = cur->next;
		//头插
		cur->next = result;
		result = cur;
		cur = next;
	}
	return result;
}

//定义结果链表
//遍历原有链表
//头插到结果链表
//需要考虑为空链表的情况