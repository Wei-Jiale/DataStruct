#include <stdio.h>
//����Ľ��ṹ��
typedef struct Node{
	int value;
	struct Node *next;//��������һ�����ĵ�ַ
}Node;
//3.��������������ϳ�Ϊһ���µ�����������������һ���ȳ���
//��������ֱ���һ��ָ�룬˭Сȡ��˭ͷ�嵽�������
struct Node* mergeTwoLists(Node*l1, Node*l2){
	//�ж��Ƿ��п�����
	if (l1 == NULL){
		return l2;
	}
	if (l2 == NULL){
		return l1;
	}

	Node*c1 = l1;
	Node*c2 = l2;
	Node*result = NULL;
	Node*last = NULL;
	//ͬʱ������������(����Ϊ�ղ��ܽ�������ıȽϣ�
	while (c1 != NULL&&c2 != NULL){
		if (c1->value <= c2->value){
			Node*next = c1->next;

			c1->next = NULL;
			if (result == NULL){
				result = c1;
				last = c1;
			}
			else{
				last->next = c1;
				last = c1;
			}
			c1 = next;
		}
		else{
			Node*next = c2->next;

			c2->next = NULL;
			if (result == NULL){
				result = c2;
				last = c2;
			}
			else{
				last->next = c2;
				last = c2;
			}
			c2 = next;
		}
	}
	//һ������ᱻ���
	//��Ϊ����ʣ��
	if (c1 != NULL){
		last->next = c1;
	}
	if (c2 != NULL){
		last->next = c2;
	}
	return result;
}