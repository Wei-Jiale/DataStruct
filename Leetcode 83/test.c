//ɾ�������е��ظ�Ԫ��
//1->2->2->3->3
//1->2->3
#include<stdio.h>
struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* deleteDuplicates(struct ListNode* head){

	if (head == NULL){
		return head;
	}

	struct ListNode* back = head;
	struct ListNode* front = head->next;

	while (front){

		if (back->val == front->val){
			while (front != NULL&&back->val == front->val){
				struct ListNode* node = front->next;
				free(front);
				front = node;
			}

			//����ѭ���������
			if (front == NULL){
				back->next = NULL;
			}
			else{
				back->next = front;
				back = front;
				front = front->next;
			}

		}
		else{
			back = front;
			front = front->next;
		}
	}
	return head;
}