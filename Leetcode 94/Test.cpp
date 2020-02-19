//二叉树的中序遍历
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<int> vec;
	vector<int> inorderTraversal(TreeNode* root) {
		if (root){
			if (root->left){
				inorderTraversal(root->left);
			}
			vec.push_back(root->val);
			if (root->right){
				inorderTraversal(root->right);
			}
		}
		return vec;
	}
};