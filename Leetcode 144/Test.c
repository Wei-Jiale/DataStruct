//二叉树的前序遍历
#include<stdio.h>
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

//定义全局变量
int *array;
int size;

void Preorder(struct TreeNode* root){
	if (root != NULL){
		//前序遍历
		//顺序表的尾插
		array[size++] = root->val;
		Preorder(root->left);
		Preorder(root->right);
	}
}

int* preorderTraversal(struct TreeNode* root, int* returnSize){
	//开辟数组
	array = (int*)malloc(sizeof(int)* 100 * 1000);
	size = 0;

	//前序遍历
	Preorder(root);

	*returnSize = size;

	return array;

}