#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	char value;
	struct Node *left;
	struct Node *right;
}	Node;
//二叉树中查找一个结点
//1.空树返回NULL
//2.如果根的值为查找值直接返回根的地址
//3.根不是，则去左子树查找
//4.左子树找到直接返回
//5.左子树找不到，则去右子树
//6.右子树找到直接返回
//7.找不到返回NULL
Node*Find(Node*root, char v){
	if (root == NULL){
		return NULL;
	}
	if (root->value == v){
		return root;
	}
	Node*result = Find(root->left, v);
	if (result != NULL){
		return result;
	}

	result = Find(root->right, v);
	if (result != NULL){
		return result;
	}

	return NULL;
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


	Find(a, 'F');

	return 0;
}