//单值二叉树
//二叉树每个结点都有相同的值
#include<iostream>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isUnivalTree(TreeNode* root) {
		return isVaild(root, root->val);
	}

	bool isVaild(TreeNode* root, int n)
	{
		if (!root)
			return true;
		if (root->val != n)
			return false;
		return isVaild(root->left, n) && isVaild(root->right, n);
	}
};