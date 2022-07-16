#include <iostream>
#include <algorithm>
using namespace std;

template <class T>
struct tree_node {
	T _key;
	int _height;
	tree_node<T>* _left;
	tree_node<T>* _right;
	tree_node(T k) { _key = k; _left = _right = 0; _height = 1; }
};

template <class T>
class bin_tree {
public:

	int height_tree() { return _root->_height; }

	int height(tree_node<T>* p){ return p ? p->_height : 0; }

	tree_node<T>* insert(T k) { insert(_root, k);  }

	int bfactor(tree_node<T>* p){return height(p->_right) - height(p->_left); }

	void print() { print(_root, 3); }

private:
	tree_node<T>* _root = nullptr;

	tree_node<T>* insert(tree_node<T>* p, T k){
		if (!p) {
			p = tree_node<T>*(k, 0, 0, 1);
			_root = p;
			return 0;
		}
		if (k < p->_key)
			p->_left = insert(p->_left, k);
		else
			p->_right = insert(p->_right, k);
		return balance(p);
	}

	tree_node<T>* rotateright(tree_node<T>* p) {
		tree_node* q = p->_left;
		p->_left = q->_right;
		q->_right = p;
		fixheight(p);
		fixheight(q);
		return q;
	}

	tree_node<T>* rotateleft(tree_node<T>* q) {
		tree_node* p = q->_right;
		q->_right = p->_left;
		p->_left = q;
		fixheight(q);
		fixheight(p);
		return p;
	}

	tree_node<T>* balance(tree_node<T>* p) {
		fixheight(p);
		if (bfactor(p) == 2) {
			if (bfactor(p->_right) < 0)
				p->_right = rotateright(p->_right);
			return rotateleft(p);
		}
		if (bfactor(p) == -2) {
			if (bfactor(p->_left) > 0)
				p->_left = rotateleft(p->_left);
			return rotateright(p);
		}
		return p; // балансировка не нужна
	}

	void fixheight(tree_node<T>* p) {
		int hl = height(p->_left);
		int hr = height(p->_right);
		p->_height = (hl > hr ? hl : hr) + 1;
	}

	void print(tree_node<T>* pos, int space) {
		if (pos == nullptr)
			return;
		print(pos->_left, space + 1);
		for (int i = 0; i < space; i++)
			cout << " ";
		cout << pos->_key << '\n';
		print(pos->_right, space + 1);
	}
};

int main() {
	bin_tree<int> tree;
	tree.insert(5);
	tree.insert(3);
	tree.insert(14);
	tree.insert(1);
	tree.insert(4);
	tree.insert(18);
	tree.print();
	return 0;
}

