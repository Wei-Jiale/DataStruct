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
		//1.拷贝结点并插入到原结点的后面
		Node* cur = head;
		while (cur){
			Node* next = cur->next;

			//初始化
			Node* copyNode = (Node*)malloc(sizeof(Node));
			copyNode->val = cur->val;
			copyNode->next = NULL;
			copyNode->random = NULL;

			//链接
			cur->next = copyNode;
			copyNode->next = next;

			//遍历
			cur = next;
		}

		//2.置random
		cur = head;
		while (cur){
			Node* copyNode = cur->next;

			//cur->random可能为空
			if (cur->random != NULL){
				copyNode->random = cur->random->next;
			}
			else{
				copyNode->random = NULL;
			}

			cur = cur->next->next;
		}

		//3.拆下copyNode
		Node* copyHead = NULL;
		Node* copyTail = NULL;
		cur = head;
		while (cur){
			Node* copyNode = cur->next;
			Node* next = copyNode->next;

			//尾插
			if (copyTail == NULL){
				copyHead = copyTail = copyNode;
			}
			else{
				copyTail->next = copyNode;
				copyTail = copyNode;
			}

			//原链表缝合
			cur->next = next;
			//遍历
			cur = next;
		}

		return copyHead;
	}
};