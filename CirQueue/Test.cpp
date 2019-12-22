#include<iostream>
class MyCircularQueue {
public:
	int *array;//保存空间指针
	int capacity;//容量
	int size;//实际数据个数
	int front;//当前队首数据下标
	int vear;//当前队尾可用位置下标
	/** Initialize your data structure here. Set the size of the queue to be k. */
	MyCircularQueue(int k) {
		array = (int*)malloc(sizeof(int)*k);
		capacity = k;
		size = 0;
		front = 0;
		vear = 0;
	}

	/** Insert an element into the circular queue. Return true if the operation is successful. */
	bool enQueue(int value) {
		if (size == capacity){
			return false;
		}
		else{
			array[vear] = value;
			//更新队尾可用位置下标
			vear = (vear + 1) % capacity;
			//更新实际数据个数
			size++;
			return true;
		}
	}

	/** Delete an element from the circular queue. Return true if the operation is successful. */
	bool deQueue() {
		if (size == 0){
			return false;
		}
		else{
			//更新队首数据下标
			front = (front + 1) % capacity;
			//更新实际数据个数
			size--;
			return true;
		}
	}

	/** Get the front item from the queue. */
	int Front() {
		if (size == 0){
			return -1;
		}
		else{
			return array[front];
		}
	}

	/** Get the last item from the queue. */
	int Rear() {
		if (size == 0){
			return -1;
		}
		else{
			//当vear=0时 取队尾元素
			int index = (vear - 1 + capacity) % capacity;
			return array[index];
		}
	}

	/** Checks whether the circular queue is empty or not. */
	bool isEmpty() {
		return size == 0;
	}

	/** Checks whether the circular queue is full or not. */
	bool isFull() {
		return size == capacity;
	}
};