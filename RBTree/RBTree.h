#pragma once

enum Colour{
	BLACK,
	RED,
};

template<class K,class V>
struct RBTreeNode{
	RBTreeNode<K, V>* _left;
	RBTreeNode<K, V>* _right;
	RBTreeNode<K, V>* _parent;

	pair<K, V> _kv;

	Colour _col;

	RBTreeNode(const pair<K, V>& kv)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _kv(kv)
		, _col(RED)
	{}
};

template<class K,class V>
class RBTree{
	typedef RBTreeNode<K, V> Node;
public:
	bool Insert(const pair<K, V>& kv){
		// 1. �������������Ĺ�����в���
		if (_root == nullptr){
			_root = new Node(kv);
			_root->_col = BLACK;
			return true;
		}
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur){
			if (cur->_kv.first < kv.first){
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first > kv.first){
				parent = cur;
				cur = cur->_left;
			}
			else{
				return false;
			}
		}

		// �ҵ������λ��
		cur = new Node(kv);
		if (parent->_kv.first < kv.first){
			parent->_right = cur;
			cur->_parent = parent;
		}
		else{
			parent->_left = cur;
			cur->_parent = parent;
		}

		// ��������ʿ���
		// ������Ĭ�Ϻ�ɫ����Ĭ�Ϻ�ɫ����ÿ��·������Ӱ�죬����ɫ���Ӱ��һ��·����
		cur->_col = RED;

		while (parent && parent->_col == RED){
			// ����������ص�������
			Node* grandfather = parent->_parent;
			if (grandfather->_left == parent){
				// ��������
				Node* uncle = grandfather->_right;
				if (uncle && uncle->_col == RED){
					// 1. curΪ�� parentΪ�� grandfatherΪ�� u������Ϊ�죨��ɫ����
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;
					// ���ϴ���
					cur = grandfather;
					parent = cur->_parent;
				}
				else{
					// curΪ�� parentΪ�� grandfatherΪ�� u�����ڻ�uΪ�ڣ���ɫ+����˫������
					if (cur == parent->_right){
						// ������
						RotateL(parent);
						// ����תΪ�ڶ������
						swap(parent, cur);
					}
					// curΪ�� parentΪ�� grandfatherΪ�� u�����ڻ�uΪ�ڣ���ɫ+ֱ�ߵ�������
					RotateR(grandfather);
					grandfather->_col = RED;
					parent->_col = BLACK;

					break;
				}
			}
			else{
				Node* uncle = grandfather->_left;
				if (uncle && uncle->_col == RED){
					// 1. curΪ�� parentΪ�� grandfatherΪ�� u������Ϊ�죨��ɫ����
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;
					// ���ϴ���
					cur = grandfather;
					parent = cur->_parent;
				}
				else{
					if (cur == parent->_left){
						// ˫��ת����
						RotateR(parent);
						swap(parent, cur);
					}
					RotateL(grandfather);
					grandfather->_col = RED;
					parent->_col = BLACK;

					break;
				}
			}
		}
		_root->_col = BLACK;
		return true;
	}

	// ����
	void RotateL(Node* parent){
		Node* SubR = parent->_right;
		Node* SubRL = SubR->_left;
		parent->_right = SubRL; // subR���� ��ֵ�� parent����
		if (SubRL != nullptr){
			SubRL->_parent = parent;
		}
		SubR->_left = parent; // parent ��ֵ�� subR����
		Node* ppNode = parent->_parent;
		parent->_parent = SubR;

		// 1.ԭ��parent�����ĸ������ڱ�ΪSubR
		if (parent == _root){
			_root = SubR;
			SubR->_parent = nullptr;
		}
		// 2.ԭ��parent�������ĸ�
		else{
			if (ppNode->_left == parent){
				ppNode->_left = SubR;
			}
			else{
				ppNode->_right = SubR;
			}
			SubR->_parent = ppNode;
		}
	}

	// �ҵ���
	void RotateR(Node* parent){
		Node* SubL = parent->_left;
		Node* SubLR = SubL->_right;

		parent->_left = SubLR;
		if (SubLR != nullptr){
			SubLR->_parent = parent;
		}
		SubL->_right = parent;
		Node* ppNode = parent->_parent;
		parent->_parent = SubL;

		if (parent == _root){
			_root = SubL;
			SubL->_parent = nullptr;
		}
		else{
			if (ppNode->_left == parent){
				ppNode->_left = SubL;
			}
			else{
				ppNode->_right = SubL;
			}
			SubL->_parent = ppNode;
		}
	}

private:
	Node* _root = nullptr;
};