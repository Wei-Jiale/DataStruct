//��ת������
//���������������Һ���
#include<stdio.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* invertTree(struct TreeNode* root){
	//��������0
	if (root == NULL){
		return NULL;
	}

	//ʵ�ֽ���
	struct TreeNode* temp = root->left;
	root->left = root->right;
	root->right = temp;

	//�ݹ�
	invertTree(root->left);
	invertTree(root->right);

	return root;
}