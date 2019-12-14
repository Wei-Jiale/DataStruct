//��һ������������У������ظ��Ľ�㣬��ɾ�����������ظ��Ľ�㣬�ظ��Ľ�㲻��������������ͷָ�롣 
//���� ����1->2->3->3->4->4->5 �����Ϊ 1->2->5
#include<stdio.h>

typedef struct ListNode {
	int val;
	struct ListNode *next;
}	ListNode;

ListNode* deleteDuplication(ListNode* pHead){
	//�����п�
	if (pHead == NULL){
		return NULL;
	}

	//����һ���ٽ�㣨����ÿ����㶼�����Լ���ǰ����㣩
	ListNode* fake = (ListNode*)malloc(sizeof(ListNode));
	fake->next = pHead;

	ListNode* prev = fake;
	ListNode* back = pHead;
	ListNode* front = pHead->next;

	while (front != NULL){
		if (back->val != front->val){
			prev = back;
			back = front;
			front = front->next;
		}
		else{
			//front->val == back->val  frontһֱ������
			while (front != NULL&&back->val == front->val){
				front = front->next;
			}
			//front�������back->val!=front->val
			prev->next = front;

			//�ı�back��front��ָ��
			back = front;

			if (front != NULL){
				front = front->next;
			}
		}
	}

	pHead = fake->next;
	free(fake);
	return pHead;
}