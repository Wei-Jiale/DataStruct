#include<stdio.h>
#include<stdlib.h>
//定义二叉树结点
typedef struct Node{
	char value;
	struct Node *left;
	struct Node *right;
}	Node;

//创建树
Node * CreatTree(char preorder[], int size, int *pUsed){
	if (size == 0){
		*pUsed = 0;
		return NULL;
	}
	if (preorder == '#'){
		*pUsed = 1;
		return NULL;
	}
	//根
	Node* root = (Node*)malloc(sizeof(Node));
	root->value = preorder[0];

	//左子树
	int LeftUsed;
	root->left = CreatTree(preorder + 1, size - 1, &LeftUsed);
	//右子树
	int RightUsed;
	root->right = CreatTree(preorder + 1 + LeftUsed, size - 1 - LeftUsed, &RightUsed);

	//处理返回
	*pUsed = 1 + LeftUsed + RightUsed;
	return root;
}