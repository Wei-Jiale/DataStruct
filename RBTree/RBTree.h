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
		// 1. 按二叉搜索树的规则进行插入
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

		// 找到插入的位置
		cur = new Node(kv);
		if (parent->_kv.first < kv.first){
			parent->_right = cur;
			cur->_parent = parent;
		}
		else{
			parent->_left = cur;
			cur->_parent = parent;
		}

		// 红黑树性质控制
		// 插入结点默认红色（若默认黑色，则每条路径都会影响，而红色最多影响一条路径）
		cur->_col = RED;

		while (parent && parent->_col == RED){
			// 红黑树调整重点在叔叔
			Node* grandfather = parent->_parent;
			if (grandfather->_left == parent){
				// 叔叔在右
				Node* uncle = grandfather->_right;
				if (uncle && uncle->_col == RED){
					// 1. cur为红 parent为红 grandfather为黑 u存在且为红（变色处理）
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;
					// 向上处理
					cur = grandfather;
					parent = cur->_parent;
				}
				else{
					// cur为红 parent为红 grandfather为黑 u不存在或u为黑（变色+折线双旋处理）
					if (cur == parent->_right){
						// 先左单旋
						RotateL(parent);
						// 交换转为第二种情况
						swap(parent, cur);
					}
					// cur为红 parent为红 grandfather为黑 u不存在或u为黑（变色+直线单旋处理）
					RotateR(grandfather);
					grandfather->_col = RED;
					parent->_col = BLACK;

					break;
				}
			}
			else{
				Node* uncle = grandfather->_left;
				if (uncle && uncle->_col == RED){
					// 1. cur为红 parent为红 grandfather为黑 u存在且为红（变色处理）
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;
					// 向上处理
					cur = grandfather;
					parent = cur->_parent;
				}
				else{
					if (cur == parent->_left){
						// 双旋转单旋
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

	// 左单旋
	void RotateL(Node* parent){
		Node* SubR = parent->_right;
		Node* SubRL = SubR->_left;
		parent->_right = SubRL; // subR的左 赋值给 parent的右
		if (SubRL != nullptr){
			SubRL->_parent = parent;
		}
		SubR->_left = parent; // parent 赋值给 subR的左
		Node* ppNode = parent->_parent;
		parent->_parent = SubR;

		// 1.原来parent是树的根，现在变为SubR
		if (parent == _root){
			_root = SubR;
			SubR->_parent = nullptr;
		}
		// 2.原来parent不是树的根
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

	// 右单旋
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