#include<iostream>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* removeLeafNodes(TreeNode* root, int target) {
		if (root == NULL) {
			return NULL;
		}
		root->left = removeLeafNodes(root->left, target);
		root->right = removeLeafNodes(root->right, target);
		if (root->left == NULL && root->right == NULL && root->val == target) {
			return NULL;
		}
		return root;
	}
};