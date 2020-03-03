//��ֵ������
//������ÿ������ֵ����ͬ

#include<stdio.h>
#include<stdbool.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isUnivalTree(struct TreeNode* root){
	//������������
	if (root == NULL){
		return true;
	}

	//��������ֵ�����ڸ�
	if (root->left && root->left->val != root->val){
		return false;
	}

	//��������ֵ�����ڸ�
	if (root->right && root->right->val != root->val){
		return false;
	}

	//�ݹ� ��������������
	return isUnivalTree(root->left) && isUnivalTree(root->right);
}