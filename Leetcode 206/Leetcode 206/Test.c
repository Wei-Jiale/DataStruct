//��תһ��������

#include<stdio.h>
struct ListNode {
	int val;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head){
	//����������
	struct ListNode* result = NULL;
	struct ListNode* cur = head;
	//������
	if (head == NULL){
		return NULL;
	}
	//����ԭ������
	//ͷ�嵽�������
	while (cur != NULL){
		struct ListNode* next = cur->next;
		//ͷ��
		cur->next = result;
		result = cur;
		cur = next;
	}
	return result;
}

//����������
//����ԭ������
//ͷ�嵽�������
//��Ҫ����Ϊ����������