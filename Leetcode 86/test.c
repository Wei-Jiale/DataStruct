//�ָ�����
//����һ����׼ֵ ����ԭ������
//���������������һ�����С�ڻ�׼ֵ�� һ����Ŵ��ڵ��ڻ�׼ֵ��
//�ٽ�������ϲ�
//����ע������һ������Ϊ�յ����

#include<stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* partition(struct ListNode* head, int x){
	//����������
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


	//ע�⣡ ��ԭ����ȫ��С�ڻ�׼ֵ����ȫ�����ڵ��ڻ�׼ֵ��ʱ��
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