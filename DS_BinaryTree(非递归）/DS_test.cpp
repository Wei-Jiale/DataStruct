#include<stack>
//定义二叉树结点
//递归：易懂易写
//非递归：能更精细的控制

typedef struct Node{
	char value;
	struct Node *left;
	struct Node *right;
}	Node;

//前序遍历
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

//中序遍历
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

//后序遍历
//右子树回来 第三次遇到
//怎么区分是左子树返回还是右子树返回
void Postorder(Node *root){
	std::stack<Node*> s;
	Node *cur = root;
	Node *last = NULL;//上一个被完整后序遍历过的树的根结点

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