//二叉树的最大深度
#include<stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int maxDepth(struct TreeNode* root){
	//定义左右最大深度
	int Highleft, Highright;

	if (root == NULL){
		return 0;
	}

	else {
		//递归计算左右最大深度
		Highleft = maxDepth(root->left);
		Highright = maxDepth(root->right);

		//返回左右较大值
		return Highleft >Highright ? Highleft + 1 : Highright + 1;
	}
}