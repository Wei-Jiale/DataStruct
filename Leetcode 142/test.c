//��������ʼ�뻷�ĵ�һ�����
//�������ָ��
//���ж������Ƿ����
//���������
//����ָ���ͷ��������һ����� �������ǻ�����ڵ�
#include<stdio.h>
struct ListNode {
	int val;
    struct ListNode *next;
};

struct ListNode *detectCycle(struct ListNode *head) {
	struct ListNode* slow = head;
	struct ListNode* fast = head;
	//���ҵ�������
	while (fast&&fast->next){
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast){
			//������
			struct ListNode* meet = slow;
			while (1){
				//��ʽ֤��
				//L = NC-X
				if (meet == head){
					return meet;
				}
				else{
					meet = meet->next;
					head = head->next;
				}
			}
		}
	}
	return NULL;

}