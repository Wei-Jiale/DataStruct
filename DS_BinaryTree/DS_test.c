#include<stdio.h>
#include<stdlib.h>
//ƽ������������������ĸ߶Ȳ����1��
//��������������������ƽ�������

//������
//������������
typedef struct Node{
	char value;
	struct Node *left;
	struct Node *right;
}	Node;

//����    Node *root == NULL
//ֻ��һ�����    Node *root;  root!=NULL&&root->left == NULL&&root->right == NULL;

//ǰ�����(�ǿս���һ�ξ������ӡ��
//�ݹ�
//1.���ƹ�ʽ
//2.��ֹ����
void preorderTraversal(Node *root){
	if (root == NULL){
		return;
	}
	//��
	printf("%c", root->value);
	//������
	preorderTraversal(root->left);
	//������
	preorderTraversal(root->right);
}

//�������
void inorderTraversal(Node *root){
	if (root == NULL){
		return;
	}
	//������
	inorderTraversal(root->left);
	//��
	printf("%c", root->value);
	//������
	inorderTraversal(root->right);
}

//�������
void postorderTraversal(Node *root){
	if (root == NULL){
		return;
	}
	//������
	postorderTraversal(root->left);
	//������
	postorderTraversal(root->right);
	//��
	printf("%c", root->value);
}

//�������
//1.����
//int count = 0;
//void GetSize(Node*root){
//	if (root == NULL){
//		return;
//	}
//	//��
//	count++;
//	GetSize(root->left);
//	GetSize(root->right);
//}
//2.�����ռ�
int GetSize(Node *root){
	if (root == NULL){
		return 0;
	}
	return GetSize(root->left) + GetSize(root->right) + 1;
}



Node *CreateNode(char value){
	Node *node = (Node*)malloc(sizeof(Node));
	node->value = value;
	node->left = node->right = NULL;
	return node;
}

int main(){
	Node*a = CreateNode('A');
	Node*b = CreateNode('B');
	Node*c = CreateNode('C');
	Node*d = CreateNode('D');
	Node*e = CreateNode('E');
	Node*f = CreateNode('F');
	Node*g = CreateNode('G');
	Node*h = CreateNode('H');

	a->left = b; a->right = c;
	b->left = d; b->right = e;
	c->left = f; c->right = g;
	d->left = NULL; d->right = NULL;
	e->left = NULL; e->right = h;
	f->left = NULL; f->right = NULL;
	g->left = NULL; g->right = NULL;
	h->left = NULL; h->right = NULL;

	printf("ǰ�������\n");
	preorderTraversal(a);
	printf("\n");

	printf("���������\n");
	inorderTraversal(a);
	printf("\n");

	printf("���������\n");
	postorderTraversal(a);
	printf("\n");

	printf("��������\n");
	int ret = GetSize(a);
	printf("%d", ret);
	return 0;
}