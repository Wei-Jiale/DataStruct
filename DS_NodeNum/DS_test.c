#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	char value;
	struct Node *left;
	struct Node *right;
}	Node;
//遍历求二叉树结点个数
int count = 0;
void PreorderCount(Node* root){
	if (root != NULL){
		//根
		count++;
		PreorderCount(root->left);
		PreorderCount(root->right);
	}
}
//子问题
//递推公式：左子树结点个数+右子树结点个数+1
//终止条件：1.空树 return 0;
int NodeSzie(Node*root){
	if (root == NULL){
		return 0;
	}
	else if (root->left == NULL&&root->right == NULL){
		return 1;
	}
	else{
		//本质为后序遍历 左子树+右子树+根
		int left = NodeSzie(root->left);
		int right = NodeSzie(root->right);
		return left + right + 1;
	}
}

//叶子结点个数
int LeafSzie(Node*root){
	if (root == NULL){
		return 0;
	}
	else if (root->left == NULL&&root->right == NULL){
		return 1;
	}
	else{
		//本质为后序遍历 左子树+右子树+根
		int left = LeafSzie(root->left);
		int right = LeafSzie(root->right);
		return left + right;
	}
}

//二叉树高度
#define MAX(a,b) ((a)>(b)?(a):(b))
int Height(Node*root){
	if (root == NULL){
		return 0;
	}

	int left = Height(root->left);
	int right = Height(root->right);

	return MAX(left, right) + 1;
}
//求第K层结点个数
//递推 左：第K-1层  右：第K-1层  第K层left+right
//终止 空树返回0; 
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

	printf("结点个数=%d\n", NodeSzie(a));
	printf("叶子结点个数=%d\n", LeafSzie(a));
	printf("二叉树高度=%d\n", Height(a));

	for (int i = 1; i <= 5; i++){
		printf("第%d层有结点：%d个\n", i, LevelSize(a,i));
	}

	return 0;
}