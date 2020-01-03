#include<queue>
//定义二叉树结点
typedef struct Node{
	char value;
	struct Node *left;
	struct Node *right;
}	Node;

//层序遍历
void LevelOrder(Node* root){
	if (root == NULL){
		printf("\n");
	}
	std::queue<Node*> q;
	//启动
	q.push(root);

	while (!q.empty())
	{
		Node* front = q.front();
		q.pop();

		printf("%c", front->value);

		if (front->left != NULL){
			q.push(front->left);
		}
		if (front->right != NULL){
			q.push(front->right);
		}
	}
	printf("\n");
}