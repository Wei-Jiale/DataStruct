#include<stdio.h>
#include<stdlib.h>
//平衡二叉树（左右子树的高度差不超过1）
//左子树和右子树都得是平衡二叉树

//二叉树
//定义二叉树结点
typedef struct Node{
	char value;
	struct Node *left;
	struct Node *right;
}	Node;

//空树    Node *root == NULL
//只有一个结点    Node *root;  root!=NULL&&root->left == NULL&&root->right == NULL;

//前序遍历(非空结点第一次经过则打印）
//递归
//1.递推公式
//2.终止条件
void preorderTraversal(Node *root){
	if (root == NULL){
		return;
	}
	//根
	printf("%c", root->value);
	//左子树
	preorderTraversal(root->left);
	//右子树
	preorderTraversal(root->right);
}

//中序遍历
void inorderTraversal(Node *root){
	if (root == NULL){
		return;
	}
	//左子树
	inorderTraversal(root->left);
	//根
	printf("%c", root->value);
	//右子树
	inorderTraversal(root->right);
}

//后序遍历
void postorderTraversal(Node *root){
	if (root == NULL){
		return;
	}
	//左子树
	postorderTraversal(root->left);
	//右子树
	postorderTraversal(root->right);
	//根
	printf("%c", root->value);
}

//求结点个数
//1.遍历
//int count = 0;
//void GetSize(Node*root){
//	if (root == NULL){
//		return;
//	}
//	//根
//	count++;
//	GetSize(root->left);
//	GetSize(root->right);
//}
//2.归纳收集
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

	printf("前序遍历：\n");
	preorderTraversal(a);
	printf("\n");

	printf("中序遍历：\n");
	inorderTraversal(a);
	printf("\n");

	printf("后序遍历：\n");
	postorderTraversal(a);
	printf("\n");

	printf("结点个数：\n");
	int ret = GetSize(a);
	printf("%d", ret);
	return 0;
}