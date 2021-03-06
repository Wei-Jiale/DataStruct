#pragma once
template<class K,class V>
struct BSTreeNode{
	BSTreeNode<K,V>* _left;
	BSTreeNode<K,V>* _right;
	K _key;
	V _value;

	BSTreeNode(const K& key, const V& value)
		:_left(nullptr)
		, _right(nullptr)
		, _key(key)
		, _value(value)
	{}
};

template<class K, class V>
class BSTree{
	typedef BSTreeNode<K, V> Node;
public:
	bool Insert(const K& key, const V& value){
		if (_root == nullptr){
			_root = new Node(key,value);
			return true;
		}
		// parent起到连接新结点的作用
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur){
			if (cur->_key < key){
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key > key){
				parent = cur;
				cur = cur->_left;
			}
			else{
				return false;
			}
		}
		cur = new Node(key,value);
		// 连接
		if (parent->_key < key){
			parent->_right = cur;
		}
		else{
			parent->_left = cur;
		}
		return true;
	}

	Node* Find(const K& key){
		Node* cur = _root;
		while (cur){
			if (cur->_key < key){
				cur = cur->_right;
			}
			else if (cur->_key > key){
				cur = cur->_left;
			}
			else{
				return cur;
			}
		}
		return nullptr;
	}

	// 删除的结点存在左右孩子
	// 则找左子树的最右结点或右子树的最左结点进行替代
	bool Erase(const K& key){
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur){
			if (cur->_key < key){
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key > key){
				parent = cur;
				cur = cur->_left;
			}
			else{
				// 找到了需要删除的结点
				// 需要判断cur是parent的左孩子还是右孩子
				if (cur->_left == nullptr){
					// 被删除的结点是根结点
					if (cur == _root){
						_root = cur->_right;
					}
					// 被删除的结点存在父结点
					else{
						if (parent->_right == cur){
							parent->_right = cur->_right;
						}
						else{
							parent->_left = cur->_right;
						}
					}
					delete cur;
				}
				else if (cur->_right == nullptr){
					if (cur == _root){
						_root = cur->_left;
					}
					else{
						if (parent->_right == cur){
							parent->_right = cur->_left;
						}
						else{
							parent->_left = cur->_left;
						}
					}
					delete cur;
				}
				else{
					// 替代
					Node* rightMinParent = cur;
					Node* rightMin = cur->_right;
					// 若while循环没有进入则Parent就会为nullptr
					// 初始化时Parent就为cur
					while (rightMin->_left){
						rightMinParent = rightMin;
						rightMin = rightMin->_left;
					}
					// 替代删除结点
					cur->_key = rightMin->_key;
					// 删除rightMin
					// 右子树的最左结点可能是父结点的右孩子
					if (rightMin == rightMinParent->_left){
						rightMinParent->_left = rightMin->_right;
					}
					else{
						rightMinParent->_right = rightMin->_right;
					}
					delete rightMin;
				}
				return true;
			}
		}
		return false;
	}

	void _Inorder(Node* root){
		if (root == nullptr){
			return;
		}
		_Inorder(root->_left);
		cout << root->_key << "：" << root->_value << endl;
		_Inorder(root->_right);
	}

	void Inorder(){
		_Inorder(_root);
		cout << endl;
	}
private:
	Node* _root = nullptr;
};

void TestBSTree(){
	BSTree<string, string> dict;
	dict.Insert("sort", "排序");
	dict.Insert("string", "字符串");
	dict.Insert("tree", "树");
	dict.Insert("insert", "插入");

	string str;
	//while (cin >> str){
	//	// 查找
	//	BSTreeNode<string, string>* ret = dict.Find(str);
	//	if (ret != nullptr){
	//		cout << ret->_value << endl;
	//	}
	//	else{
	//		cout << "未找到" << endl;
	//	}
	//}

	// 统计水果出现的次数
	string strArray[] = { "西瓜", "苹果", "樱桃", "西瓜", "樱桃" };
	BSTree<string, int> countTree;
	for (auto str : strArray){
		BSTreeNode<string, int>* ret = countTree.Find(str);
		if (ret == nullptr){
			countTree.Insert(str, 1);
		}
		else{
			ret->_value++;
		}
	}
	countTree.Inorder();
}