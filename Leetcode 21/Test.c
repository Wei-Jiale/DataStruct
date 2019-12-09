//�ϲ�������������

#include<stdio.h>
struct ListNode {
	int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
	//����������
	struct ListNode* result = NULL;
	struct ListNode* last = NULL;

	//������һ������Ϊ�տ�ֱ�ӷ�����һ��
	if (l1 == NULL){
		return l2;
	}
	if (l2 == NULL){
		return l1;
	}

	while (l1&&l2){
		if (l1->val <= l2->val){
			//�տ�ʼresultΪ��ʱ
			if (result == NULL){
				result = l1;
				last = l1;
			}
			else{
				last->next = l1;
				last = l1;
			}

			l1 = l1->next;
		}
		else{
			//�տ�ʼresultΪ��ʱ
			if (result == NULL){
				result = l2;
				last = l2;
			}
			else{
				last->next = l2;
				last = l2;
			}

			l2 = l2->next;
		}
	}

	//�Ѿ���һ��������յ����
	if (l1 == NULL){
		last->next = l2;
	}
	if (l2 == NULL){
		last->next = l1;
	}

	return result;
}


//����������
//���������α����Ƚ�
//��С��ͷ�嵽�������
//ֱ����һ���������
