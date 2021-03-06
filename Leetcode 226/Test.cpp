//�ݹ鷴ת������
#include<iostream>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

	TreeNode* invertTree(TreeNode* root) {
		invert(root);
		return root;

	}

	void invert(TreeNode* root){
		if (root == NULL) return;

		TreeNode* temp = root->left;
		root->left = root->right;
		root->right = temp;

		invert(root->left);
		invert(root->right);
	}
};