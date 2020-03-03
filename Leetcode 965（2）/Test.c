//单值二叉树
//二叉树每个结点的值都相同

#include<stdio.h>
#include<stdbool.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isUnivalTree(struct TreeNode* root){
	//空树符合题意
	if (root == NULL){
		return true;
	}

	//左子树的值不等于根
	if (root->left && root->left->val != root->val){
		return false;
	}

	//右子树的值不等于根
	if (root->right && root->right->val != root->val){
		return false;
	}

	//递归 左子树和右子树
	return isUnivalTree(root->left) && isUnivalTree(root->right);
}