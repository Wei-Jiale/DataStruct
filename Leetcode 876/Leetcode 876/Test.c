//��ͷ�ǿյ����������м���
//����������м����򷵻صڶ���

#include<stdio.h>

struct ListNode {
	int val;
    struct ListNode *next;
};

struct ListNode* middleNode(struct ListNode* head){
	struct ListNode* slow = head;
	struct ListNode* fast = head;

	while (fast != NULL&&fast->next != NULL){
		slow = slow->next;
		fast = fast->next->next;
	}

	return slow;
}

//�������ָ��fast slow
//���ֽ�����Ϊż����������
//ע��while�е���ֹ����