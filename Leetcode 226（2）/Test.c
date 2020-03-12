//翻转二叉树
//交换二叉树的左右孩子
#include<stdio.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* invertTree(struct TreeNode* root){
	//空树返回0
	if (root == NULL){
		return NULL;
	}

	//实现交换
	struct TreeNode* temp = root->left;
	root->left = root->right;
	root->right = temp;

	//递归
	invertTree(root->left);
	invertTree(root->right);

	return root;
}