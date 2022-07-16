#include <iostream>
using namespace std;

template <class T>
struct bin_tree_node {
	T value;
	bin_tree_node<T>* left = nullptr;
	bin_tree_node<T>* right = nullptr;
	bin_tree_node<T>* parent = nullptr;
	bin_tree_node(T val = T()) :value(val) {};
};

template <class T>
struct bin_tree {
	bin_tree_node<T>* root = nullptr;
	void add_node(T val, bin_tree_node<T>* pos) {
		if (pos == nullptr) {
			pos = new bin_tree_node<T>(val);
			root = pos;
			return;
		}
		if (pos->value == val)
			return;
		if (pos->value < val) {
			if (pos->right == nullptr) {
				pos->right = new bin_tree_node<T>(val);
				pos->right->parent = pos;
			}
			else
				add_node(val, pos->right);
		}
		if (pos->value > val) {
			if (pos->left == nullptr) {
				pos->left = new bin_tree_node<T>(val);
				pos->left->parent = pos;
			}
			else
				add_node(val, pos->left);
		}
	}

	void add_node(T val) {
		add_node(val, root);
	}

	void print(bin_tree_node<T>* pos, int level) {
		if (pos == 0) return;
		print(pos->right, level + 1);
		for (int i = 0; i < level; i++) cout << ' ';
		cout << pos->value << '\n';
		print(pos->left, level + 1);
	}

	void checker(bin_tree_node<T>* pos, int& flag) {
		if (pos == 0) return;
		checker(pos->right, flag);
		flag++;
		if (flag == 2) {
			cout << pos->value << '\n';
			flag ++;
		}
		checker(pos->left, flag);
	}

};

int main() {
	bin_tree<int> my_tree;
	int num, max = 0;
	cin >> num;
	while (num != 0) {
		my_tree.add_node(num, my_tree.root);
		cin >> num;
	}
	my_tree.checker(my_tree.root, max);
	return 0;
}
