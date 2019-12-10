//�ҵ������������ཻ����ʼ�ڵ�
//�ȵó�������ĳ���
//����һ��������һ�������� ������ǵĲ�diff
//����������diff�� Ȼ����������ͬʱ��
//ֱ���������ַ���ڶ������ַ
struct ListNode {
    int val;
    struct ListNode *next;
};

int getlen(struct ListNode* head){
	int len = 0;
	struct ListNode* cur = head;
	while (cur){
		len++;
		cur = cur->next;
	}
	return len;
}

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
	//�õ���������
	int lenA = getlen(headA);
	int lenB = getlen(headB);

	//���峤������
	struct ListNode* longer = headA;
	struct ListNode* shorter = headB;
	int diff = lenA - lenB;

	if (lenB>lenA){
		longer = headB;
		shorter = headA;
		diff = lenB - lenA;
	}

	while (diff--){
		longer = longer->next;
	}

	while (longer != shorter){
		longer = longer->next;
		shorter = shorter->next;
	}

	return longer;

}