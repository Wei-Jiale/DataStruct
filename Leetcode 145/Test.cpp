//�������ĺ������
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	//�ݹ�
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> v;
		postorder(root, v);
		return v;
	}

	void postorder(TreeNode* root, vector<int>& v) {
		if (root == nullptr)
			return;
		postorder(root->left, v);
		postorder(root->right, v);
		v.push_back(root->val);
	}
};