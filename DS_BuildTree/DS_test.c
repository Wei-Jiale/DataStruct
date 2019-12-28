#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
//定义二叉树结点
typedef struct Node{
	char value;
	struct Node *left;
	struct Node *right;
}	Node;

//前序+中序 还原二叉树(结点不能有重复）
int find(char array[], int size, char v){
	for (int i = 0; i < size; i++){
		if (array[i] == v){
			return i;
		}
	}
	return -1;
}
Node* BuildTree(char preorder[], char inorder[], int size){
	if (size == 0){
		return NULL;
	}

	char rootValue = preorder[0];
	int leftSize = find(inorder, size, rootValue);
	assert(leftSize != -1);

	//根
	Node* root = (Node*)malloc(sizeof(Node));
	root->value = rootValue;

	//左子树(首先找到根在中的位置下标）
	root->left = BuildTree(preorder + 1, inorder, leftSize);
	//右子树
	root->right = BuildTree(preorder + 1 + leftSize, inorder + 1 + leftSize, size - 1 - leftSize);

	return root;
}