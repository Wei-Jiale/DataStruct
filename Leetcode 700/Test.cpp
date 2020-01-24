//二叉搜索树中的搜索
#include<iostream>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* searchBST(TreeNode* root, int val) {
		//结点不存在
		if (!root) return nullptr;
		//根的值 == val
		if (root->val == val) return root;
		//根的值 < val 返回右子树查找
		else if (root->val < val) return searchBST(root->right, val);
		//根的值 > val 返回左子树查找
		else return searchBST(root->left, val);
	}
};