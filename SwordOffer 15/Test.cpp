#include<stdio.h>

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
	val(x), next(NULL) {
	}
};

class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		ListNode* fast = pListHead;
		ListNode* slow = pListHead;

		//ͷ���Ϊ�ջ���k=0  
		if (pListHead == NULL || k == 0){
			return NULL;
		}

		//��ָ������k��
		while (k--){

			//��k��ֵ�����������ܸ���
			if (fast == NULL){
				return NULL;
			}
			fast = fast->next;
		}

		//����ָ����һ����
		while (fast){
			slow = slow->next;
			fast = fast->next;
		}

		return slow;
	}
};