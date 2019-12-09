//分割链表
//给定一个基准值 遍历原有链表
//定义两个结果链表一个存放小于基准值的 一个存放大于等于基准值的
//再将两链表合并
//尤其注意其中一个链表为空的情况

#include<stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* partition(struct ListNode* head, int x){
	//定义结果链表
	struct ListNode* small = NULL;
	struct ListNode* small_last = NULL;

	struct ListNode* big = NULL;
	struct ListNode* big_last = NULL;

	struct ListNode* cur = head;

	if (head == NULL){
		return NULL;
	}

	while (cur){
		if (cur->val < x){
			if (small == NULL){
				small = cur;
				small_last = cur;
			}
			else{
				small_last->next = cur;
				small_last = cur;
			}
		}
		else{
			if (big == NULL){
				big = cur;
				big_last = cur;
			}
			else{
				big_last->next = cur;
				big_last = cur;
			}
		}

		cur = cur->next;
	}


	//注意！ 当原链表全部小于基准值或者全部大于等于基准值的时候
	if (small == NULL){
		//big_last->next == NULL;
		return big;
	}
	else if (big == NULL){
		//small_last->next == NULL;
		return small;
	}
	else{
		small_last->next = big;
		big_last->next = NULL;
		return small;
	}
}