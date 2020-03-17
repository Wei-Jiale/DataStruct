//����ԳƵĶ�����
#include<stdio.h>
#include<stdbool.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

bool isMirror(struct TreeNode *p, struct TreeNode *q){
	//�������Ĳ���
	if (p == NULL&& q == NULL){
		return true;
	}

	if (p == NULL || q == NULL){
		return false;
	}

	//ֵ��Ȳ��Ҿ���Գ�
	return (p->val == q->val) && isMirror(p->left, q->right) && isMirror(p->right, q->left);
}

bool isSymmetric(struct TreeNode* root){
	//������������
	if (root == NULL){
		return true;
	}

	//�ݹ������������
	return isMirror(root->left, root->right);
}

