//�����������е�����
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
		//��㲻����
		if (!root) return nullptr;
		//����ֵ == val
		if (root->val == val) return root;
		//����ֵ < val ��������������
		else if (root->val < val) return searchBST(root->right, val);
		//����ֵ > val ��������������
		else return searchBST(root->left, val);
	}
};