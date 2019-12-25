#include<iostream>
#include<stack>
class MyQueue {
public:
	stack<int> in;
	stack<int> out;
	/** Initialize your data structure here. */
	MyQueue() {

	}

	/** Push element x to the back of queue. */
	void push(int x) {
		in.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		//如果out为空，把所有in的数据导入到out
		if (out.empty()){
			while (!in.empty()){
				int v = in.top();
				in.pop();
				out.push(v);
			}
		}
		int v = out.top();
		out.pop();
		return v;
	}

	/** Get the front element. */
	int peek() {
		//如果out为空，把所有in的数据导入到out
		if (out.empty()){
			while (!in.empty()){
				int v = in.top();
				in.pop();
				out.push(v);
			}
		}
		int v = out.top();
		return v;
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		//两个栈都为空则队列为空
		return in.empty() && out.empty();
	}
};