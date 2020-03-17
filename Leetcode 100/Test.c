//相同的树
//结构相同并且对应结点的值相同
//在两棵树的层面解题

#include<stdio.h>
#include<stdbool.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

bool IsSameTree(struct TreeNode* p, struct TreeNode* q){
	//空树符合题意
	if (p == NULL && q == NULL){
		return true;
	}

	//有一个为空不符合题意
	if (p == NULL || q == NULL){
		return false;
	}

	return (p->val == q->val) && IsSameTree(p->left, q->left) && IsSameTree(p->right, q->right);
}