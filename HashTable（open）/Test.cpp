#include<iostream>
#include<vector>
using namespace std;

// 结点结构体
template<class T>
struct Hash_Node{
	T _data;
	Hash_Node<T>* _next;
	Hash_Node(const T& data)
		:_data(data)
		, _next(nullptr)
	{}
};

template<class K,class T,class KeyOfT>
class Hash_Table{
	typedef Hash_Node<T> Node;
private:
	bool Insert(const T& data){
		// 计算关键码在vector中的位置
		KeyOfT koft;
		// 如果负载因子=1，则增容，避免大量的哈希冲突
		if (_tables.size() == _nums){
			vector<Node*> newtables;
			size_t newsize = _tables.size() == 0 ? 10 : _tables.size() * 2;
			newtables.resize(newsize);
			for (size_t i = 0; i < _tables.size(); i++){
				// 将旧表中的结点取下，计算在新表中的位置
				Node* cur = _tables[i];
				while (cur){
					Node* next = cur->_next;
					size_t index = koft(cur->_data) % newtables.size();
					cur->_next = newtables[index];
					newtables[index] = cur;
					cur = next;
				}
				_tables[i] = nullptr;
			}
			_tables.swap(newtables);

		}
		size_t index = koft(data) % _tables.size();
		// 寻找结点存在不存在
		Node* cur = _tables[index];
		while (cur){
			if (koft(cur->_data) == koft(data)){
				return false;
			}
			else{
				cur = cur->_next;
			}
		}

		// 头插
		Node* newnode = new Node(data);
		newnode->_next = _tables[index];
		_tables[index] = newnode;

		++_nums;
		return true;
	}

	Node* Find(const K& key){
		KeyOfT koft;
		size_t index = key % _tables.size();
		Node* cur = _tables[index];
		while (cur){
			if (koft(cur->_data) == key){
				return cur;
			}
			else{
				cur = cur->_next;
			}
		}
		return nullptr;
	}

	bool Erase(const K& key){
		// 计算key在表中位置再寻找桶
		KeyOfT koft;
		size_t index = key % _tables.size();
		Node* prev = nullptr;
		Node* cur = _tables[index];
		while (cur){
			// 单链表的删除就要找到被删除结点的前一个结点
			if (koft(cur->_data) == key){
				if (prev == nullptr){
					// 此时删除的是第一个结点
					_tables[index] = cur->_next;
				}
				else{
					prev->_next = cur->_next;
				}
				delete cur;
				return true;
			}
			else{
				prev = cur;
				cur = cur->_next;
			}
		}
		return false;
	}
	vector<Node*> _tables;// 数组中存放结点的指针
	size_t _nums = 0; // 记录表中存储数据的个数
};