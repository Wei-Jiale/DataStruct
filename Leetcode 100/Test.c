//��ͬ����
//�ṹ��ͬ���Ҷ�Ӧ����ֵ��ͬ
//���������Ĳ������

#include<stdio.h>
#include<stdbool.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

bool IsSameTree(struct TreeNode* p, struct TreeNode* q){
	//������������
	if (p == NULL && q == NULL){
		return true;
	}

	//��һ��Ϊ�ղ���������
	if (p == NULL || q == NULL){
		return false;
	}

	return (p->val == q->val) && IsSameTree(p->left, q->left) && IsSameTree(p->right, q->right);
}