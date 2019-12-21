#include<stdio.h>
#include<stdlib.h>

class Node {
	public:
	int val;
	Node* next;
	Node* random;

	Node(int _val) {
		val = _val;
		next = NULL;
		random = NULL;
	}
};

class Solution {
public:
	Node* copyRandomList(Node* head) {
		//1.������㲢���뵽ԭ���ĺ���
		Node* cur = head;
		while (cur){
			Node* next = cur->next;

			//��ʼ��
			Node* copyNode = (Node*)malloc(sizeof(Node));
			copyNode->val = cur->val;
			copyNode->next = NULL;
			copyNode->random = NULL;

			//����
			cur->next = copyNode;
			copyNode->next = next;

			//����
			cur = next;
		}

		//2.��random
		cur = head;
		while (cur){
			Node* copyNode = cur->next;

			//cur->random����Ϊ��
			if (cur->random != NULL){
				copyNode->random = cur->random->next;
			}
			else{
				copyNode->random = NULL;
			}

			cur = cur->next->next;
		}

		//3.����copyNode
		Node* copyHead = NULL;
		Node* copyTail = NULL;
		cur = head;
		while (cur){
			Node* copyNode = cur->next;
			Node* next = copyNode->next;

			//β��
			if (copyTail == NULL){
				copyHead = copyTail = copyNode;
			}
			else{
				copyTail->next = copyNode;
				copyTail = copyNode;
			}

			//ԭ������
			cur->next = next;
			//����
			cur = next;
		}

		return copyHead;
	}
};