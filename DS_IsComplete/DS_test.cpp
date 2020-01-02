#include<queue>
//������������
typedef struct Node{
	char value;
	struct Node *left;
	struct Node *right;
}	Node;
//�ж���ȫ������
//�������ΪK�ģ���n�����Ķ����������ҽ�����ÿһ����㶼�����ΪK�����������б�Ŵ�1��n�Ľ��һһ��Ӧʱ��֮Ϊ��ȫ��������
bool IsComplete(Node *root){
	if (root == NULL){
		return true;
	}
	//����һ������
	std::queue<Node*> q;
	q.push(root);
	//�������������
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
	//�ж϶���ʣ��Ԫ���Ƿ�ȫΪ��
	while (!q.empty()){
		Node *front = q.front();
		q.pop();
		if (front != NULL){
			return false;
		}
	}
	return true;

}