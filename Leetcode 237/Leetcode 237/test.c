//只删除链表中给定结点（只给定了被删除的结点）
//将下一个结点的值赋给被删除的结点
//再删除下一个结点

#include<stdio.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

void deleteNode(struct ListNode* node) {
	node->val = node->next->val;
	node->next = node->next->next;
}