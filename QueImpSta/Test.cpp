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
		//压栈没有特殊性
		q.push(x);
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		//出栈首先得挪动size-1个数
		int size = q.size();
		for (int i = 0; i<size - 1; i++){
			//拿出队首元素
			int v = q.front();
			//删除
			q.pop();
			//再从后进入队列
			q.push(v);
		}
		int v = q.front();
		q.pop();
		return v;
	}


	/** Get the top element. */
	int top() {
		//出栈首先得挪动size-1个数
		int size = q.size();
		for (int i = 0; i<size - 1; i++){
			//拿出队首元素
			int v = q.front();
			//删除
			q.pop();
			//再从后进入队列
			q.push(v);
		}
		int v = q.front();
		q.pop();
		q.push(v);

		return v;
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		//队列为空 栈就为空
		return q.empty();
	}
};