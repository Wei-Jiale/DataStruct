//��ȫ�������Ľ�����
#include<iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int countNodes(TreeNode* root) {
		return root == NULL ? 0 : 1 + countNodes(root->left) + countNodes(root->right);
	}
};