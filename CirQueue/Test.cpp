#include<iostream>
class MyCircularQueue {
public:
	int *array;//����ռ�ָ��
	int capacity;//����
	int size;//ʵ�����ݸ���
	int front;//��ǰ���������±�
	int vear;//��ǰ��β����λ���±�
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
			//���¶�β����λ���±�
			vear = (vear + 1) % capacity;
			//����ʵ�����ݸ���
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
			//���¶��������±�
			front = (front + 1) % capacity;
			//����ʵ�����ݸ���
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
			//��vear=0ʱ ȡ��βԪ��
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