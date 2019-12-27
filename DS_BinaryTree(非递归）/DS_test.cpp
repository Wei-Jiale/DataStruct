#include<stack>
//������������
//�ݹ飺�׶���д
//�ǵݹ飺�ܸ���ϸ�Ŀ���

typedef struct Node{
	char value;
	struct Node *left;
	struct Node *right;
}	Node;

//ǰ�����
void Preorder(Node *root){
	std::stack<Node*> s;
	Node *cur = root;

	while (!s.empty()||cur!=NULL){
		while (cur != NULL){
			printf("%c", cur->value);
			s.push(cur);
			cur = cur->left;
		}

		Node *top = s.top();
		s.pop();

		cur = top->right;
	}
}

//�������
void Inorder(Node *root){
	std::stack<Node*> s;
	Node *cur = root;

	while (!s.empty() || cur != NULL){
		while (cur != NULL){
			s.push(cur);
			cur = cur->left;
		}

		Node *top = s.top();
		s.pop();
		printf("%c", top->value);

		cur = top->right;
	}
}

//�������
//���������� ����������
//��ô���������������ػ�������������
void Postorder(Node *root){
	std::stack<Node*> s;
	Node *cur = root;
	Node *last = NULL;//��һ����������������������ĸ����

	while (!s.empty() || cur != NULL){
		while (cur != NULL){
			s.push(cur);
			cur = cur->left;
		}

		Node *top = s.top();
		if (top->right == NULL){
			printf("%c", top->value);
			s.pop();
			last = top;
		}
		else if(top->right == last){
			printf("%c", top->value);
			s.pop();
			last = top;
		}
		else{
			cur = top->right;
		}
	}
}