//找到两个单链表相交的起始节点
//先得出两链表的长度
//定义一个长链表一个短链表 求出它们的差diff
//长链表先走diff步 然后两链表再同时走
//直到长链表地址等于短链表地址
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
	//得到两链表长度
	int lenA = getlen(headA);
	int lenB = getlen(headB);

	//定义长短链表
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