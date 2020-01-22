//N叉树的最大深度
#include<iostream>

class Solution {
public:
	int maxDepth(Node* root) {
		if (!root) return 0;
		int m = 0;
		for (Node* it : root->children)
			m = max(m, maxDepth(it));
		return ++m;
	}
};