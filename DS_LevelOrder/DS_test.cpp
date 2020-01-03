#include<queue>
//������������
typedef struct Node{
	char value;
	struct Node *left;
	struct Node *right;
}	Node;

//�������
void LevelOrder(Node* root){
	if (root == NULL){
		printf("\n");
	}
	std::queue<Node*> q;
	//����
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