//ɾ�������е��ڸ���ֵval�����н��
#include<stdio.h>
struct ListNode {
     int val;
     struct ListNode *next;
};

struct ListNode* removeElements(struct ListNode* head, int val){
	struct ListNode* cur = head;
	//����������
	struct ListNode* result = NULL;
	//��������������һ�����
	struct ListNode* last = NULL;
	//����Ϊ��
	if (head == NULL){
		return NULL;
	}
	//��������
	while (cur != NULL){
		//����Ŀ��ֵ��β�嵽�������
		if (cur->val != val){
			//��һ�ν���
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
	//���һ����㲻Ϊ��ʱ
	if (last != NULL){
		last->next = NULL;
	}
	return result;
}

//����������
//������ǰ����
//����Ŀ��ֵ�Ľ��ȡ��β�嵽�������

//����ע�⵱���һ�����last!=NULLʱ