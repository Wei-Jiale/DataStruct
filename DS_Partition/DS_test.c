#include <stdio.h>
//����Ľ��ṹ��
typedef struct Node{
	int value;
	struct Node *next;//��������һ�����ĵ�ַ
}Node;
//4.��һ��xΪ��׼������ָ�������֣�����С��x�Ľ�����ڴ��ڻ����x�Ľ��֮ǰ���ָ�󱣳�ԭ��������˳�򲻱䣩
struct Node* partition(Node*head, int x){
	Node* small = NULL;
	Node* small_last = NULL;

	Node* big = NULL;
	Node* big_last = NULL;

	Node*cur = head;
	while (cur != NULL){
		Node*next = cur->next;
		cur->next = NULL; // ��big��lastӦָ��գ�
		if (cur->value < x){
			//β�嵽small
			if (small == NULL){
				//smallΪ��
				small = small_last = cur;
			}
			else{
				//small��Ϊ��
				small_last->next = cur;
				small_last = cur;
			}
		}
		else{
			if (big == NULL){
				//bigΪ��
				big = big_last = cur;
			}
			else{
				//big��Ϊ��
				big_last->next = cur;
				big_last = cur;
			}
		}
		cur = next;
	}
	// small  big  ƴ��  
	if (small == NULL){
		return big;
	}
	else if (big == NULL){
		return small;
	}
	else{
		small_last->next = big;
		return small;
	}

}
