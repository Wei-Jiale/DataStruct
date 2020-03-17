//镜像对称的二叉树
#include<stdio.h>
#include<stdbool.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

bool isMirror(struct TreeNode *p, struct TreeNode *q){
	//两个树的层面
	if (p == NULL&& q == NULL){
		return true;
	}

	if (p == NULL || q == NULL){
		return false;
	}

	//值相等并且镜像对称
	return (p->val == q->val) && isMirror(p->left, q->right) && isMirror(p->right, q->left);
}

bool isSymmetric(struct TreeNode* root){
	//空树符合题意
	if (root == NULL){
		return true;
	}

	//递归根的左右子树
	return isMirror(root->left, root->right);
}

