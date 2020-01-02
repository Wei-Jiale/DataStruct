#include<queue>
//定义二叉树结点
typedef struct Node{
	char value;
	struct Node *left;
	struct Node *right;
}	Node;
//判断完全二叉树
//对于深度为K的，有n个结点的二叉树，当且仅当其每一个结点都与深度为K的满二叉树中编号从1至n的结点一一对应时称之为完全二叉树。
bool IsComplete(Node *root){
	if (root == NULL){
		return true;
	}
	//定义一个队列
	std::queue<Node*> q;
	q.push(root);
	//层序遍历二叉树
	while (true)
	{
		Node *front = q.front();
		q.pop();
		if (front == NULL){
			break;
		}

		q.push(front->left);
		q.push(front->right);
	}
	//判断队列剩余元素是否全为空
	while (!q.empty()){
		Node *front = q.front();
		q.pop();
		if (front != NULL){
			return false;
		}
	}
	return true;

}