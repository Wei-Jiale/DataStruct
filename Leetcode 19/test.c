//ɾ�������е�����n�����

#include<stdio.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
	//�����п�
	if (head == NULL || n == 0 ){
		return NULL;
	}

	//�������ָ��
	struct ListNode* front = head;
	struct ListNode* back = head;

	//��ָ������k��
	while (n--){
		//n���ڽ�����
		if (front == NULL){
			return NULL;
		}
		front = front->next;
	}

	//��k���ڽ�����ʱ
	if (front == NULL){
		return head->next;
	}

	while (front->next){
		//����ָ����һ����
		front = front->next;
		back = back->next;
	}

	//��¼���Ƴ��Ľ��
	struct ListNode* remove = back->next;
	back->next = remove->next;
	free(remove);

	return head;

}