//×óÒ¶×ÓÖ®ºÍ
#include<iostream>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int sumOfLeftLeaves(TreeNode* root) {
		if (root == NULL) return 0;
		if (root->left != NULL&&root->left->right == NULL&&root->left->left == NULL){
			return sumOfLeftLeaves(root->right) + root->left->val;
		}
		return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
	}
};