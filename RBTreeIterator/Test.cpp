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

	//����ʱ��ʵ���õ���->->�����ﷵ�ص������ݶ����ָ�룬Ȼ���ٴ�ָ����ȡ���ݡ��������Ż�����ֻ����һ��
	Ptr operator ->()
	{
		return &_node->_data;
	}

	//�������������++ --��ʵ����������������еĴ���仯
	Self& operator++()
	{
		/*
		����������ȷ������нڵ�������������ŷ�����Щ�ڵ����������
		��++����ʵ�������������������һ��λ��
		1.�����ǰ�ڵ����������Ϊ�գ���˵����ǰ�ڵ����������û�����꣬��һ��λ������������������ڵ㡣

		2.�����ʱ������Ϊ�գ���˵����ǰ�ڵ���������������꣬���ǵ�ǰ�ڵ�Ҳ����Ϊ��������������������һֱ���ϣ��ҵ�����Ϊ���׵��������Ľ�㣬�Ǹ����׵�λ��������һ��λ��
		*/
		if (_node->_right)
		{
			Node* cur = _node->_right;

			//�ҵ�������������ڵ�
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

			//�����ң�ֱ�����ڵ�Ϊ�ջ��ߺ��ӽڵ�Ϊ���ڵ��������
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
	��--����ʵ�������������������һ��λ�ã�˼·��++���
	1.�����ǰ�ڵ����������Ϊ�գ�����������������ҽڵ�
	2.�����ʱ������Ϊ�գ���˵������������ڵ��Ѿ����ʣ����ž����ϲ��ң��ҵ�����Ϊ���׵��ҽڵ��λ�ã��Ǹ����׾�����һ��λ��
	*/
	Self& operator--()
	{
		if (_node->_parent->_parent == _node && _node->_color == RED)
		{
			//����˽ڵ�Ϊͷ��㣬��˵��--Ӧ�ûص�����������λ�ã�Ҳ����ͷ����������������Ϊͷ���͸��ڵ��γɱջ������Ե�
			//_node->_parent->_parent == _node������colorΪ��ʱ��˵��Ϊ_head��

			_node = _node->_right;
		}
		else if (_node->_left)
		{
			Node* cur = _node->_left;

			//�ҵ������������ҽڵ�
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

			//�����ң�ֱ�����ڵ�Ϊ�ջ��ߺ��ӽڵ�Ϊ���ڵ��������
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