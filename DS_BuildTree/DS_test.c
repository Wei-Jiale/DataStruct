#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
//������������
typedef struct Node{
	char value;
	struct Node *left;
	struct Node *right;
}	Node;

//ǰ��+���� ��ԭ������(��㲻�����ظ���
int find(char array[], int size, char v){
	for (int i = 0; i < size; i++){
		if (array[i] == v){
			return i;
		}
	}
	return -1;
}
Node* BuildTree(char preorder[], char inorder[], int size){
	if (size == 0){
		return NULL;
	}

	char rootValue = preorder[0];
	int leftSize = find(inorder, size, rootValue);
	assert(leftSize != -1);

	//��
	Node* root = (Node*)malloc(sizeof(Node));
	root->value = rootValue;

	//������(�����ҵ������е�λ���±꣩
	root->left = BuildTree(preorder + 1, inorder, leftSize);
	//������
	root->right = BuildTree(preorder + 1 + leftSize, inorder + 1 + leftSize, size - 1 - leftSize);

	return root;
}