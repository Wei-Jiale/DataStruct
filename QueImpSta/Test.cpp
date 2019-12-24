#include<iostream>
#include<queue>
class MyStack {
public:
	queue<int> q;
	/** Initialize your data structure here. */
	MyStack() {

	}

	/** Push element x onto stack. */
	void push(int x) {
		//ѹջû��������
		q.push(x);
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		//��ջ���ȵ�Ų��size-1����
		int size = q.size();
		for (int i = 0; i<size - 1; i++){
			//�ó�����Ԫ��
			int v = q.front();
			//ɾ��
			q.pop();
			//�ٴӺ�������
			q.push(v);
		}
		int v = q.front();
		q.pop();
		return v;
	}


	/** Get the top element. */
	int top() {
		//��ջ���ȵ�Ų��size-1����
		int size = q.size();
		for (int i = 0; i<size - 1; i++){
			//�ó�����Ԫ��
			int v = q.front();
			//ɾ��
			q.pop();
			//�ٴӺ�������
			q.push(v);
		}
		int v = q.front();
		q.pop();
		q.push(v);

		return v;
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		//����Ϊ�� ջ��Ϊ��
		return q.empty();
	}
};