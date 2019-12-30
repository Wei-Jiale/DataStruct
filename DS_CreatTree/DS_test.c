#include<stdio.h>
#include<stdlib.h>
//������������
typedef struct Node{
	char value;
	struct Node *left;
	struct Node *right;
}	Node;

//������
Node * CreatTree(char preorder[], int size, int *pUsed){
	if (size == 0){
		*pUsed = 0;
		return NULL;
	}
	if (preorder == '#'){
		*pUsed = 1;
		return NULL;
	}
	//��
	Node* root = (Node*)malloc(sizeof(Node));
	root->value = preorder[0];

	//������
	int LeftUsed;
	root->left = CreatTree(preorder + 1, size - 1, &LeftUsed);
	//������
	int RightUsed;
	root->right = CreatTree(preorder + 1 + LeftUsed, size - 1 - LeftUsed, &RightUsed);

	//������
	*pUsed = 1 + LeftUsed + RightUsed;
	return root;
}