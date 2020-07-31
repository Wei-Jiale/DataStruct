template<class T, class Ptr, class Ref>
class __RBTreeIterator
{
public:
	typedef RBTreeNode<T> Node;
	typedef __RBTreeIterator<T, Ptr, Ref> Self;

	__RBTreeIterator(Node* node) : _node(node)
	{}

	Ref operator *()
	{
		return _node->_data;
	}

	//调用时其实调用的是->->，这里返回的是数据对象的指针，然后再从指针中取数据。编译器优化所以只看到一个
	Ptr operator ->()
	{
		return &_node->_data;
	}

	//红黑树迭代器的++ --其实就是其在中序遍历中的次序变化
	Self& operator++()
	{
		/*
		中序遍历：先访问所有节点的左子树，接着访问这些节点的右子树。
		而++，其实就是其在中序遍历的下一个位置
		1.如果当前节点的右子树不为空，则说明当前节点的右子树还没遍历完，下一个位置则是右子树的最左节点。

		2.如果此时右子树为空，则说明当前节点的所有子树访问完，但是当前节点也可能为其他树的右子树，所以一直往上，找到孩子为父亲的左子树的结点，那个父亲的位置则是下一个位置
		*/
		if (_node->_right)
		{
			Node* cur = _node->_right;

			//找到右子树的最左节点
			while (cur->_left)
			{
				cur = cur->_left;
			}

			_node = cur;
		}
		else
		{
			Node* parent = _node->_parent;
			Node* cur = _node;

			//往上找，直到父节点为空或者孩子节点为父节点的左子树
			while (parent->_right == cur)
			{
				cur = parent;
				parent = parent->_parent;
			}

			_node = parent;
		}

		return *this;
	}

	Self operator++(int)
	{
		Self temp(*this);
		++(*this);

		return temp;
	}
	/*
	而--，其实就是其在中序遍历的上一个位置，思路和++差不多
	1.如果当前节点的左子树不为空，则访问左子树的最右节点
	2.如果此时左子树为空，则说明子树的最左节点已经访问，接着就往上查找，找到孩子为父亲的右节点的位置，那个父亲就是下一个位置
	*/
	Self& operator--()
	{
		if (_node->_parent->_parent == _node && _node->_color == RED)
		{
			//如果此节点为头结点，则说明--应该回到最右子树的位置，也就是头结点的右子树，而因为头结点和根节点形成闭环，所以当
			//_node->_parent->_parent == _node，并且color为红时，说明为_head。

			_node = _node->_right;
		}
		else if (_node->_left)
		{
			Node* cur = _node->_left;

			//找到左子树的最右节点
			while (cur && cur->_right)
			{
				cur = cur->_right;
			}

			_node = cur;
		}
		else
		{
			Node* parent = _node->_parent;
			Node* cur = _node;

			//往上找，直到父节点为空或者孩子节点为父节点的右子树
			while (parent->_right != cur)
			{
				cur = parent;
				parent = parent->_parent;
			}

			_node = parent;
		}
		return *this;
	}

	Self operator--(int)
	{
		Self temp(*this);
		--(*this);

		return temp;
	}
	bool operator==(const Self& s)
	{
		return _node == s._node;
	}

	bool operator!=(const Self& s)
	{
		return _node != s._node;
	}

private:
	Node* _node;
};