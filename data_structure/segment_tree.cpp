#include <iostream>
#include <vector>
using namespace std;

struct SegmentTreeNode {
	SegmentTreeNode *left, *right;
	int L, R;
	int value, tag;

	SegmentTreeNode() {
		left = right = NULL;
		L = R = -1;
		value = 0;
        tag = 0;
	}

    void pull() {
        value = left->value + right->value;
    }

    void push() {
        if (!tag) return;
        int M = (L + R) / 2;
        if (left) {
            left->tag += tag;
            left->value += tag * (M - L);
        }
        if (right) {
            right->tag += tag;
            right->value += tag * (R - M);
        }
        tag = 0;
    }
};

struct SegmentTree {
	vector<int> array;
	SegmentTreeNode* root;

	SegmentTree() {
		root = new SegmentTreeNode();
	}

	void destroy() {
		_destroy(root);
	}

	void _destroy(SegmentTreeNode* node) {
		if (!node)
			return;
		_destroy(node->left);
		_destroy(node->right);
		delete node;
	}

	void build() {
		_build(0, array.size(), root);
	}

	int query(int x, int y) {
		return _query(x, y, root);
	}

    void modify(int x, int y, int d) {
        _modify(x, y, d, root);
    }

	void _build(int L, int R, SegmentTreeNode* node) {
		node->L = L;
		node->R = R;

		if (L+1 == R) {
			node->value = array[L];
			return;
		}

		int M = (L + R) / 2;

		if (!node->left) node->left = new SegmentTreeNode();
		if (!node->right) node->right = new SegmentTreeNode();

		_build(L, M, node->left);
		_build(M, R, node->right);

		node->pull();
	}

	int _query(int x, int y, SegmentTreeNode* node) {
		if (!node)
			return 0;
		if (y <= node->L || node->R <= x)
			return 0;
		if (x <= node->L && node->R <= y)
			return node->value;

        node->push();

		int a = _query(x, y, node->left);
		int b = _query(x, y, node->right);

		return a + b;
	}

    void _modify(int x, int y, int d, SegmentTreeNode* node) {
        if (!node)
            return;
		if (y <= node->L || node->R <= x)
            return;
		if (x <= node->L && node->R <= y) {
            node->tag += d;
            node->value += d * (node->R - node->L);
			return;
        }
        node->push();
        _modify(x, y, d, node->left);
        _modify(x, y, d, node->right);
        node->pull();
    }
};

