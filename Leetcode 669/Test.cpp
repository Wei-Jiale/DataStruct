#include<iostream>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* trimBST(TreeNode* root, int L, int R) {
		if (!root) return nullptr;
		//剪枝分三种情况 0 [1,2, 3,] 2 [1,2,3] 4 [1,2,3]
		// 0 [1,2,3] ,左枝都不要了 root不要了，root=右枝
		if (root->val < L) {
			root->left = nullptr;
			root = trimBST(root->right, L, R);
			return root;
		}
		// 2 [1,2,3];
		if (root->val >= L && root->val <= R) {
			root->left = trimBST(root->left, L, R);
			root->right = trimBST(root->right, L, R);
			return root;
		}
		// 4 [1,2,3];
		if (root->val > R) {
			root->right = nullptr;
			root = trimBST(root->left, L, R);
			return root;
		}

		return root;
	}
};