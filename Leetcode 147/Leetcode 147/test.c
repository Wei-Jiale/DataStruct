//对链表进行插入排序
#include<stdio.h>
struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* insertionSortList(struct ListNode* head){
	//判断链表是否为空或者只有一个结点
	if (head == NULL || head->next == NULL){
		return head;
	}

	//遍历已经有序的链表（前半部分）
	struct ListNode* node = head;
	//遍历还未有序的链表（后半部分）
	struct ListNode* cur = head->next;
	//分隔开链表
	node->next = NULL;

	while (cur){
		if (cur->val<node->val){
			//头插到有序链表
			head = cur;
			cur = cur->next;
			head->next = node;
			node = head;
		}
		else{
			while (node->next != NULL&&cur->val >= node->next->val){
				node = node->next;
			}

			//第一种情况：node->next == NULL尾插
			if (node->next == NULL){
				node->next = cur;
				cur = cur->next;
				node->next->next = NULL;
				//一次插入完成 node重新回到头部
				node = head;
			}
			//第二种情况：在中间插入
			else{
				struct ListNode* temp = cur;
				cur = cur->next;
				temp->next = node->next;
				node->next = temp;
				node = head;
			}
		}
	}
	return head;
}