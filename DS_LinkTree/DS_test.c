#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//定义二叉树结点
typedef struct Node{
	char value;
	struct Node *left;
	struct Node *right;
}	Node;

Node* prev = NULL;
void link(Node* node){
	node->left = prev;
	if (prev != NULL){
		prev->right = node;
	}
	prev = node;
}
void InOrder(Node *root){
	if (root != NULL){
		InOrder(root->left);
		link(root);
		InOrder(root->right);
	}
}