#include <stdio.h>
//����Ľ��ṹ��
typedef struct Node{
	int value;
	struct Node *next;//��������һ�����ĵ�ַ
}Node;
//8.��һ������������У������ظ��Ľ�㣬��ɾ�����������ظ��Ľ�㣬�ظ��Ľ�㲻���������ظ������ͷָ�롣
struct Node* deleteDuplication(Node* Head){
	//����һ���ٽ�㣨����ÿ����㶼���Լ���ǰ����
	if (Head == NULL){
		return NULL;
	}
	Node *fake = (Node*)malloc(sizeof(Node));
	fake->next = Head;

	Node*prev = fake;
	Node*p1 = Head;
	Node*p2 = Head->next;

	while (p2!=NULL)
	{
		if (p1->value != p2->value){
			prev = p1;
			p1 = p2;
			p2 = p2->next;
		}
		else{
			while (p2!=NULL&&p1->value == p2->value)
			{
				p2 = p2->next;
			}
			//p2Ҫ������ Ҫ�����������
			prev->next = p2;//ɾ��

			p1 = p2;
			if (p2 != NULL){
				p2 = p2->next;
			}

		}
	}
	Head = fake->next;
	free(fake);
	return Head;
};