#include<iostream>
#include<vector>
using namespace std;

// ���ṹ��
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
		// ����ؼ�����vector�е�λ��
		KeyOfT koft;
		// �����������=1�������ݣ���������Ĺ�ϣ��ͻ
		if (_tables.size() == _nums){
			vector<Node*> newtables;
			size_t newsize = _tables.size() == 0 ? 10 : _tables.size() * 2;
			newtables.resize(newsize);
			for (size_t i = 0; i < _tables.size(); i++){
				// ���ɱ��еĽ��ȡ�£��������±��е�λ��
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
		// Ѱ�ҽ����ڲ�����
		Node* cur = _tables[index];
		while (cur){
			if (koft(cur->_data) == koft(data)){
				return false;
			}
			else{
				cur = cur->_next;
			}
		}

		// ͷ��
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
		// ����key�ڱ���λ����Ѱ��Ͱ
		KeyOfT koft;
		size_t index = key % _tables.size();
		Node* prev = nullptr;
		Node* cur = _tables[index];
		while (cur){
			// �������ɾ����Ҫ�ҵ���ɾ������ǰһ�����
			if (koft(cur->_data) == key){
				if (prev == nullptr){
					// ��ʱɾ�����ǵ�һ�����
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
	vector<Node*> _tables;// �����д�Ž���ָ��
	size_t _nums = 0; // ��¼���д洢���ݵĸ���
};