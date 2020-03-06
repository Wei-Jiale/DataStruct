//��������������
#include<stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int maxDepth(struct TreeNode* root){
	//��������������
	int Highleft, Highright;

	if (root == NULL){
		return 0;
	}

	else {
		//�ݹ��������������
		Highleft = maxDepth(root->left);
		Highright = maxDepth(root->right);

		//�������ҽϴ�ֵ
		return Highleft >Highright ? Highleft + 1 : Highright + 1;
	}
}