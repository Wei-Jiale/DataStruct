//��������в�������
#include<stdio.h>
struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* insertionSortList(struct ListNode* head){
	//�ж������Ƿ�Ϊ�ջ���ֻ��һ�����
	if (head == NULL || head->next == NULL){
		return head;
	}

	//�����Ѿ����������ǰ�벿�֣�
	struct ListNode* node = head;
	//������δ�����������벿�֣�
	struct ListNode* cur = head->next;
	//�ָ�������
	node->next = NULL;

	while (cur){
		if (cur->val<node->val){
			//ͷ�嵽��������
			head = cur;
			cur = cur->next;
			head->next = node;
			node = head;
		}
		else{
			while (node->next != NULL&&cur->val >= node->next->val){
				node = node->next;
			}

			//��һ�������node->next == NULLβ��
			if (node->next == NULL){
				node->next = cur;
				cur = cur->next;
				node->next->next = NULL;
				//һ�β������ node���»ص�ͷ��
				node = head;
			}
			//�ڶ�����������м����
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