#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	char value;
	struct Node *left;
	struct Node *right;
}	Node;
//�����������������
int count = 0;
void PreorderCount(Node* root){
	if (root != NULL){
		//��
		count++;
		PreorderCount(root->left);
		PreorderCount(root->right);
	}
}
//������
//���ƹ�ʽ��������������+������������+1
//��ֹ������1.���� return 0;
int NodeSzie(Node*root){
	if (root == NULL){
		return 0;
	}
	else if (root->left == NULL&&root->right == NULL){
		return 1;
	}
	else{
		//����Ϊ������� ������+������+��
		int left = NodeSzie(root->left);
		int right = NodeSzie(root->right);
		return left + right + 1;
	}
}

//Ҷ�ӽ�����
int LeafSzie(Node*root){
	if (root == NULL){
		return 0;
	}
	else if (root->left == NULL&&root->right == NULL){
		return 1;
	}
	else{
		//����Ϊ������� ������+������+��
		int left = LeafSzie(root->left);
		int right = LeafSzie(root->right);
		return left + right;
	}
}

//�������߶�
#define MAX(a,b) ((a)>(b)?(a):(b))
int Height(Node*root){
	if (root == NULL){
		return 0;
	}

	int left = Height(root->left);
	int right = Height(root->right);

	return MAX(left, right) + 1;
}
//���K�������
//���� �󣺵�K-1��  �ң���K-1��  ��K��left+right
//��ֹ ��������0; 
int LevelSize(Node*root,int k){
	if (root == NULL){
		return 0;
	}
	if (k == 1){
		return 1;
	}
	else{
		int left = LevelSize(root->left, k - 1);
		int right = LevelSize(root->right, k - 1);
		return left + right;
	}
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

	printf("������=%d\n", NodeSzie(a));
	printf("Ҷ�ӽ�����=%d\n", LeafSzie(a));
	printf("�������߶�=%d\n", Height(a));

	for (int i = 1; i <= 5; i++){
		printf("��%d���н�㣺%d��\n", i, LevelSize(a,i));
	}

	return 0;
}