//删除链表中等于给定值val的所有结点
#include<stdio.h>
struct ListNode {
     int val;
     struct ListNode *next;
};

struct ListNode* removeElements(struct ListNode* head, int val){
	struct ListNode* cur = head;
	//定义结果链表
	struct ListNode* result = NULL;
	//定义结果链表的最后一个结点
	struct ListNode* last = NULL;
	//链表为空
	if (head == NULL){
		return NULL;
	}
	//遍历链表
	while (cur != NULL){
		//不是目标值则尾插到结果链表
		if (cur->val != val){
			//第一次进来
			if (last == NULL){
				last = cur;
				result = cur;
			}
			else{
				last->next = cur;
				last = cur;
			}
		}
		cur = cur->next;
	}
	//最后一个结点不为空时
	if (last != NULL){
		last->next = NULL;
	}
	return result;
}

//定义结果链表
//遍历当前链表
//不是目标值的结点取出尾插到结果链表

//尤其注意当最后一个结点last!=NULL时