//��������ǰ�����
#include<stdio.h>
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

//����ȫ�ֱ���
int *array;
int size;

void Preorder(struct TreeNode* root){
	if (root != NULL){
		//ǰ�����
		//˳����β��
		array[size++] = root->val;
		Preorder(root->left);
		Preorder(root->right);
	}
}

int* preorderTraversal(struct TreeNode* root, int* returnSize){
	//��������
	array = (int*)malloc(sizeof(int)* 100 * 1000);
	size = 0;

	//ǰ�����
	Preorder(root);

	*returnSize = size;

	return array;

}